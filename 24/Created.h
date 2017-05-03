#include "GrantState.h"
#include "Grant.h"

class Created : public GrantState {
public:
	Created(Grant* grant);
	std::string getState();
	bool sendApplication();
	bool saveDraft();
	bool acceptApplication();
	bool rejectApplication();
	bool withdrawApplication();
};