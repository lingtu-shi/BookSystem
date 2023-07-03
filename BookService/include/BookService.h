/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: BookService.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */
#pragma once
#include "BookManager.h"

class BookService
{
public:
	BookService(BookManager& bookManager);
	void GetBookState(const string& bookName);
	bool SetBookState(const string& bookName, BookState lastState, BookState state);
	string GetBookSource(const string& bookName);
	string GetBookState(BookState state);
	BookState SetBookState(string state);
	BookManager* GetBookManager() { return &mBookManager; }
private:
	BookManager mBookManager;
};
