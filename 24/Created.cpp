#include "stdafx.h"
#include "Created.h"

Created::Created(Grant* grant) : GrantState(grant) {}

std::string Created::getState(){
	return "created";
}

bool Created::sendApplication(){
	grant->setState(grant->stateWaiting);
	std::cout << "Application sent\n";
	return true;
}

bool Created::saveDraft(){
	grant->setState(grant->stateDelayed);
	std::cout << "Application saved\n";
	return true;
}

bool Created::acceptApplication(){
	std::cout << "Application not sent yet\n";
	return false;
}

bool Created::rejectApplication(){
	std::cout << "Application not sent yet\n";
	return false;
}

bool Created::withdrawApplication(){
	std::cout << "Application not sent yet\n";
	return false;
}