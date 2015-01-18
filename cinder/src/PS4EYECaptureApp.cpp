/*
 *	PlayStation 4 Camera Capture sample
 *	Copyright (C) 2013,2014 Antonio Jose Ramos Marquez (aka bigboss) @psxdev on twitter
 *
 *  Repository https://github.com/bigboss-ps3dev/PS4EYECam
 *  some parts are based on PS3EYECamera driver https://github.com/inspirit/PS3EYEDriver
 *  some parts were commited to ps4eye https://github.com/ps4eye/ps4eye
 *	
 *  This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public Licence as published by
 *	the Free Software Foundation; either version 2 of the Licence, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public Licence for more details.
 *
 *	You should have received a copy of the GNU General Public Licence
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Utilities.h"
#include "cinder/Thread.h"

#include "ciUI.h"
//opencv for future options
#include "CinderOpenCV.h"
#include "ps4eye.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class eyeFPS : public ciUIFPS
{
public:
    eyeFPS(float x, float y, int _size):ciUIFPS(x,y,_size)
    {
    }

    eyeFPS(int _size):ciUIFPS(_size)
    {
    }

    void update_fps(float fps)
    {
        setLabel("FPS: " + numToString(fps, labelPrecision));
    }
};
/* For future test with opencv
class ImageSourcePS4EyeDepth : public ImageSource{
public:
    ImageSourcePS4EyeDepth( uint16_t *buffer, int width,int height )
	: ImageSource(), mData( buffer )
    {
        setSize( width, height );
        setColorModel( ImageIo::CM_GRAY );
        setChannelOrder( ImageIo::Y );
        setDataType( ImageIo::UINT16 );
    }
    ~ImageSourcePS4EyeDepth()
    {

    }
    virtual void load( ImageTargetRef target )
    {
        ImageSource::RowFunc func = setupRowFunc( target );
        for( int32_t row = 0; row < 480; ++row )
            ((*this).*func)( target, row, mData + row * 640 );
    }
protected:
    uint16_t	*mData;
};*/
class PS4EYECaptureApp : public AppBasic {
public:
	void setup();
    void shutdown();
	void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event );

	void update();
	void draw();
    void prepareSettings( Settings *settings );

	void eyeUpdateThreadFn();

    ciUICanvas *gui;
    eyeFPS *eyeFpsLab;
    void guiEvent(ciUIEvent *event);

    ps4eye::PS4EYECam::PS4EYERef eye;

	bool mShouldQuit;
	std::thread mThread;

	gl::Texture mTextureLeft;

    gl::Texture mTextureRight;


	uint8_t *frame_rgb_left;
    uint8_t *frame_rgb_right;
	Surface mFrameLeft;
    Surface mFrameRight;



	// mesure cam fps
	Timer mTimer;
	uint32_t mCamFrameCount;
	float mCamFps;
	uint32_t mCamFpsLastSampleFrame;
	double mCamFpsLastSampleTime;
    int mDepthThreshold1;
    int mDepthThreshold2;

};
void convert_opencv_to_RGBA(uint8_t *in,uint8_t *out, int size_x,int size_y)
{

    cv::Mat yuv(size_y,size_x,CV_8UC2 ,in);
    cv::Mat rgb(size_y,size_x,CV_8UC4, out);

    cv::cvtColor(yuv, rgb, CV_YUV2RGBA_YUY2);


}
void convert_opencv_to_RGB(uint8_t *in,uint8_t *out, int size_x,int size_y)
{

    cv::Mat yuv(size_y,size_x,CV_8UC2 ,in);
    cv::Mat rgb(size_y,size_x,CV_8UC3, out);

    cv::cvtColor(yuv, rgb, CV_YUV2RGB_YUY2);

    
}

void convert_opencv_to_GRAY(uint8_t *in,uint8_t *out, int size_x,int size_y)
{

    cv::Mat rgb(size_y,size_x,CV_8UC3 ,in);
    cv::Mat gray(size_y,size_x,CV_8UC1, out);

    cv::cvtColor(rgb, gray, CV_RGB2GRAY);


}


