#include "stdafx.h"
#include "Rejected.h"

Rejected::Rejected(Grant* grant) : GrantState(grant) {}

std::string Rejected::getState(){
	return "rejected";
}

bool Rejected::sendApplication(){
	std::cout << "This application has been rejected, create new one\n";
	return false;
}

bool Rejected::saveDraft(){
	std::cout << "This application has been rejected, create new one\n";
	return false;
}

bool Rejected::acceptApplication(){
	std::cout << "Application already rejected\n";
	return false;
}

bool Rejected::rejectApplication(){
	std::cout << "Application already rejected\n";
	return false;
}

bool Rejected::withdrawApplication(){
	std::cout << "Application already rejected\n";
	return false;
}