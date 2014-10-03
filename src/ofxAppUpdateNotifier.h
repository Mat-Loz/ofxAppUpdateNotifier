// ofxAppUpdateNotifier
// Raise an event when a new version of the app is available

#pragma once

#include "ofMain.h"


namespace AppUpdateNotifier
{
	struct Version
	{
	public:
		int number;
		string displayNumber;
		bool isCritical;
		string url;
	};
}


class ofxAppUpdateNotifier
{
public:
	void init(int currentVersionNumber, string url, int frequencyInHours, string filename = "AppUpdateLastCheckedDate");
	void update();
	void exit();

	ofEvent<AppUpdateNotifier::Version> newVersionAvailable;

private:
	void checkNewVersion();

	int _currentVersionNumber;
	string _url;
	int _frequency;
	float _lastCheckedDate;
	bool _hasFoundANewVersion;
	string _filename;
};