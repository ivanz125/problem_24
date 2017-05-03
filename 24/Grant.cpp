#include "stdafx.h"
#include "Grant.h"
#include "Created.h"
#include "Delayed.h"
#include "Waiting.h"
#include "Confirmed.h"
#include "Rejected.h"
#include "Withdrawn.h"

Grant::Grant(){
	stateCreated = new Created(this);
	stateDelayed = new Delayed(this);
	stateWaiting = new Waiting(this);
	stateConfirmed = new Confirmed(this);
	stateRejected = new Rejected(this);
	stateWithdrawn = new Withdrawn(this);
	setState(stateCreated);
}

void Grant::setState(GrantState* state){
	this->state = state;
}

std::string Grant::getState(){
	return state->getState();
}

bool Grant::setDescription(std::string text){
	if (saveDraft()) this->description = text;
	else std::cout << "Cannot change description in current state\n";
	return saveDraft();
}

std::string Grant::getDescription(){
	return description;
}

bool Grant::sendApplication(){
	return state->sendApplication();		
}

bool Grant::saveDraft(){
	return state->saveDraft();
}

bool Grant::acceptApplication(){
	return state->acceptApplication();
}

bool Grant::rejectApplication(){
	return state->rejectApplication();
}

bool Grant::withdrawApplication(){
	return state->withdrawApplication();
}