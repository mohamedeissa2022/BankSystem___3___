#pragma once
#include <iostream>
#include "clsCleint.h"
#include "clsMangeUsersLogic.h"
#include "clsTransactionLogic.h"
using namespace std;
class ICleintOperations
{


public:
	virtual void AddCleint(clsCleint& cleint) = 0;
	virtual void DeleteCleint(string AccountNumber) = 0;
	virtual void UpdateCleint(string AccountNumber, clsCleint Updated_Cleint) = 0;
	virtual bool FindCleint(string AccountNumber) = 0;
	virtual clsTransactionLogic CleintTransactions() = 0;
	virtual clsMangeUsersLogic ManageUsers() = 0;

};

