#include "GrantState.h"
#include "Grant.h"

class Delayed : public GrantState {
public:
	Delayed(Grant* grant);
	std::string getState();
	bool sendApplication();
	bool saveDraft();
	bool acceptApplication();
	bool rejectApplication();
	bool withdrawApplication();
};