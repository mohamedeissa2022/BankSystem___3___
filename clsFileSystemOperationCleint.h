#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsString.h"
#include "clsCleint.h"
class clsFileSystemOperationCleint
{


	vector<clsCleint> _vAllCleints;
	string filePathByCleint = "Cleint.txt";
	string ConverRecordToLine(clsCleint cleint) {
		string converted;
		converted = cleint.getAccountNumber() + "|##|";
		converted += cleint.getPinCode() + "|##|";
		converted += cleint.getName() + "|##|";
		converted += cleint.getPhone() + "|##|";
		converted += to_string(cleint.getAccountBalance());
		return converted;
	}
	clsCleint ConvertLineToRecord(string line) {
		clsCleint cleint;
		clsString strLib;
		vector<string> cAllUsers = strLib.split(line, "|##|");
		//AccountNumber|##|PinCode|##|Name|##|Phone|##|AccountBalance
		cleint.setAccountNumber(cAllUsers[0]);
		cleint.setPinCode(cAllUsers[1]);
		cleint.setName(cAllUsers[2]);
		cleint.setPhone(cAllUsers[3]);
		cleint.setAccountBalance(stod(cAllUsers[4]));
		return cleint;
	}

	vector<clsCleint> ConvertFileToVector() {
		vector<clsCleint> __cAllCleints;
		fstream file;
		string line;
		file.open(filePathByCleint, ios::in);

		if (file.is_open()) {
			while (getline(file, line))
			{
				__cAllCleints.push_back(ConvertLineToRecord(line));
			}
			file.close();
		}
		return __cAllCleints;
	}
public:
	void LoadFileData() {
		//_cAllUsers.clear();
		_vAllCleints = ConvertFileToVector();
	}
	vector<clsCleint> getData() {
		if (!_vAllCleints.empty())
			return _vAllCleints;
		return _vAllCleints;
	}
	void ConvertVectorToFile(vector<clsCleint> vAllCleints) {
		fstream file;
		file.open(filePathByCleint, ios::out);
		if (file.is_open()) {
			for (clsCleint cleint : vAllCleints) {
				file << ConverRecordToLine(cleint) << endl;
			}
		}
	}
	void clearCleintsFileData() {
		fstream file;
		file.open(filePathByCleint, ios::out);
		file.clear();
		file.close();
	}

};

