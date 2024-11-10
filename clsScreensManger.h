#pragma once
#include "clsScreenContorller.h"
class clsScreensManger:private clsScreenContorller
{
public:
	clsTransactionScreen* CreateTransactionScreen() {
		if (TransactionScreen == nullptr) {
			TransactionScreen = new clsTransactionScreen();
			return  TransactionScreen;
		}
		return TransactionScreen;
	}
	void Destroy_Transaction_Screen() {
		if (TransactionScreen != nullptr) {
			
			delete TransactionScreen;
			cout << "TransactionScreen Destroyed Done\n";
		}
		else
		{
			cout << "TransactionScreen Not Created In Memory Please Create object\n";
		}
	}

};

