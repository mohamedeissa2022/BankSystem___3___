#pragma once
#include "clsFileSystemOperationCleint.h"
#include "clsTransactionScreen.h"
#include "PermissionBuilderBinarrySystem.h"
#include "clsMangeUsersLogic.h"
#include "clsTransactionLogic.h"



#include "ICleintOperations.h"
#include  <vector>
#include  <iostream>
using namespace std;
class clsBankSystemLogic:public ICleintOperations
{
	clsMangeUsersLogic MangeUsersLogic;
	clsFileSystemOperationCleint FileCleintOp;
	vector<clsCleint> vAllCleints;
	void loadFileDataToVector() {
		FileCleintOp.LoadFileData();
		vAllCleints = FileCleintOp.getData();
	}
	clsUser user;
public:
	PermissionBuilderBinarrySystem _PermissionBuilder;
	enum enBankOperations{_Admin=-1,_ShowCleints=1,_AddCleint=2,_DeleteCleint=4,_UpdateCleint=8,_FindCleint=16,_CleintTransactions=32,_ManageUsers=64};
	clsBankSystemLogic() {

	}
	clsBankSystemLogic(clsUser user) {
		this->user = user;
		_PermissionBuilder = PermissionBuilderBinarrySystem(false);

	}
	

	bool checkNumberInRange(short selection, short from, short to) {
		return (selection < from || selection>to) ? false : true;
	}
	void AddCleint(clsCleint& cleint)override {
		loadFileDataToVector();
		vAllCleints.push_back(cleint);
		FileCleintOp.ConvertVectorToFile(vAllCleints);
	};
	void DeleteCleint(string AccountNumber)override {
		loadFileDataToVector();
		vector<clsCleint> tempData;

		for (clsCleint& c : vAllCleints) {
			if (AccountNumber != c.getAccountNumber()) {
				tempData.push_back(c);
			}
		}
		vAllCleints = tempData;
		FileCleintOp.ConvertVectorToFile(vAllCleints);
		tempData.clear();
	};
	void UpdateCleint(string AccountNumber,clsCleint Updated_Cleint)override {
		loadFileDataToVector();
		for (clsCleint& c : vAllCleints) {
			if (AccountNumber != c.getAccountNumber()) {
				c = Updated_Cleint;
				return;
			}
		}

	};
	bool FindCleint(string AccountNumber)override {
		loadFileDataToVector();
		for (clsCleint& c : vAllCleints) {
			if (AccountNumber != c.getAccountNumber()) {
				return true;
			}
		}
		return false;
	};
	clsTransactionLogic CleintTransactions()override {
		return clsTransactionLogic();
	};
	clsMangeUsersLogic ManageUsers()override {
		return clsMangeUsersLogic();
	};
	vector<clsCleint> getAllCleints() {
		FileCleintOp.LoadFileData();
		vAllCleints = FileCleintOp.getData();
		return vAllCleints;
	}
	clsUser getUser() {
		return user;
	}

};

