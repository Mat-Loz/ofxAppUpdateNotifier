#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	_appUpdateNotifier.init(1, "version.json", 1);
	ofAddListener(_appUpdateNotifier.newVersionAvailable, this, &ofApp::onNewVersionAvailable);
}

//--------------------------------------------------------------
void ofApp::update()
{
	_appUpdateNotifier.update();
}

//--------------------------------------------------------------
void ofApp::exit()
{
	_appUpdateNotifier.exit();
}

//--------------------------------------------------------------
void ofApp::onNewVersionAvailable(AppUpdateNotifier::Version& version)
{
	ofLog() << "A new version is available: " << version.displayNumber << " download it there: " << version.url;
}
