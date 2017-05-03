#include "GrantState.h"

class Withdrawn : public GrantState {
public:
	Withdrawn(Grant* grant);
	std::string getState();
	bool sendApplication();
	bool saveDraft();
	bool acceptApplication();
	bool rejectApplication();
	bool withdrawApplication();
};