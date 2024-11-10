#pragma once
#include "clsString.h"
#include "clsFileUserOpertions.h"
#include "clsLoginLogic.h"
#include "clsScreenTheme.h"

class clsLoginScreen
{
	string _username;
	string _password;
	bool isLogined = false;
	clsLoginLogic LoginLogic;
	clsScreenTheme theme;


public:
	clsLoginScreen() {
		theme.setScreenThemeColor(theme.__white, theme.___Purple);
	}


	void ShowLoginScreen() {
		cout << "______________________________________________________________\n";
		cout << "                                                              \n";
		cout << "                       Login Screen                           \n";
		cout << "                                                              \n";
		cout << "______________________________________________________________\n";
		cout << "Alert :Password Contain CaptalLetters                          \n";
		cout << "And Small Letters And Numbers And Symbols.                    \n";
		cout << "______________________________________________________________\n";
	}
	void ReadUsernameAndPassword() {
		cout << "Enter Username:";
		cin >> _username;

		cout << "Enter Password:";
		cin >> _password;

	}
	void Login() {
		LoginLogic.CheckUserInSystem(_username, _password, isLogined);

	}
	bool isLogin() {
		theme.restThemeColor();
		return isLogined;
	}
	clsUser getUser() {
		return LoginLogic.getUserInfo();
	}

};

