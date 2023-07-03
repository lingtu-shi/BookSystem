/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: BookService.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */
#pragma once
#include "BookManager.h"
#include "UserManager.h"

class BookService
{
public:
	BookService(BookManager& bookManager, UserManager& userManager);
	void GetBookState(const string& bookName);
	bool SetBookState(const string& bookName, BookState lastState, BookState state);
	string GetBookSource(const string& bookName);

	BookState SetBookState(const string& state);
	string GetBookState(BookState state);

	BookManager* GetBookManager() { return &mBookManager; }
	UserManager* GetUserManager() { return &mUserManager; }
private:
	BookManager mBookManager;
	UserManager mUserManager;
};
