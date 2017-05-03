#include "stdafx.h"
#include "Delayed.h"

Delayed::Delayed(Grant* grant) : GrantState(grant) {}

std::string Delayed::getState(){
	return "delayed";
}

bool Delayed::sendApplication(){
	grant->setState(grant->stateWaiting);
	std::cout << "Application sent\n";
	return true;
}

bool Delayed::saveDraft(){
	std::cout << "Application saved\n";
	return true;
}

bool Delayed::acceptApplication(){
	std::cout << "Application not sent yet\n";
	return false;
}

bool Delayed::rejectApplication(){
	std::cout << "Application not sent yet\n";
	return false;
}

bool Delayed::withdrawApplication(){
	std::cout << "Application not sent yet\n";
	return false;
}