#pragma once

#include "ofMain.h"
#include "ofxAppUpdateNotifier.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void exit();

	void onNewVersionAvailable(AppUpdateNotifier::Version& version);

private:
	ofxAppUpdateNotifier _appUpdateNotifier;
};
