#pragma once


#include "clsMangeUsersLogic.h"
#include "clsString.h"


class clsMangeUsersScreen
{
	clsUser ReadUserData() {
		clsUser user;
		short startPos = 0;
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
		cout << "Enter Permissions:\n";
		cout << "_______________________________\n";
		BuildPermissions.ReadPermission("Show Clients");
		BuildPermissions.ReadPermission("Add Client");
		BuildPermissions.ReadPermission("Delete Client");
		BuildPermissions.ReadPermission("Update Client");
		BuildPermissions.ReadPermission("Find Client");
		cout << "_______________________________\n";

		user.setPermission(BuildPermissions.getPermissionCode());

		return user;

	}
	clsUser ReadUserData(string username) {
		clsUser user;
		short startPos = 0;
		PermissionBuilderBinarrySystem BuildPermissions(startPos, true);
		string reader;
		user.Username = username;
		cout << "Enter Password:";
		cin >> reader;
		user.Password = reader;
		reader.clear();
		cout << "Enter Permissions:\n";
		cout << "_______________________________\n";
		BuildPermissions.ReadPermission("Show Clients");
		BuildPermissions.ReadPermission("Add Client");
		BuildPermissions.ReadPermission("Delete Client");
		BuildPermissions.ReadPermission("Update Client");
		BuildPermissions.ReadPermission("Find Client");
		cout << "_______________________________\n";

		user.setPermission(BuildPermissions.getPermissionCode());

		return user;

	}

	enum enMangeUsersMenuItems{_AddUser=1,_DeleteUser=2,_UpdateUser=3,_FindUser=4,_GoBackMainMenu=5};
	string ReadUsrname(string msg) {
		string username;
		cout << msg;
		return username;
	}
	bool checkNumberInRange(short selection, short from, short to) {
		return (selection < from || selection>to) ? false : true;
	}
	short ReadUserSelectionMenuItem() {
		short selection = 0;
		do
		{
		cout << "Choice Mange Users Operations Selection from [1 to 5]:";
		cin >> selection;
		} while (checkNumberInRange(selection,1,5));
		return selection;
	}
	void ShowMangeUsersScreen() {

	}


	void GoBackMangeUsersMainMenu(clsMangeUsersLogic& logic) {
		clsMangeUsersScreen s1;
		s1.PerformMangeUsersScreen(logic);

	}
	//clsMangeUsersLogic logic;
public:
	void PerformMangeUsersScreen(clsMangeUsersLogic& logic) {
		ShowMangeUsersScreen();
		enMangeUsersMenuItems MenuItems;
		string username;
		MenuItems = (enMangeUsersMenuItems)ReadUserSelectionMenuItem();
		switch (MenuItems)
		{
		case clsMangeUsersScreen::_AddUser:
		{
			system("cls");
			logic.AddUser(ReadUserData());
			system("pause>0");
			GoBackMangeUsersMainMenu(logic);

			break;
		}
		case clsMangeUsersScreen::_DeleteUser:
		{
			username = ReadUsrname("Plese Enter Username To Delete:");

			logic.DeleteUser(ReadUsrname(username));
			system("pause>0");
			GoBackMangeUsersMainMenu(logic);

			break;
		}
		case clsMangeUsersScreen::_UpdateUser:
		{
			username = ReadUsrname("Plese Enter Username To Update:");
			logic.UpdateUser(username, ReadUserData(username));
			system("pause>0");
			GoBackMangeUsersMainMenu(logic);
			break;
		}
		case clsMangeUsersScreen::_FindUser:
		{
			username = ReadUsrname("Plese Enter Username To Find:");

			logic.FindUser(username);
			system("pause>0");
			GoBackMangeUsersMainMenu(logic);
			break;
		}
		case clsMangeUsersScreen::_GoBackMainMenu:
		{

			return;
		}

		}
		
		
	}
};