void convert_depth_to_RGBA( const uint8_t *in,uint8_t *rgb, int size_x,int size_y,int low,int high)
{
    int i,j;
    uint16_t *aux=(uint16_t *)in;
  //  cout << aux[0] << endl;
    //cout << aux[0] << endl;
    unsigned char *out_ptr;
    uint16_t value;
    for(j=0;j<size_y;j++)
    {
        out_ptr=&rgb[size_x*3*j/*+size_x*3-1*/];

        for(i=0;i<size_x;i++)
        {

            //printf("%d,%d %02x %02x value=%d  \n",i,j,in[j*size_x*2+2*i],in[j*size_x*2+2*i+1],aux[j*size_x+i]);
            value=aux[size_x*j+i];//&0xafff;

            if(value <=low)
            {
               // *out_ptr-- = 255;

                *out_ptr++ = 0;
                *out_ptr++ = 0;
                *out_ptr++ = 255;
                //     printf("blue %d,%d %d\n",j,i,value);

            }
            if(value>low && value<high)
            {
                //*out_ptr-- = 255;

                *out_ptr++ = 0;
                *out_ptr++ = 255;
                *out_ptr++ = 0;
                //   printf("green %d,%d %d\n",j,i,value);



            }
            if(value>=high)
            {
                //*out_ptr-- = 255;

                *out_ptr++ = 255;
                *out_ptr++ = 0;
                *out_ptr++ = 0;
                // printf("red %d,%d %d\n",j,i,value);


            }



        }
        
        
    }

    
    
}

