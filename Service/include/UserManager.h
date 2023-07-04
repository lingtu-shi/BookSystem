/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: UserManager.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */
#pragma once

#include <string>
#include <list>
#include <vector>

#include "MemoryConfig.h"

using namespace std;
class UserManager
{
public:
	bool AddUser(const vector<string>& userMsg);
	bool UpdateUser(const vector<string>& userMsg);
	bool SearchUser(const long long& userNum);
	bool MatchUser(const long long& userNum, const string& status);
	void PrintUser();
	UserStatus SetUserStatus(const string& status);
	string GetUserStatus(UserStatus status);
protected:
	list<UserMsg>::iterator IsUserExist(const long long& userNum);
protected:
	list<UserMsg> mUserMap;
};
