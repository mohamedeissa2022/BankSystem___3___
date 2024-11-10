#pragma once
#include "IUserOperations.h"
#include "clsFileUserOpertions.h"
#include "PermissionBuilderBinarrySystem.h"
class clsMangeUsersLogic:private IUserOperations
{
	short startPos = 0;
	vector<clsUser> vAllUsers;
	clsFileUserOpertions userfileOperations;
	clsMangeUsersLogic* logic;
	clsUser ReadUserData(bool setDefaultPermission) {
		clsUser user;

		PermissionBuilderBinarrySystem BuildPermissions(startPos, true);
		string reader;
		cout << "Enter Username:";
		cin >> reader;
		user.Username = reader;
		reader.clear();
		cout << "Enter Password:";
		cin >> reader;
		user.Password = reader;
		reader.clear();
		if (setDefaultPermission) {
			user.setPermission(1);
		}
		cout << "_______________________________\n";
		return user;

	}

	void UpdateVectorData() {
		userfileOperations.LoadFileData();//load All Users
		vAllUsers = userfileOperations.getData();//get All Users Loaded From File And Return vector
	}
	clsUser* user=nullptr;
public:

	clsUser* getUserData() {
		if(user!=nullptr)
		return user;
	}
	clsMangeUsersLogic() {
		user = nullptr;
		vAllUsers.clear();
		logic =new  clsMangeUsersLogic();
	}
	void AddUser(clsUser user) override{
		//clsUser user;
		// Read User Data And Save To User Object
		//user = ReadUserData();

		userfileOperations.AddNewUserToFile(user);
	};
	void DeleteUser(string username)override {
		userfileOperations.DeleteUserFromFileByUsername(username);
		UpdateVectorData();
	};
	void UpdateUser(string username,clsUser user)override {
		userfileOperations.UpdateUserFromFileByUsername(username, user);
		UpdateVectorData();
	};
	bool FindUser(string username)override {
		UpdateVectorData();
		for (clsUser& u:vAllUsers)
		{
			if (username == u.Username) {
				user = &u;
				return true;
			}
		}
		return false;
	};

	void AddUser(bool setDefaultPermission){
		clsUser user;
		// Read User Data And Save To User Object
		user = ReadUserData(setDefaultPermission);

		userfileOperations.AddNewUserToFile(user);
	};


	clsMangeUsersLogic* getMangeUsersLogic() {
		if (logic != nullptr)return logic;
	}
};

