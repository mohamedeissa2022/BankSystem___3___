#pragma once
#include <iostream>
#include "clsUser.h"
using namespace std;

class IUserOperations
{

public:
	virtual void AddUser(clsUser user) = 0;
	virtual void DeleteUser(string username) = 0;
	virtual void UpdateUser(string username,clsUser user) = 0;
	virtual bool FindUser(string username) = 0;
};

