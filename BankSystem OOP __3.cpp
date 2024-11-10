// BankSystem OOP __3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "clsLoginScreen.h"
#include "clsBankSystemScreen.h"

void LoginSystem() {
	clsLoginScreen login;
	login.ShowLoginScreen();
	login.ReadUsernameAndPassword();
	login.Login();
	if (login.isLogin()) {
		
		clsBankSystemScreen startScreen(login.getUser());
		startScreen.showBankSystemScreen();
		startScreen.RunBankSystem(startScreen.Read_User_Bank_Operation_Selected());
	}
}

int main()
{

	//clsLoginScreen s1;
	//s1.ShowLoginScreen();
	//s1.ReadUsernameAndPassword();
	//s1.Login();
	//if (s1.isLogin()) {
	//	system("cls");
	//	// Show Menu Screen Now
	//	system("pause>0");
	//}
	//clsRegsterScreen s2;
	//s2.ShowRegisterScreen();
	//s2.logic.UserRegister();
	//if (s2.logic.isRegister()) {
	//	
	//}


	LoginSystem();

	system("pause");
}

