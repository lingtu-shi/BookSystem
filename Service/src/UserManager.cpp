/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: UserManager.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: to do User Manage
 */

#include <iostream>

#include "UserManager.h"

list<UserMsg>::iterator UserManager::IsUserExist(const long long& userNum)
{
	for (auto it = mUserMap.begin(); it != mUserMap.end(); it++)
	{
		if (it->mUserNum == userNum) {
			return it;
		}
	}
	return mUserMap.end();
}

bool UserManager::AddUser(const vector<string>& userMsg)
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
	user.mStatus = SetUserStatus(userMsg[4]);
	if (user.mStatus == UserStatus::mUserError)
	{
		return false;
	}
	mUserMap.push_back(user);
	return true;
}

bool UserManager::UpdateUser(const vector<string>& userMsg)
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
	user.mStatus = SetUserStatus(userMsg[4]);
	if (user.mStatus == UserStatus::mUserError)
	{
		return false;
	}
	mUserMap.push_back(user);
	return true;
}

bool UserManager::SearchUser(const long long& userNum)
{
	cout << "Name\tNum\tDepartment\tUserStatus" << endl;
	auto it = IsUserExist(userNum);
	if (it != mUserMap.end())
	{
		cout << it->mUserName << "\t" << it->mUserNum << "\t"\
			<< it->mDepartment << "\t" << GetUserStatus(it->mStatus) << endl;
		return true;
	}
	else
	{
		cout << "..." << endl;
		cout << userNum << " not find!" << endl;
	}
	return false;
}

void UserManager::PrintUser()
{
	cout << "Name\tNum\tDepartment\tUserStatus" << endl;
	for (auto it : mUserMap)
	{
		cout << it.mUserName << "\t" << it.mUserNum << "\t"\
			<< it.mDepartment << "\t" << GetUserStatus(it.mStatus) << endl;
	}
}

UserStatus UserManager::SetUserStatus(const string& status)
{
	if (status == "buyer" || status == "bu")
	{
		return UserStatus::mBookBuyer;
	}
	else if (status == "keeper" || status == "k")
	{
		return UserStatus::mBookKeeper;
	}
	else if (status == "borrower" || status == "b")
	{
		return UserStatus::mBorrower;
	}
	else
	{
		cout << "Error: Input UserStatus error!" << endl;
	}
	return UserStatus::mUserError;
}

string UserManager::GetUserStatus(UserStatus status)
{
	switch (status)
	{
	case mBookBuyer:
		return "buyer";
	case mBookKeeper:
		return "keeper";
	case mBorrower:
		return "borrower";
	default:
		cout << "Error: Input UserStatus error!" << endl;
		return string();
	}
	return string();
}

