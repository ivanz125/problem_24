#pragma once
#include "GrantState.h"

class Grant{

	GrantState* state;
	std::string description;

public:
	GrantState* stateCreated;
	GrantState* stateDelayed;
	GrantState* stateWaiting;
	GrantState* stateConfirmed;
	GrantState* stateRejected;
	GrantState* stateWithdrawn;

	Grant();
	void setState(GrantState* state);
	std::string getState();
	bool setDescription(std::string text);
	std::string getDescription();
	bool sendApplication();
	bool saveDraft();
	bool acceptApplication();
	bool rejectApplication();
	bool withdrawApplication();
};