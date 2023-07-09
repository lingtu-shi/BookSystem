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
	bool SearchBook(const string& nameOrPrice);
	void PrintBook();
	void PrintBookMap();
	void GetBookStatus(const string& name);
protected:
	BookService* mBookService;
	BookManager* mBookManager;
};
