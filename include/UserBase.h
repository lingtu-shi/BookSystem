/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: UserManager.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: define UserBase
 */

#pragma once

#include <string>
#include <list>
#include <vector>

#include "BookService.h"

using namespace std;
class UserBase
{
public:
	UserBase(BookService* bookService);
	bool AddUser(const vector<string>& userMsg);
	bool UpdateUser(const vector<string>& userMsg);
	bool SearchUser(const long long& userNum);
	bool SearchBook(const string& nameOrPrice);
	void PrintBook();
	void GetBookStatus(const string& name);
protected:
	list<UserMsg>::iterator IsUserExist(const long long& userNum);
protected:
	BookService* mBookService;
	BookManager* mBookManager;
	list<UserMsg> mUserMap;
};
