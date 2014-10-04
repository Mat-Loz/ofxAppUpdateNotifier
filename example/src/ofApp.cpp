#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(ofColor::black);
	_isAnUpdateAvailable = false;
	_appUpdateNotifier.init(1, "version.json", 1);
	ofAddListener(_appUpdateNotifier.newVersionAvailable, this, &ofApp::onNewVersionAvailable);
}

//--------------------------------------------------------------
void ofApp::draw()
{	
	if (_isAnUpdateAvailable)
	{
		const float x = 20;
		const float y = 20;
		const float padding = 20;
		ofDrawBitmapString("A new version is available !", x, y);
		ofDrawBitmapString("\tdisplayNumber :\t" + _newVersion.displayNumber, x, y + padding);
		ofDrawBitmapString("\tnumber :\t" + ofToString(_newVersion.number), x, y + padding * 2);
		ofDrawBitmapString("\tisCritical :\t" + ofToString(_newVersion.isCritical), x, y + padding * 3);
		ofDrawBitmapString("\turl :\t\t" + _newVersion.url, x, y + padding * 4);
	}
}

//--------------------------------------------------------------
void ofApp::exit()
{
	_appUpdateNotifier.exit();
}

//--------------------------------------------------------------
void ofApp::onNewVersionAvailable(AppUpdateNotifier::Version& version)
{
	_isAnUpdateAvailable = true;
	_newVersion = version;
}
