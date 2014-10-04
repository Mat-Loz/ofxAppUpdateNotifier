#pragma once

#include "ofMain.h"
#include "ofxAppUpdateNotifier.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void draw();
	void exit();

	void onNewVersionAvailable(AppUpdateNotifier::Version& version);

private:
	ofxAppUpdateNotifier _appUpdateNotifier;
	bool _isAnUpdateAvailable;
	AppUpdateNotifier::Version _newVersion;
};
