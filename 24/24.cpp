#include "stdafx.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Grant.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	Catch::Session().run(argc, argv);
	system("pause");
	return 0;
}

TEST_CASE("Created")
{
	Grant* grant = new Grant();
	CHECK(grant->getState().compare("created") == 0);
	CHECK(grant->acceptApplication() == false);
	CHECK(grant->rejectApplication() == false);
	CHECK(grant->withdrawApplication() == false);
	CHECK(grant->sendApplication() == true);
	CHECK(grant->getState().compare("waiting") == 0);

	Grant* grant2 = new Grant();
	CHECK(grant2->saveDraft() == true);
	CHECK(grant2->setDescription("Some text") == true);
	CHECK(grant2->getDescription().compare("Some text") == 0);
}

TEST_CASE("Delayed")
{
	Grant* grant = new Grant();
	CHECK(grant->saveDraft() == true);
	CHECK(grant->getState().compare("delayed") == 0);
	CHECK(grant->acceptApplication() == false);
	CHECK(grant->rejectApplication() == false);
	CHECK(grant->withdrawApplication() == false);
	CHECK(grant->saveDraft() == true);
	CHECK(grant->sendApplication() == true);
}

TEST_CASE("Waiting")
{
	Grant* grant = new Grant();
	CHECK(grant->sendApplication() == true);
	CHECK(grant->getState().compare("waiting") == 0);
	CHECK(grant->saveDraft() == false);
	CHECK(grant->sendApplication() == false);
	CHECK(grant->acceptApplication() == true);
	CHECK(grant->getState().compare("confirmed") == 0);

	Grant* toReject = new Grant();
	toReject->sendApplication();
	CHECK(toReject->rejectApplication() == true);
	CHECK(toReject->getState().compare("rejected") == 0);
	
	Grant* toWithdraw = new Grant();
	toWithdraw->sendApplication();
	CHECK(toWithdraw->withdrawApplication() == true);
	CHECK(toWithdraw->getState().compare("withdrawn") == 0);
}

TEST_CASE("Confirmed")
{
	Grant* grant = new Grant();
	grant->sendApplication();
	grant->acceptApplication();
	CHECK(grant->getState().compare("confirmed") == 0);
	CHECK(grant->sendApplication() == false);
	CHECK(grant->saveDraft() == false);
	CHECK(grant->acceptApplication() == false);
	CHECK(grant->rejectApplication() == false);
	CHECK(grant->withdrawApplication() == false);
}

TEST_CASE("Rejected")
{
	Grant* grant = new Grant();
	grant->sendApplication();
	grant->rejectApplication();
	CHECK(grant->getState().compare("rejected") == 0);
	CHECK(grant->sendApplication() == false);
	CHECK(grant->saveDraft() == false);
	CHECK(grant->acceptApplication() == false);
	CHECK(grant->rejectApplication() == false);
	CHECK(grant->withdrawApplication() == false);
}

TEST_CASE("Withdrawn")
{
	Grant* grant = new Grant();
	grant->sendApplication();
	grant->withdrawApplication();
	CHECK(grant->getState().compare("withdrawn") == 0);
	CHECK(grant->sendApplication() == false);
	CHECK(grant->saveDraft() == false);
	CHECK(grant->acceptApplication() == false);
	CHECK(grant->rejectApplication() == false);
	CHECK(grant->withdrawApplication() == false);
}