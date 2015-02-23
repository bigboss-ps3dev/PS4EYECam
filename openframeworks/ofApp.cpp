#include "ofApp.h"
#include "ofxOpenCv.h"

//--------------------------------------------------------------
void ofApp::setup(){
    using namespace ps4eye;

    camFrameCount = 0;
    camFpsLastSampleFrame = 0;
    camFpsLastSampleTime = 0;
    camFps = 0;

    // // list out the devices
    //  std::vector<PS3EYECam::PS3EYERef> devices( PS3EYECam::getDevices() );
    std::vector<PS4EYECam::PS4EYERef> devices( PS4EYECam::getDevices() );

    if(devices.size())
    {
        eye = devices.at(0);
       bool res = eye->init(1, 30);
       eye->start();

        frame_rgb_left = new uint8_t[eye->getWidth()*eye->getHeight()*3];
        frame_rgb_right = new uint8_t[eye->getWidth()*eye->getHeight()*3];
        memset(frame_rgb_left, 0, eye->getWidth()*eye->getHeight()*3);
        memset(frame_rgb_right, 0, eye->getWidth()*eye->getHeight()*3);


       videoFrame 	= new unsigned char[eye->getWidth()*eye->getHeight()*3];
       videoTextureLeft.allocate(eye->getWidth(), eye->getHeight(), GL_RGB);
       videoTextureRight.allocate(eye->getWidth(), eye->getHeight(), GL_RGB);


        threadUpdate.start();
    }


}
//from https://social.msdn.microsoft.com/forums/windowsdesktop/en-us/1071301e-74a2-4de4-be72-81c34604cde9/program-to-translate-yuyv-to-rgbrgb modified yuyv order
/*--------------------------------------------------------*\
 |    yuv2rgb                                               |
 \*--------------------------------------------------------*/
void yuv2rgb(int y, int u, int v, char *r, char *g, char *b)
{
    int r1, g1, b1;
    int c = y-16, d = u - 128, e = v - 128;

    r1 = (298 * c           + 409 * e + 128) >> 8;
    g1 = (298 * c - 100 * d - 208 * e + 128) >> 8;
    b1 = (298 * c + 516 * d           + 128) >> 8;

    // Even with proper conversion, some values still need clipping.

    if (r1 > 255) r1 = 255;
    if (g1 > 255) g1 = 255;
    if (b1 > 255) b1 = 255;
    if (r1 < 0) r1 = 0;
    if (g1 < 0) g1 = 0;
    if (b1 < 0) b1 = 0;

    *r = r1 ;
    *g = g1 ;
    *b = b1 ;
}

/*--------------------------------------------------------*\
 |    yuyvToRgb                                             |
 \*--------------------------------------------------------*/
void yuyvToRgb(uint8_t *in,uint8_t *out, int size_x,int size_y)
{
    int i;
    unsigned int *pixel_16=(unsigned int*)in;;     // for YUYV
    unsigned char *pixel_24=out;    // for RGB
    int y, u, v, y2;
    char r, g, b;


    for (i=0; i< (size_x*size_y/2) ; i++)
    {
        // read YuYv from newBuffer (2 pixels) and build RGBRGB in pBuffer

     //   v  = ((*pixel_16 & 0x000000ff));
       // y  = ((*pixel_16 & 0x0000ff00)>>8);
       // u  = ((*pixel_16 & 0x00ff0000)>>16);
       // y2 = ((*pixel_16 & 0xff000000)>>24);

        y2  = ((*pixel_16 & 0x000000ff));
        u  = ((*pixel_16 & 0x0000ff00)>>8);
        y  = ((*pixel_16 & 0x00ff0000)>>16);
        v = ((*pixel_16 & 0xff000000)>>24);

     yuv2rgb(y, u, v, &r, &g, &b);            // 1st pixel


        *pixel_24++ = r;
        *pixel_24++ = g;
        *pixel_24++ = b;



    yuv2rgb(y2, u, v, &r, &g, &b);            // 2nd pixel

        *pixel_24++ = r;
        *pixel_24++ = g;
        *pixel_24++ = b;



        pixel_16++;
    }
}
void convert_opencv_to_RGB(uint8_t *in,uint8_t *out, int size_x,int size_y)
{
    cv::Mat yuv(size_y,size_x,CV_8UC2 ,in);

    cv::Mat rgb(size_y,size_x,CV_8UC3, out);
    //ARRRRRRGGGGGGHHHHHHHH openframework has an veryyyyyyyyy old opencv lib you wiil need opencv 2.4.9 to use 115 ->>> CV_YUV2RGB_YUY2 
    cv::cvtColor(yuv, rgb, 115);
}
//--------------------------------------------------------------
void ofApp::update(){


    eyeframe *frame;
    if(eye)
    {
        bool isNewFrame = eye->isNewFrame();
        if(isNewFrame)
        {
            eye->check_ff71();
            frame=eye->getLastVideoFramePointer();


            yuyvToRgb(frame->videoRightFrame, frame_rgb_right, eye->getWidth(), eye->getHeight());
            videoTextureRight.loadData(frame_rgb_right, eye->getWidth(),eye->getHeight(), GL_RGB);

            yuyvToRgb(frame->videoLeftFrame, frame_rgb_left, eye->getWidth(), eye->getHeight());
            videoTextureLeft.loadData(frame_rgb_left, eye->getWidth(),eye->getHeight(), GL_RGB);


        }


        camFrameCount += isNewFrame ? 1: 0;
        float timeNow = ofGetElapsedTimeMillis();
        if( timeNow > camFpsLastSampleTime + 1000 ) {
            uint32_t framesPassed = camFrameCount - camFpsLastSampleFrame;
            camFps = (float)(framesPassed / ((timeNow - camFpsLastSampleTime)*0.001f));

            camFpsLastSampleTime = timeNow;
            camFpsLastSampleFrame = camFrameCount;
        }
    }
    


}

//--------------------------------------------------------------
void ofApp::draw(){

     ofSetHexColor(0xffffff);
    //uglyyyyy harcoded to mode 1 640x400
    //left
    videoTextureLeft.draw(0,0,eye->getWidth(),eye->getHeight());
    //right
    videoTextureRight.draw(640,0,eye->getWidth(),eye->getHeight());


    string str = "app fps: ";
    str += ofToString(ofGetFrameRate(), 2);
    str += "\neye fps: " + ofToString(camFps, 2);
    ofDrawBitmapString(str, 10, 15);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit(){
    threadUpdate.stop();
    // You should stop before exiting
    // otherwise the app will keep working
    if(eye)
    {
    cout << "Shutdown begin wait..." << std::endl;
    eye->shutdown();
    //
    delete[] frame_rgb_left;
    delete[] frame_rgb_right;

    }
}

