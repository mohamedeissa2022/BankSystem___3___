#pragma once
#include <iostream>
#include "clsTransactionLogic.h"


using namespace std;
class clsTransactionScreen
{
	clsTransactionScreen* transactionScreen = nullptr;
	short selection = 0;
	enum enTransactionOperations { __WithdrawMoney = 1, __DepositMoney = 2, __CheckBalance = 3, __GoBackToMainMen = 4 };
	void ShowTransactionMenuItems() {
		cout << "__________________________\n";
		cout << "____Transaction Screen____\n";
		cout << "__________________________\n";

		cout << "1.Withdraw Money.\n";
		cout << "2.Deposit Money.\n";
		cout << "3.Check Balance.\n";
	}
	short ReadSelection() {
		do
		{
			cout << ":";
			cin >> selection;
		} while (selection < 1 || selection>3);

		return selection;
	}
	enTransactionOperations ReadCleintMenuSelection() {
		return (enTransactionOperations)ReadSelection();
	}
	void GoToTransactonScreen(clsTransactionLogic& logic) {
		//transactionScreen = new clsTransactionScreen();
		//transactionScreen->PerformTransactionScreen();
		//delete transactionScreen;
		clsTransactionScreen transactionScreen;
		transactionScreen.PerformTransactionScreen(logic);

	}

	string ReadAccountNumber(string msg) {
		string AccountNumber;
		cout << msg;
		cin >> AccountNumber;
		return AccountNumber;
	}
	float ReadMoney(string msg) {
		float money;
		cout << msg;
		cin >> money;
		return money;
	}
public:
	clsTransactionScreen() {
		system("cls");
	
		ShowTransactionMenuItems();
	}
	void PerformTransactionScreen(clsTransactionLogic& logic) {
		enTransactionOperations transactionOp = {};
		transactionOp = ReadCleintMenuSelection();
		string AccountNumber;
		float Money;
		switch (transactionOp)
		{
		case clsTransactionScreen::__WithdrawMoney: {
			system("cls");
			 AccountNumber = ReadAccountNumber("Enter Account Number:");
			 Money = ReadMoney("Enter Money To Withdraw:");
			logic.WithdrawMoney(AccountNumber, Money);
			cout << "__WithdrawMoney\n";
			system("pause>0");
			GoToTransactonScreen(logic);
			break;
		}
		case clsTransactionScreen::__DepositMoney: {
			system("cls");
			//cout << "__DepositMoney\n";
			AccountNumber = ReadAccountNumber("Enter Account Number:");
			Money = ReadMoney("Enter Money To Deposit:");
			logic.DepositMoney(AccountNumber, Money);
			system("pause>0");
			GoToTransactonScreen(logic);
			break;
		}
		case clsTransactionScreen::__CheckBalance: {
			system("cls");
			//cout << "__CheckBalance\n";
			AccountNumber = ReadAccountNumber("Enter Account Number:");
			cout<<"Balance Now:"<<logic.CheckBalance(AccountNumber)<<endl;
			system("pause>0");
			GoToTransactonScreen(logic);
			break;
		}
		case clsTransactionScreen::__GoBackToMainMen: {
			system("cls");
			return;
		}

		}
	}
};

