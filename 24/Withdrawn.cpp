#include "stdafx.h"
#include "Withdrawn.h"

Withdrawn::Withdrawn(Grant* grant) : GrantState(grant) {}

std::string Withdrawn::getState(){
	return "withdrawn";
}

bool Withdrawn::sendApplication(){
	std::cout << "This application has been withdrawn, create new one\n";
	return false;
}

bool Withdrawn::saveDraft(){
	std::cout << "This application has been withdrawn, create new one\n";
	return false;
}

bool Withdrawn::acceptApplication(){
	std::cout << "Application already withdrawn\n";
	return false;
}

bool Withdrawn::rejectApplication(){
	std::cout << "Application already withdrawn\n";
	return false;
}

bool Withdrawn::withdrawApplication(){
	std::cout << "Application already withdrawn\n";
	return false;
}