void convert_YUYV_to_RGB24(const uint8_t  *yuyv,  uint8_t *rgb,int size_x, int size_y)
{
    int K1 = (1.402f * (1 << 16));
    int K2 = (0.714f * (1 << 16));
    int K3 = (0.334f * (1 << 16));
    int K4 = (1.772f * (1 << 16));

    unsigned char* out_ptr;

    // unsigned char* out_ptr = &rgb_image[1280*3-1];
    const int pitch = size_x * 2; // 2 bytes per one YU-YV pixel

    for (int y=0; y<size_y; y++) {
        out_ptr=&rgb[size_x*4*y/*+1280*4-1*/];
        const unsigned char * src = yuyv + pitch * y;
      for (int x=0; x<size_x*2; x+=4) { // Y1 U Y2 V
            //for (int x=size_x*2-1; x<=0; x-=4) { // Y1 U Y2 V
            unsigned char Y1 = src[x + 0];
            unsigned char U  = src[x + 1];
            unsigned char Y2 = src[x + 2];
            unsigned char  V  = src[x + 3];

            int uf = U - 128;
            int vf = V - 128;

            int R = Y1 + (K1*vf >> 16);
            int G = Y1 - (K2*vf >> 16) - (K3*uf >> 16);
            int B = Y1 + (K4*uf >> 16);

            if (R < 0) R = 0;
            else if (R > 255) R = 255;
            if (G < 0) G = 0;
            else if (G > 255) G = 255;
            if (B < 0) B = 0;
            else if (B > 255) B = 255;

       //     *out_ptr-- = 255;

         //   *out_ptr-- = (unsigned char)B;
           // *out_ptr-- = (unsigned char)G;
            //*out_ptr-- = (unsigned char)R;
          *out_ptr++ = (unsigned char)R;



            *out_ptr++ = (unsigned char)G;
          *out_ptr++ = (unsigned char)B;



            *out_ptr++ = 255;






            /*   *out_ptr-- = 255;
             *out_ptr-- = 0;
             *out_ptr-- = 0;*/



            /**out_ptr++ = (unsigned char)R;
             *out_ptr++ = (unsigned char)G;
             *out_ptr++ = (unsigned char)B;*/



            R = Y2 + (K1*vf >> 16);
            G = Y2 - (K2*vf >> 16) - (K3*uf >> 16);
            B = Y2 + (K4*uf >> 16);


            if (R < 0) R = 0;
            else if (R > 255) R = 255;
            if (G < 0) G = 0;
            else if (G > 255) G = 255;
            if (B < 0) B = 0;
            else if (B > 255) B = 255;

          //  *out_ptr-- = 255;
           // *out_ptr-- = (unsigned char)B;
           // *out_ptr-- = (unsigned char)G;
           // *out_ptr-- = (unsigned char)R;
          *out_ptr++ = (unsigned char)R;
          *out_ptr++ = (unsigned char)G;

          *out_ptr++ = (unsigned char)B;

            *out_ptr++ = 255;
            /*  *out_ptr-- = 255;
             *out_ptr-- = 255;
             *out_ptr-- = 0;
             *out_ptr-- = 0;*/


            /**out_ptr++ = (unsigned char)R;
             *out_ptr++ = (unsigned char)G;
             *out_ptr++ = (unsigned char)B;*/
        }

    }
}
void PS4EYECaptureApp::prepareSettings( Settings *settings ){
    //for mode 1
    settings->setWindowSize( 1280, 800 );

   // settings->setFrameRate( 120.0f );
    settings->setFrameRate( 540.0f );
    settings->setBorderless();

}
void PS4EYECaptureApp::setup()
{
    using namespace ps4eye;

    mShouldQuit = false;

    // list out the devices
    std::vector<PS4EYECam::PS4EYERef> devices( PS4EYECam::getDevices() );
    // console() << "found " << devices.size() << " cameras" << std::endl;

    mTimer = Timer(true);
    mCamFrameCount = 0;
    mCamFps = 0;
    mCamFpsLastSampleFrame = 0;
    mCamFpsLastSampleTime = 0;

    //mode 1
    gui = new ciUICanvas(0,0,1280, 800);

    float gh = 15;
    float slw = 340 - 20;
    gl::disableVerticalSync();
   // setFrameRate(300.0f);
    if(devices.size())
    {
        eye = devices.at(0);
        //check or load firmware to PlayStation Camera and exit
        eye->firmware_path=cinder::app::App::getResourcePath("firmware.bin").c_str();
        eye->firmware_upload();
        //mode 0: 60,30,15,8 fps 1280x800
        //mode 1: 120,60,30,15,8 fps 640x400
        //mode 2: 240,120,60,30 fps 320x192
        if(!(eye->init(1, 120)))
        {
            cout << "init failed" << std::endl;
            //don't use when you are debugging is fine.
            //eye->stop();
           // exit(0);

        }
        //   console() << "init eye result " << res << std::endl;
        eye->start();
        //test values use it in depth mode
        mDepthThreshold1=35000;
        mDepthThreshold2=36000;

        frame_rgb_left = new uint8_t[eye->getWidth()*eye->getHeight()*3];
        frame_rgb_right = new uint8_t[eye->getWidth()*eye->getHeight()*3];

		mFrameLeft = Surface(frame_rgb_left, eye->getWidth(), eye->getHeight(), eye->getWidth()*3,SurfaceChannelOrder::RGB);
        memset(frame_rgb_left, 0, eye->getWidth()*eye->getHeight()*3);

        mFrameRight = Surface(frame_rgb_right, eye->getWidth(), eye->getHeight(), eye->getWidth()*3,SurfaceChannelOrder::RGB);
        memset(frame_rgb_right, 0, eye->getWidth()*eye->getHeight()*3);






		// create and launch the thread
		mThread = thread( bind( &PS4EYECaptureApp::eyeUpdateThreadFn, this ) );

        gui->addWidgetDown(new ciUILabel("PS4EYECAM", CI_UI_FONT_MEDIUM));

        eyeFpsLab = new eyeFPS(CI_UI_FONT_MEDIUM);
        gui->addWidgetRight(eyeFpsLab);

        // controls
       // gui->addWidgetDown(new ciUIToggle(gh, gh, false, "set led on"));
        //gui->addWidgetDown(new ciUIToggle(gh, gh, false, "reset sensor"));
        gui->addWidgetDown(new ciUIToggle(gh, gh, false, "stop stream"));
        gui->addWidgetRight(new ciUIToggle(gh, gh, false, "show right camera"));
       // gui->addWidgetDown(new ciUISlider(slw, gh, 0, 100000, mDepthThreshold1, "mDepthThreshold1"));
        //gui->addWidgetDown(new ciUISlider(slw, gh, 0, 100000, mDepthThreshold2, "mDepthThreshold2"));

        //gui->addWidgetDown(new ciUISlider(slw, gh, 0, 255, eye->getBrightness(), "brightness"));


        /*gui->addWidgetDown(new ciUISlider(slw, gh, 0, 63, eye->getGain(), "gain"));
         gui->addWidgetDown(new ciUISlider(slw, gh, 0, 63, eye->getSharpness(), "sharpness"));
         gui->addWidgetDown(new ciUISlider(slw, gh, 0, 255, eye->getExposure(), "exposure"));
         gui->addWidgetDown(new ciUISlider(slw, gh, 0, 255, eye->getBrightness(), "brightness"));
         gui->addWidgetDown(new ciUISlider(slw, gh, 0, 255, eye->getContrast(), "contrast"));
         gui->addWidgetDown(new ciUISlider(slw, gh, 0, 255, eye->getHue(), "hue"));
         gui->addWidgetDown(new ciUISlider(slw, gh, 0, 255, eye->getBlueBalance(), "blue balance"));
         gui->addWidgetDown(new ciUISlider(slw, gh, 0, 255, eye->getRedBalance(), "red balance"));*/

        gui->registerUIEvents(this, &PS4EYECaptureApp::guiEvent);
    }
    else
    {
        cout << "There is not a PlayStation Camera device on this System" << std::endl;
        exit(0);
    }

}
void PS4EYECaptureApp::guiEvent(ciUIEvent *event)
{
    string name = event->widget->getName();
    if(name == "stop stream")
    {
        ciUIToggle *t = (ciUIToggle * ) event->widget;
        if(t->getValue())
        {
            cout << "stop stream enabled" << std::endl;
           // eye->set_led_off();

            eye->stop();

        }
        else
        {
            cout << "stop stream disabled" << std::endl;
            eye->start();
        }

    }
    else if(name == "show right camera")
    {
        ciUIToggle *t = (ciUIToggle * ) event->widget;
        //eye->setAutogain(t->getValue());
        if(t->getValue())
        {
            cout << "show right camera enabled" << std::endl;
            eye->rightflag=1;
        }
        else
        {
            cout << "show right camera disabled" << std::endl;
            eye->rightflag=0;
        }
        

    }
  /*  else if(name == "mDepthThreshold1")
    {
        ciUISlider *s = (ciUISlider *) event->widget;
        mDepthThreshold1=(static_cast<float>(s->getScaledValue()));
    }else if(name == "mDepthThreshold2")
    {
        ciUISlider *s = (ciUISlider *) event->widget;
        mDepthThreshold2=(static_cast<float>(s->getScaledValue()));
    }*/

}

