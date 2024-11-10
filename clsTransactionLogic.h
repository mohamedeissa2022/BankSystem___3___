#pragma once


#include <iostream>
#include "ITransactionOperations.h"
#include "clsFileSystemOperationCleint.h"
using namespace std;

class clsTransactionLogic:private ITransactionOperations
{
	vector<clsCleint>vAllCleints;
	clsFileSystemOperationCleint systemFileCleint;
	void LoadData() {
		//get client data from file
		systemFileCleint.LoadFileData();
		vAllCleints = systemFileCleint.getData();
	}
public:

	void WithdrawMoney(string AccountNumber, float money)override {
		LoadData();
		for (clsCleint& c : vAllCleints) {
			if (AccountNumber == c.getAccountNumber()) {
				c.setAccountBalance(c.getAccountBalance() - money);
				systemFileCleint.ConvertVectorToFile(vAllCleints);
				vAllCleints.clear();
				return;
			}
		}
	};
	void DepositMoney(string AccountNumber, float money)override {
		LoadData();
		for (clsCleint& c : vAllCleints) {
			if (AccountNumber == c.getAccountNumber()) {
				c.setAccountBalance(c.getAccountBalance() + money);
				systemFileCleint.ConvertVectorToFile(vAllCleints);
				vAllCleints.clear();
				return;
			}
		}

	};
	double CheckBalance(string AccountNumber)override {
		LoadData();
		for (clsCleint& c : vAllCleints) 
			if (AccountNumber == c.getAccountNumber())return c.getAccountBalance();
		
	};
};

