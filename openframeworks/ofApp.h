#pragma once

#include "ofMain.h"
#include "ps4eye.h"

class ps4eyeUpdate : public ofThread{

public:
    //   ps3eyeUpdate(){

    ps4eyeUpdate(){
    }

    void start(){
        startThread(false, false);   // blocking, verbose
    }

    void stop(){
        stopThread();
    }

    //--------------------------
    void threadedFunction()
    {
        while( isThreadRunning() != 0 )
        {
            //    bool res = ps3eye::PS3EYECam::updateDevices();
            bool res = ps4eye::PS4EYECam::updateDevices();

            if(!res)
            {
                break;
            }
        }
    }
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ps4eye::PS4EYECam::PS4EYERef eye;

    int camFrameCount;
    int camFpsLastSampleFrame;
    float camFpsLastSampleTime;
    float camFps;

    ps4eyeUpdate threadUpdate;

    unsigned char * videoFrame;
    ofTexture videoTextureLeft;
    ofTexture videoTextureRight;

    uint8_t *frame_rgb_left;
    uint8_t *frame_rgb_right;


};
