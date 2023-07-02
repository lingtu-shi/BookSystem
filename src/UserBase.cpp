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

list<UserMsg>::iterator UserBase::IsUserExist(const long long& userNum)
{
	for (auto it = mUserMap.begin(); it != mUserMap.end(); it++)
	{
		if (it->mUserNum == userNum) {
			return it;
		}
	}
	return mUserMap.end();
}

bool UserBase::AddUser(const vector<string>& userMsg)
{
	auto it = IsUserExist(atol(userMsg[2].c_str()));
	if (it != mUserMap.end())
	{
		char update = false;
		cout << "User is exist. update?(y/n)";
		cin >> update;
		if (update == 'y')
		{
			cin.ignore(numeric_limits< streamsize >::max(), '\n');
			mUserMap.erase(it);
		}
		else
		{
			cin.ignore(numeric_limits< streamsize >::max(), '\n');
			return false;
		}
	}
	UserMsg user;
	user.mUserName = userMsg[1];
	user.mUserNum = atol(userMsg[2].c_str());
	user.mDepartment = userMsg[3];
	mUserMap.push_back(user);
	return true;
}

bool UserBase::UpdateUser(const vector<string>& userMsg)
{
	auto it = IsUserExist(atol(userMsg[2].c_str()));
	if (it == mUserMap.end())
	{
		cout << "user " << userMsg[1] << " not found!" << endl;
		return false;
	}
	UserMsg user;
	user.mUserName = userMsg[1];
	user.mUserNum = atol(userMsg[2].c_str());
	user.mDepartment = userMsg[3];
	mUserMap.push_back(user);
	return true;
}

bool UserBase::SearchUser(const long long& userNum)
{
	cout << "Name\tNum\tDepartment" << endl;
	auto it = IsUserExist(userNum);
	if (it != mUserMap.end())
	{
		cout << it->mUserName << "\t" << it->mUserNum << "\t"\
			<< it->mDepartment << endl;
		return true;
	}
	else
	{
		cout << "..." << endl;
		cout << userNum << " not find!" << endl;
	}
	return false;
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

void UserBase::GetBookStatus(const string& name)
{
	SearchBook(name);
}
