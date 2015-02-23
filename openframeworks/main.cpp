#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"


//========================================================================
int main( ){
    ofAppBaseWindow window;

	ofSetupOpenGL(1280,800,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
