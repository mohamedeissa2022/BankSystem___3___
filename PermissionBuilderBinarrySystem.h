#pragma once
//
// Created by mohammedeissa on 11/5/2024.
//


#include <iostream>
#include <string>
#include <math.h>
using  namespace  std;
#include <vector>
#include <iterator>


class PermissionBuilderBinarrySystem {
    short TotalPermissions;

    bool useKeyMaping;
    struct stPermissions {
        short permission;
    };
    struct stPermissionMaping {
        string key;
        short value;
    };
    vector<stPermissions> vPermissions;
    vector<stPermissionMaping> vPermissionsMap;
    bool bitWiseOperatorAnd(short CodePermission, short Permission) {
        return (CodePermission & Permission) == Permission;
    }

    short SumAllPermissions() {
        short Sum = 0;
        if (useKeyMaping) {
            if (vPermissionsMap.size() != 0)
            {
                for (stPermissionMaping permission : vPermissionsMap)
                    Sum += permission.value;
            }

        }
        else {
            if (vPermissions.size() != 0)
            {
                for (stPermissions permission : vPermissions)
                    Sum += permission.permission;
            }
        }

        return Sum;
    }

    short SumAllPermissionsBykey() {
        short Sum = 0;
        if (vPermissionsMap.size() != 0)
        {
            for (stPermissionMaping permission : vPermissionsMap)
                Sum += permission.value;
        }
        return Sum;
    }

public:
    PermissionBuilderBinarrySystem(short& StartPos, bool useKeyMaping = false) {
        this->TotalPermissions = StartPos;
        this->useKeyMaping = useKeyMaping;

    }
    PermissionBuilderBinarrySystem(bool useKeyMaping) {
        this->TotalPermissions = 0;
        this->useKeyMaping = useKeyMaping;

    }
    PermissionBuilderBinarrySystem() {

    }

    bool checkPermission(short permissionCode, short Permission) {
        if (bitWiseOperatorAnd(permissionCode, Permission)) {
            return true;
        }
        return false;
    }
    void addNewPermission() {
        stPermissions permission{};
        short CreatePermissionBinarry = (short)(pow(2, TotalPermissions));
        permission.permission = CreatePermissionBinarry;
        vPermissions.push_back(permission);
        TotalPermissions++;
    }


    void addNewPermission(string key) {
        stPermissionMaping maping;
        short CreatePermissionBinarry = (short)pow(2, TotalPermissions);
        maping.key = key;
        maping.value = CreatePermissionBinarry;
        vPermissionsMap.push_back(maping);
        TotalPermissions++;
    }




    short getPermissionCode() {
        //if(useKey)return SumAllPermissionsBykey();
        return  SumAllPermissions();
    }
    vector<short> getPermissions() {
        vector<short>  vAllPermissions;
        if (useKeyMaping) {
            if (vPermissionsMap.size() != 0) {
                for (stPermissionMaping& maping : vPermissionsMap)
                    vAllPermissions.push_back(maping.value);
            }
        }
        else {
            if (vPermissions.size() != 0) {
                for (stPermissions st_permissions : vPermissions)
                    vAllPermissions.push_back(st_permissions.permission);
            }
        }
        return vAllPermissions;
    }

    vector<string>getAllPermissionsKeys() noexcept{
        vector<string> vAllPermissionsKeys;
        if (!vPermissionsMap.empty() && useKeyMaping) {
            for (stPermissionMaping map : vPermissionsMap)vAllPermissionsKeys.push_back(map.key);
            return vAllPermissionsKeys;
        }
    }

    void ReadPermission(string permission_Name) {
        char ans = {'n'};
        cout << "Do You Need (" << permission_Name << ")  [y : n]:";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            addNewPermission(permission_Name);
        }
        else
        {
            return;
        }
    }
    void ReadListOfPermissions(string permissionsNames[],short totalPermissions) {
        for (size_t i = 0; i < totalPermissions; i++)
        {
            ReadPermission(permissionsNames[i]);
        }
    }


    void ReadListOfPermissions(vector<string> permissionsNames) {
   
 




        for (string permissionName : permissionsNames)
        {

            ReadPermission(permissionName);
        }
    }




    // Later On Futures:
    //importPermissions
    //ExportPermissions
    //updatePermission
    //removePermission
    //createPermissionGroup
    //addPermissionToGroup
    
};


