/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: UserBase.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: define UserBase
 */

#include <iostream>

#include "UserBase.h"
UserBase::UserBase(BookService* bookService)
{
	mBookService = bookService;
	mBookManager = bookService->GetBookManager();
}

bool UserBase::SearchBook(const string& nameOrPrice)
{
	if (mBookManager->SearchBook(nameOrPrice))
	{
		return true;
	}
	return false;
}

void UserBase::PrintBook()
{
	mBookManager->PrintAllBook(mBookManager->GetBookMap());
}

void UserBase::PrintBookMap()
{
	mBookManager->PrintBookMap(mBookManager->GetBookMap());
}

void UserBase::GetBookStatus(const string& name)
{
	SearchBook(name);
}
