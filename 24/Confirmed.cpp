#include "stdafx.h"
#include "Confirmed.h"

Confirmed::Confirmed(Grant* grant) : GrantState(grant) {}

std::string Confirmed::getState(){
	return "confirmed";
}

bool Confirmed::sendApplication(){
	std::cout << "Application already sent\n";
	return false;
}

bool Confirmed::saveDraft(){
	std::cout << "Application already sent\n";
	return false;
}

bool Confirmed::acceptApplication(){
	std::cout << "Application already accepted\n";
	return false;
}

bool Confirmed::rejectApplication(){
	std::cout << "Application already accepted\n";
	return false;
}

bool Confirmed::withdrawApplication(){
	std::cout << "Application already accepted\n";
	return false;
}