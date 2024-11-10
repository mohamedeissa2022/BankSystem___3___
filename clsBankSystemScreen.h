#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreenTheme.h"
#include "clsBankSystemLogic.h"
#include "clsLoginScreen.h"
#include "clsMangeUsersScreen.h"
#include "clsMangeUsersLogic.h"
using namespace std;
class clsBankSystemScreen
{
	enum enBankOperations
	{
		_ShowCleints=1, _AddCleint = 2, _DeleteCleint = 3, _UpdateCleint = 4, _FindCleint = 5, _CleintTransactions = 6,_ManageUsers=7,_Logout=8
	};
	enum enTransactionMenu { _Withdraw = 1, _Deposit = 2, _CheckBalance = 3, _GoMainMenu=4};

	void PrintCleintData(clsCleint& cleint) {
		cout << left << setw(20) << cleint.getAccountNumber()<<" |";
		cout << left << setw(20) << cleint.getAccountBalance()<<" |";
		cout << left << setw(20) << cleint.getName()<<" |";
		cout << left << setw(20) << cleint.getPinCode()<<" |";
		cout << left << setw(20) << cleint .getPhone()<<" |";
		cout << endl;
	}
	clsBankSystemLogic _SystemBankLogic;
	void ShowAllCleints(vector<clsCleint> AllCleints) {
		cout << "______________________________________________________________\n";
		cout << "                                                              \n";
		cout << "                       Show All Cleints                       \n";
		cout << "                                                              \n";
		cout << "______________________________________________________________\n";
		cout << left << setw(20) << "Account Number |";
		cout << left << setw(20) << "Account Balance |";
		cout << left << setw(20) << "Name |";
		cout << left << setw(20) << "PinCode |";
		cout << left << setw(20) << "Phone |";
		cout << endl;
		for (clsCleint c: AllCleints)
		{
			PrintCleintData(c);
		}
	}
	void goBackMainMenuScreen() {
		clsBankSystemScreen s1;
		s1.showBankSystemScreen();
		s1.RunBankSystem(s1.Read_User_Bank_Operation_Selected());
		//showBankSystemScreen();
		//RunBankSystem(Read_User_Bank_Operation_Selected());
	}
	void ShowUpdateCleintScreen() {
		cout << "______________________________________________________________\n";
		cout << "                                                              \n";
		cout << "                       Update Cleint Screen                   \n";
		cout << "                                                              \n";
		cout << "______________________________________________________________\n";

	}
	void ShowDeleteCleintScreen() {
		cout << "______________________________________________________________\n";
		cout << "                                                              \n";
		cout << "                       Delete Cleint Screen                   \n";
		cout << "                                                              \n";
		cout << "______________________________________________________________\n";

	}
	void ShowFindCleintScreen() {
		cout << "______________________________________________________________\n";
		cout << "                                                              \n";
		cout << "                       Delete Cleint Screen                   \n";
		cout << "                                                              \n";
		cout << "______________________________________________________________\n";

	}
	string ReadAccountNumber(string msg) {
		string AccountNumber;
		cout << msg;
		cin >> AccountNumber;
		return AccountNumber;
	} 
	short ReadTransactionMenuSelectedItem() {
		short selected = 0;
		do
		{
			cout << "Please Choice Operation From [1 to 4]:";
			cin >> selected;
		} while (_SystemBankLogic.checkNumberInRange(selected,1,4));
	
		return selected;
	}
	void LogoutAccount() {
		clsLoginScreen login;
		login.ShowLoginScreen();
		login.ReadUsernameAndPassword();
		login.Login();
	}
	clsCleint ReadCleintData() {
		clsCleint c;
		string AccountNumber;
		string Name;
		string Phone;
		string PinCode;
		double AccountBalance;


		cout << "Enter Account Number:";
		cin >> AccountNumber;
		
		cout << "Enter Account Balance:";
		cin >> AccountBalance;

		cout << "Enter Name:";
		cin >> Name;
		
		cout << "Enter Phone:";
		cin >> Phone;
		
		cout << "Enter PinCode:";
		cin >> PinCode;

		c.setAccountNumber(AccountNumber);
		c.setAccountBalance(AccountBalance);
		c.setName(Name);
		c.setPhone(Phone);
		c.setPinCode(PinCode);

		return c;
	}
	void ShowScreenPermissionDenid() {
		cout << "______________________________________________________________\n";
		cout << "         Permission Denied (Please Contact your Admin)         \n";
		cout << "______________________________________________________________\n";
	}
	void ShowAddCleintScreen() {

		cout << "______________________________________________________________\n";
		cout << "                                                              \n";
		cout << "                       Add Cleint Screen                      \n";
		cout << "                                                              \n";
		cout << "______________________________________________________________\n";



	}
public:
	clsBankSystemScreen() {

	}
	clsBankSystemScreen(clsUser user) {
		_SystemBankLogic = clsBankSystemLogic(user);
		clsScreenTheme theme;
		theme.restThemeColor();
		theme.setScreenThemeColor(theme.__white, theme.___black);
	}
	void showBankSystemScreen() {
		cout << "______________________________________________________________\n";
		cout << "                                                              \n";
		cout << "                       Bank System Screen                     \n";
		cout << "                                                              \n";
		cout << "______________________________________________________________\n";
		cout << "1.Show Cleints.\n";
		cout << "2.Add Cleint.\n";
		cout << "3.Delete Cleint.\n";
		cout << "4.Update Cleint.\n";
		cout << "5.Find Cleint.\n";
		cout << "6.Cleint Transactions.\n";
		cout << "7.Manage Users.\n";
		cout << "8.Logout.\n";
		cout << "______________________________________________________________\n";
	}
	enBankOperations Read_User_Bank_Operation_Selected() {
		

		short selection = 0;
		do
		{
			cout << "Choice Selection from (1 to 8):";
			cin >> selection;
		} while (!_SystemBankLogic.checkNumberInRange(selection,1,8));
		return (enBankOperations)selection;
	}
	void RunBankSystem(enBankOperations UserSelection) {
		switch (UserSelection)
		{
		case clsBankSystemScreen::_ShowCleints: {
			system("cls");
			if (_SystemBankLogic._PermissionBuilder.checkPermission(_SystemBankLogic.getUser().getPermission(), _SystemBankLogic._ShowCleints)) {
				ShowAllCleints(_SystemBankLogic.getAllCleints());
			}
			else
			{
				ShowScreenPermissionDenid();
			}
			system("pause");
			goBackMainMenuScreen();
			break;
		}
		case clsBankSystemScreen::_AddCleint: {
			system("cls");
			if (_SystemBankLogic._PermissionBuilder.checkPermission(_SystemBankLogic.getUser().getPermission(), _SystemBankLogic._AddCleint)) {
			ShowAddCleintScreen();
			clsCleint cleint;
			cleint = ReadCleintData();
			_SystemBankLogic.AddCleint(cleint);
			}
			else
			{
				ShowScreenPermissionDenid();
			}
			system("pause");
			goBackMainMenuScreen();
			break;
		}
		case clsBankSystemScreen::_DeleteCleint:
		{
			system("cls");
			if (_SystemBankLogic._PermissionBuilder.checkPermission(_SystemBankLogic.getUser().getPermission(), _SystemBankLogic._DeleteCleint)) {

				ShowDeleteCleintScreen();
			_SystemBankLogic.DeleteCleint(ReadAccountNumber("Please Enter Account Number:"));
			}
			else
			{
				ShowScreenPermissionDenid();
			}
			system("pause");
			goBackMainMenuScreen();
			break;
		}
		case clsBankSystemScreen::_UpdateCleint:
		{
			system("cls");
			if (_SystemBankLogic._PermissionBuilder.checkPermission(_SystemBankLogic.getUser().getPermission(), _SystemBankLogic._UpdateCleint)) {

			ShowUpdateCleintScreen();
			_SystemBankLogic.UpdateCleint(ReadAccountNumber("Please Enter Account Number:"),ReadCleintData());
			}
			else
			{
				ShowScreenPermissionDenid();
			}
			system("pause");
			goBackMainMenuScreen();
			break;
		}
		case clsBankSystemScreen::_FindCleint:
		{
			system("cls");
			if (_SystemBankLogic._PermissionBuilder.checkPermission(_SystemBankLogic.getUser().getPermission(), _SystemBankLogic._FindCleint)) {

			ShowFindCleintScreen();
			_SystemBankLogic.FindCleint(ReadAccountNumber("Please Enter Account Number:"));
			}
			else
			{
				ShowScreenPermissionDenid();
			}
			system("pause");
			goBackMainMenuScreen();
			break;
		}
		case clsBankSystemScreen::_CleintTransactions:
		{
			
			system("cls");
			if (_SystemBankLogic._PermissionBuilder.checkPermission(_SystemBankLogic.getUser().getPermission(), _SystemBankLogic._CleintTransactions)) {
				clsTransactionScreen s1;
				clsTransactionLogic logicTransaction = _SystemBankLogic.CleintTransactions();

				s1.PerformTransactionScreen(logicTransaction);

			}
			else
			{
				ShowScreenPermissionDenid();
			}
			system("pause");
			goBackMainMenuScreen();
			break;
		}
		case clsBankSystemScreen::_ManageUsers:
		{
			system("cls");
			if (_SystemBankLogic._PermissionBuilder.checkPermission(_SystemBankLogic.getUser().getPermission(), _SystemBankLogic._ManageUsers)) {
				clsMangeUsersScreen s1;
				clsMangeUsersLogic logic;
				logic=_SystemBankLogic.ManageUsers();
				s1.PerformMangeUsersScreen(logic);
			}
			else
			{
				ShowScreenPermissionDenid();
			}
			system("pause");
			goBackMainMenuScreen();
			break;
		}
		case clsBankSystemScreen::_Logout:
		{
			system("cls");
			LogoutAccount();
			system("pause");
			break;
		}
		default:
			break;
		}
	}
};

