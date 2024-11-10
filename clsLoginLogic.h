#pragma once

#include "clsString.h"
#include "clsFileUserOpertions.h"
class clsLoginLogic
{
	struct stPasswordValidetor {
		bool isIncludeUpperCase = true;
		bool isIncludeLowerCase = true;
		bool isIncludeSympols = true;
		bool isIncludeNumbers = true;
		short MinmumChaructars = 8;
		short countUpperCaseChars = 0;
		short countLowerCaseChars = 0;
		short countSympolsChars = 0;
		short countNumbersChars = 0;
	};
	clsFileUserOpertions usersOperationFile;
	vector<clsUser> AllUsers;
	stPasswordValidetor stPsValidetor;

	bool isValidPassword(string password) {
		if (password.length() >= stPsValidetor.MinmumChaructars) {
			clsString strLib;
			bool temp = false;
			for (size_t i = 0; i < password.length(); i++)
			{
				if ((stPsValidetor.isIncludeUpperCase) && (strLib.isUpperCase(password[i])))
				{
					stPsValidetor.countUpperCaseChars++;
					//temp = true;
				}
				if ((stPsValidetor.isIncludeLowerCase) && (strLib.isLowerCase(password[i])))
				{
					stPsValidetor.countLowerCaseChars++;
					//temp = true;

				}
				if ((stPsValidetor.isIncludeNumbers) && (strLib.isDigit(password[i]))) {
					stPsValidetor.countNumbersChars++;
					//temp = true;

				}
				if ((stPsValidetor.isIncludeSympols) && (strLib.isPunct(password[i]))) {
					stPsValidetor.countSympolsChars++;
					//temp = true;

				}
			}
			if (stPsValidetor.isIncludeUpperCase && (stPsValidetor.countUpperCaseChars >= 1)) {
				if (stPsValidetor.isIncludeLowerCase && (stPsValidetor.countLowerCaseChars >= 1))
				{
					if (stPsValidetor.isIncludeNumbers && (stPsValidetor.countNumbersChars >= 1))
					{
						if ((stPsValidetor.isIncludeSympols && (stPsValidetor.countSympolsChars >= 1)) || stPsValidetor.isIncludeNumbers)
						{
							return true;
						}
					}
				}
			}
			return false;

		}
	}

	
	bool isLogin = false;
	clsUser user;
public:
	clsLoginLogic() {
		usersOperationFile.LoadFileData();
		AllUsers = usersOperationFile.getData();
	}
	void CheckUserInSystem(string username, string password) {
		usersOperationFile.LoadFileData();
		AllUsers = usersOperationFile.getData();
		for (clsUser& u : AllUsers)
		{
			if (u.Username == username && u.Password == password) {
				isLogin = true;
				bool __isValidPassword = isValidPassword(password);
				if (!username.empty() && __isValidPassword) {

				}
				else
				{
					if (!__isValidPassword) {
						cout << "Password Is Not Valid\n";
					}
					if (username.empty())
					{
						cout << "Username is Empty\n";
					}
				}
				break;
			}
		}
	}

	void CheckUserInSystem(string username,string password,bool& loginState) {
		usersOperationFile.LoadFileData();
		AllUsers = usersOperationFile.getData();
		for (clsUser& u : AllUsers)
		{
			if (u.Username == username && u.Password == password) {
				isLogin = true;
				loginState = true;
				bool __isValidPassword = isValidPassword(password);
				if (!username.empty() && __isValidPassword) {
					user = u;
					return;
				}
				else
				{
					/*
					
					if (!__isValidPassword) {
						cout << "Password Is Not Valid\n";
					}
					if (username.empty())
					{
						cout << "Username is Empty\n";
					}
					
					*/


				}
				break;
			}
		}
	}

	clsUser getUserInfo() { if(isLogin)return user; }
	/*
	bool isLogined() 
	{
		return isLogin;
	}
	*/
};

