#pragma once
#include "clsUser.h"
#include "clsMangeUsersLogic.h"
class clsRegsterLogic
{
	bool isRegistered = false;
public:
	void UserRegister() {
		clsMangeUsersLogic logic;
		logic.AddUser(true);//Add New User And Set permission Default is Show Clients Need More Permissions Contact Administrator 
		isRegistered = true;
	}
	bool isRegister() {
		return isRegistered;
	}
};

