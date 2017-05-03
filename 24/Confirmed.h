#include "GrantState.h"
#include "Grant.h"

class Confirmed : public GrantState {
public:
	Confirmed(Grant* grant);
	std::string getState();
	bool sendApplication();
	bool saveDraft();
	bool acceptApplication();
	bool rejectApplication();
	bool withdrawApplication();
};