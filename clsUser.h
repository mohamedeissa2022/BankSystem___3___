#pragma once
#include <iostream>
#include <vector>
#include "clsFileUserOpertions.h"
using namespace std;
class clsUser
{
	string _username;
	string _password;
	short PermissionCode;
	vector<clsUser> _vAllUsers;
	

public:

	clsUser() {

	}
	clsUser(string username, string password, short PermissionCode) {
		_username = username;
		_password = password;
		this->PermissionCode = PermissionCode;

	}
	void setUsername(string username) {
		_username = username;
	}
	void setPassword(string password) {
		_password = password;
	}
	__declspec(property(get = getUsername, put = setUsername)) string Username;
	string getUsername() {
		return _username;
	}
	string getPassword() {
		return _password;
	}
	__declspec(property(get = getPassword, put = setPassword)) string Password;

	void setPermission(short permission) {
		PermissionCode = permission;
	}
	short getPermission() {
		return PermissionCode;
	}



};