void PS4EYECaptureApp::eyeUpdateThreadFn()
{
	while( !mShouldQuit )
	{
		bool res = ps4eye::PS4EYECam::updateDevices();
        if(!res) break;
	}
}

void PS4EYECaptureApp::shutdown()
{
	mShouldQuit = true;
	mThread.join();
    // You should stop before exiting
    // otherwise the app will keep working
    cout << "Shutdown begin wait..." << std::endl;

    eye->shutdown();

    //
	delete[] frame_rgb_left;
    delete[] frame_rgb_right;

	delete gui;
}
void PS4EYECaptureApp::mouseDown( MouseEvent event )
{
}
void PS4EYECaptureApp::keyDown( KeyEvent event )
{

    if ( event.getChar() == 'f') {
        setFullScreen( !isFullScreen() );
    }

}
void PS4EYECaptureApp::update()
{
    eyeframe *frame;

    if(eye)
    {
        bool isNewFrame = eye->isNewFrame();
        if(isNewFrame)
        {
            eye->check_ff71();
            frame=eye->getLastVideoFramePointer();
            
            if(eye->rightflag)
            {
                //convert_depth_to_RGBA(eye->getLastDepthFramePointer(),frame_bgr,eye->getWidth(),eye->getHeight(),mDepthThreshold1,mDepthThreshold2);
               // convert_YUYV_to_RGB24(eye->getLastDepthFramePointer(),frame_bgra,eye->getWidth(), eye->getHeight());
                

          //      convert_opencv_to_RGBA((uint8 *)eye->getLastDepthFramePointer(), frame_bgra, eye->getWidth(), eye->getHeight());

            //    convert_opencv_to_RGB((uint8 *)eye->getLastVideoRightFramePointer(), frame_bgr, eye->getWidth(), eye->getHeight());

                convert_opencv_to_RGB(frame->videoRightFrame, frame_rgb_right, eye->getWidth(), eye->getHeight());
                
                



               mTextureRight = gl::Texture( mFrameRight );

               // depthtexture = gl::Texture( mFrame );



            }
            //else
            //{
               // convert_YUYV_to_RGB24(eye->getLastVideoFramePointer(),frame_bgra,eye->getWidth(), eye->getHeight());

        //        convert_opencv_to_RGBA((uint8 *)eye->getLastVideoFramePointer(), frame_bgra, eye->getWidth(), eye->getHeight());
            //    convert_opencv_to_RGB((uint8 *)eye->getLastVideoLeftFramePointer(), frame_bgr, eye->getWidth(), eye->getHeight());
                convert_opencv_to_RGB(frame->videoLeftFrame, frame_rgb_left, eye->getWidth(), eye->getHeight());
                


               // mTexture = gl::Texture( mFrame );
                mTextureLeft = gl::Texture( mFrameLeft );


            //}
        }
        mCamFrameCount += isNewFrame ? 1 : 0;
        double now = mTimer.getSeconds();
        if( now > mCamFpsLastSampleTime + 1 ) {
            uint32_t framesPassed = mCamFrameCount - mCamFpsLastSampleFrame;
            mCamFps = (float)(framesPassed / (now - mCamFpsLastSampleTime));

            mCamFpsLastSampleTime = now;
            mCamFpsLastSampleFrame = mCamFrameCount;
        }

        gui->update();
        eyeFpsLab->update_fps(mCamFps);
        // eyeFpsLab->update_fps(getAverageFps());
    }
}

void PS4EYECaptureApp::draw()
{
    gl::clear( Color::black() );
    gl::disableDepthRead();
    gl::disableDepthWrite();
    gl::enableAlphaBlending();
    
    gl::setMatricesWindow( getWindowWidth(), getWindowHeight() );
    //if( !eye->rightflag )
    //{
        if(mTextureLeft)
        {
        glPushMatrix();
        gl::draw( mTextureLeft );

    }
    if(eye->rightflag)
    {
        if(mTextureRight)
        {
            glPushMatrix();
            gl::draw(mTextureRight, Rectf(eye->getWidth(),0,eye->getWidth()*2,eye->getHeight()));
            glPopMatrix();
        }


    }
    
    gui->draw();
    
}

CINDER_APP_BASIC( PS4EYECaptureApp, RendererGl )
