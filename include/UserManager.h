/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: UserManager.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: define UserManager
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
private:
	list<UserMsg>::iterator IsUserExist(const long long& userNum);
private:
	list<UserMsg> mUserMap;
};
