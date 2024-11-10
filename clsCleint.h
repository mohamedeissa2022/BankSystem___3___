#pragma once
#include <iostream>
using namespace std;
class clsCleint
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0;
    //bool MarkForDelete = false;
    //bool MarkForUpdate = false;

    //AccountNumber|##|PinCode|##|Name|##|Phone|##|AccountBalance

public:

    void setAccountNumber(string _AccountNumber) {
        AccountNumber = _AccountNumber;
    }
    string getAccountNumber() {
        return AccountNumber;
    }

    void setPinCode(string _PinCode) {
        PinCode = _PinCode;
    }
    string getPinCode() {
        return PinCode;
    }

    void setName(string _Name) {
        Name = _Name;
    }
    string getName() {
        return Name;
    }


    void setPhone(string _Phone) {
        Phone = _Phone;
    }
    string getPhone() {
        return Phone;
    }


    void setAccountBalance(double _AccountBalance)
    {
        AccountBalance = _AccountBalance;
    }
    double getAccountBalance()
    {
        return AccountBalance;
    }




};
