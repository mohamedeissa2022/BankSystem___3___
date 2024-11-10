#pragma once
#include "clsUser.h"
#include "clsString.h"
#include <string>
#include <fstream>
using namespace std;
class clsFileUserOpertions
{
	
	fstream file;
	string filePath = "Users.txt";
	vector<clsUser> _cAllUsers;
	class ObejectFormatFilePattern {
		string FormatFilePattern = "";
	public:
		enum enFilePatternUser{_username_password_PermissionCode_, _password_username_PermissionCode_, _PermissionCode_username_password_
		};
		ObejectFormatFilePattern(string username, string password, short PermissionCode, string spliter) {
			FormatFilePattern = username + spliter + password + spliter + to_string(PermissionCode);
		}
		ObejectFormatFilePattern(clsUser user, enFilePatternUser SelectPattern, string spliter,bool isActive) {
			if (isActive) {
				switch (SelectPattern)
				{
				case clsFileUserOpertions::ObejectFormatFilePattern::_username_password_PermissionCode_:
					FormatFilePattern = user.Username + spliter + user.Password + spliter + to_string(user.getPermission());
					break;
				case clsFileUserOpertions::ObejectFormatFilePattern::_password_username_PermissionCode_:
					FormatFilePattern = user.getPassword() + spliter + user.Username + spliter + to_string(user.getPermission());

					break;
				case clsFileUserOpertions::ObejectFormatFilePattern::_PermissionCode_username_password_:
					FormatFilePattern = to_string(user.getPermission()) + spliter + user.Username + spliter + user.Password;
					break;
				default:
					break;
				}

			}
			
		}

		/*
		
		ObejectFormatFilePattern(string password, string username, short PermissionCode, string spliter) {
			FormatFilePattern = password + spliter + username + spliter + to_string(PermissionCode);
		}
		ObejectFormatFilePattern(short PermissionCode, string username, string password, string spliter) {
			FormatFilePattern = to_string(PermissionCode) + spliter + username + spliter + password;
		}
		
		*/
		
		string getFormat() {
			return FormatFilePattern;
		}




	};
	clsUser ConvertLineToRecordByUser(string line) {
		clsUser user;
		clsString strLib;
		vector<string> cAllUsers = strLib.split(line, "|##|");
		user.setUsername(cAllUsers[0]);
		user.setPassword(cAllUsers[1]);
		user.setPermission(stoi(cAllUsers[2]));
		
		return user;
	}
	vector<clsUser> ConvertFileToVectorByUser() {
		vector<clsUser> cAllUsers;
		//fstream file;
		string line;
		file.open(filePath, ios::in);

		if (file.is_open()) {
			while (getline(file, line))
			{
				cAllUsers.push_back(ConvertLineToRecordByUser(line));
			}
			file.close();
		}
		return cAllUsers;
	}
	string ConverRecordToLine(clsUser user) {
		/*
		
		
		string converted;
		converted =user.getUsername() + "|##|"
			+ user.getPassword() + "|##|"
			+ to_string(user.getPermission());
		
		*/

		ObejectFormatFilePattern patternSelected= ObejectFormatFilePattern(user.getUsername(), user.getPassword(), user.getPermission(),"|##|");
		return patternSelected.getFormat();
	}

public:
	bool isEmpty() {
	//	fstream file;
		string line;
		file.open(filePath, ios::in);
		if (file.is_open()) {
			while (getline(file, line))
			{

			}
			file.close();
			if (line.empty()) {
				return true;
			}
		}
		return false;
	}
	void LoadFileData() {
		//_cAllUsers.clear();
		if(!isEmpty())
		_cAllUsers = ConvertFileToVectorByUser();
	}
	void ConvertVectorToFile(vector<clsUser> vAllUsers) {
		//fstream file;
		file.open(filePath, ios::out);
		if (file.is_open()) {
			for (clsUser user : vAllUsers) {
				file << ConverRecordToLine(user) << endl;
			}
		}
	}
	vector<clsUser> getData() {
		if (!_cAllUsers.empty())
			return _cAllUsers;
	}
	void clearFileData() {
		fstream file;
		file.open(filePath, ios::out);
		file.clear();
		file.close();
	}

	void AddNewUserToFile(clsUser user) {
		file.open(filePath, ios::app);
		if (file.is_open()) {
			file << ConverRecordToLine(user) << endl;
			file.close();
		}
		
	}
	void DeleteUserFromFileByUsername(string username) {
		LoadFileData();
		for (clsUser& user : _cAllUsers) {
			if (username == user.Username) {
				string line;
				vector<clsUser> allUsers;
				file.open(filePath, ios::in);
				if (file.is_open()) {
					while (getline(file, line))
					{
						if (line == ConverRecordToLine(user)) {
							continue;
						}
						else
						{
							allUsers.push_back(ConvertLineToRecordByUser(line));
						}
					}
					file.close();
				}
				if (!allUsers.empty()) {
					ConvertVectorToFile(allUsers);
					allUsers.clear();
					return;
				}
				return;
			}
		}
	}
	void DeleteUserFromFile(clsUser u) {
		LoadFileData();
		for (clsUser& user : _cAllUsers) {
			if (u.Username == user.Username) {
				string line;
				vector<clsUser> allUsers;
				file.open(filePath, ios::in);
				if (file.is_open()) {
					while (getline(file, line))
					{
						if (line == ConverRecordToLine(user)) {
							continue;
						}
						else
						{
							allUsers.push_back(ConvertLineToRecordByUser(line));
						}
					}
					file.close();
				}
				if (!allUsers.empty()) {
					ConvertVectorToFile(allUsers);
					allUsers.clear();
					return;
				}
				return;
			}
		}

	}


	void UpdateUserFromFileByUsername(string username,clsUser newUserData) {
		LoadFileData();
		bool isUpdated = false;
		for (clsUser& user : _cAllUsers) {
			if (username == user.Username) {
				user = newUserData;
				isUpdated = true;
				break;
			}
		}
		if (isUpdated) {
			ConvertVectorToFile(_cAllUsers);
			LoadFileData();
		}
	}
};

