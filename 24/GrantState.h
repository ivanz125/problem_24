#pragma once
#include <string>
#include <iostream>

class Grant;

class GrantState{

protected:
	Grant* grant;

public:
	GrantState(Grant* grant) : grant(grant){}

	virtual std::string getState() = 0;
	virtual bool sendApplication() = 0;
	virtual bool saveDraft() = 0;
	virtual bool acceptApplication() = 0;
	virtual bool rejectApplication() = 0;
	virtual bool withdrawApplication() = 0;
};