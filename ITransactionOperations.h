#pragma once
#include <iostream>
using namespace std;
class ITransactionOperations
{

public:
	virtual void WithdrawMoney(string AccountNumber,float money) = 0;
	virtual void DepositMoney(string AccountNumber,float money) = 0;
	virtual double CheckBalance(string AccountNumber) = 0;

};

