#include "stdafx.h"
#include "Waiting.h"

Waiting::Waiting(Grant* grant) : GrantState(grant) {}

std::string Waiting::getState(){
	return "waiting";
}

bool Waiting::sendApplication(){
	std::cout << "Application already sent\n";
	return false;
}

bool Waiting::saveDraft(){
	std::cout << "Application already sent\n";
	return false;
}

bool Waiting::acceptApplication(){
	grant->setState(grant->stateConfirmed);
	std::cout << "Application accepted\n";
	return true;
}

bool Waiting::rejectApplication(){
	grant->setState(grant->stateRejected);
	std::cout << "Application rejected\n";
	return true;
}

bool Waiting::withdrawApplication(){
	grant->setState(grant->stateWithdrawn);
	std::cout << "Application withdrawn\n";
	return true;
}