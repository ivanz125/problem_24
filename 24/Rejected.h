#include "GrantState.h"

class Rejected : public GrantState {
public:
	Rejected(Grant* grant);
	std::string getState();
	bool sendApplication();
	bool saveDraft();
	bool acceptApplication();
	bool rejectApplication();
	bool withdrawApplication();
};