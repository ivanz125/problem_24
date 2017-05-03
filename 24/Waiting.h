#include "GrantState.h"
#include "Grant.h"

class Waiting : public GrantState {
public:
	Waiting(Grant* grant);
	std::string getState();
	bool sendApplication();
	bool saveDraft();
	bool acceptApplication();
	bool rejectApplication();
	bool withdrawApplication();
};