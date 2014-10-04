#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"

int main()
{
	ofSetupOpenGL(600, 120, OF_WINDOW);
	ofRunApp(new ofApp());
}
