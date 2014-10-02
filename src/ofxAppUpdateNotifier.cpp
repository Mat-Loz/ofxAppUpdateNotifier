#include "ofxAppUpdateNotifier.h"
#include "ofxJSON.h"

using namespace AppUpdateNotifier;


void ofxAppUpdateNotifier::init(int currentVersionNumber, string url, int frequencyInHours)
{
	_currentVersionNumber = currentVersionNumber;
	_url = url;
	_frequency = frequencyInHours * 3600;
	_hasFoundANewVersion = false;
	
	if (_frequency == 0)
		checkNewVersion();
}

//--------------------------------------------------------------
void ofxAppUpdateNotifier::update()
{
	if (_hasFoundANewVersion || _frequency <= 0)
		return;

	if (ofGetElapsedTimef() - _lastCheckedDate > _frequency)
		checkNewVersion();
}

//--------------------------------------------------------------
void ofxAppUpdateNotifier::checkNewVersion()
{
	ofxJSONElement response;
	if (!response.open(_url))
    {
        ofLogNotice("ofxAppUpdateNotifier::checkNewVersion") << "Failed to parse JSON";
    }
	else
	{
		int versionNumber = response["number"].asInt();
		if (versionNumber > _currentVersionNumber)
		{
			Version version;
			version.number = versionNumber;
			version.displayNumber = response["displayNumber"].asString();			
			version.isCritical = response["isCritial"].asBool();
			version.url = response["url"].asString();
			
			ofNotifyEvent(newVersionAvailable, version, this);
			_hasFoundANewVersion = true;
		}

		_lastCheckedDate = ofGetElapsedTimef();
	}	
}