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
	//for test
	//if (mUserList.size() == 0)
	//{
	//	cout << "WARN: NO user in system!" << endl;
	//}
	for (auto it = mUserList.begin(); it != mUserList.end(); it++)
	{
		if (it->mUserNum == userNum) {
			return it;
		}
	}
	return mUserList.end();
}

bool UserManager::AddUser(const vector<string>& userMsg)
{
	auto it = IsUserExist(atol(userMsg[2].c_str()));
	if (it != mUserList.end())
	{
		char update = false;
		cout << "User is exist. update?(y/n)";
		cin >> update;
		if (update == 'y')
		{
			cin.ignore(numeric_limits< streamsize >::max(), '\n');
			mUserList.erase(it);
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
	mUserList.push_back(user);
	return true;
}

bool UserManager::UpdateUser(const vector<string>& userMsg)
{
	auto it = IsUserExist(atol(userMsg[2].c_str()));
	if (it == mUserList.end())
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
	mUserList.push_back(user);
	return true;
}

bool UserManager::SearchUser(const long long& userNum)
{
	cout << "Name\tNum\tDepartment\tUserStatus" << endl;
	auto it = IsUserExist(userNum);
	if (it != mUserList.end())
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

bool UserManager::DelUser(const long long& userNum)
{
	auto it = IsUserExist(userNum);
	if (it != mUserList.end())
	{
		cout << "Del user: " << it->mUserName << " - " << it->mUserNum << endl;
		mUserList.erase(it);
		return true;
	}
	else
	{
		cout << userNum << " not find!" << endl;
	}
	return false;
}

bool UserManager::MatchUser(const long long& userNum, const string& status)
{
	auto it = IsUserExist(userNum);
	if (it != mUserList.end())
	{
		if (SetUserStatus(status) == it->mStatus)
		{
			return true;
		}
	}
	return false;
}

void UserManager::PrintUser()
{
	if (mUserList.size() != 0)
	{
		cout << "Name\tNum\tDepartment\tUserStatus" << endl;
		for (auto it : mUserList)
		{
			cout << it.mUserName << "\t" << it.mUserNum << "\t"\
				<< it.mDepartment << "\t\t" << GetUserStatus(it.mStatus) << endl;
		}
	}
	else
	{
		cout << "There's nobody here." << endl;
	}
}

void UserManager::PrintBuyer()
{
	if (mUserList.size() != 0)
	{
		mBuyerList.clear();
		for (auto it : mUserList)
		{
			if (it.mStatus == UserStatus::mBookBuyer)
				mBuyerList.push_back(it);
		}
		if (mBuyerList.size() == 0)
			return;
		cout << "Name\tNum\tDepartment\tUserStatus" << endl;
		for (auto it : mBuyerList)
		{
			cout << it.mUserName << "\t" << it.mUserNum << "\t"\
				<< it.mDepartment << "\t\t" << GetUserStatus(it.mStatus) << endl;
		}
	}
	else
	{
		cout << "There's nobody here." << endl;
	}
}

void UserManager::PrintKeeper()
{
	if (mUserList.size() != 0)
	{
		mKeeperList.clear();
		for (auto it : mUserList)
		{
			if (it.mStatus == UserStatus::mBookKeeper)
				mKeeperList.push_back(it);
		}
		if (mKeeperList.size() == 0)
			return;
		cout << "Name\tNum\tDepartment\tUserStatus" << endl;
		for (auto it : mKeeperList)
		{
			cout << it.mUserName << "\t" << it.mUserNum << "\t"\
				<< it.mDepartment << "\t\t" << GetUserStatus(it.mStatus) << endl;
		}
	}
	else
	{
		cout << "There's nobody here." << endl;
	}
}

void UserManager::PrintBorrower()
{
	if (mUserList.size() != 0)
	{
		mBorrowerList.clear();
		for (auto it : mUserList)
		{
			if (it.mStatus == UserStatus::mBorrower)
				mBorrowerList.push_back(it);
		}
		if (mBorrowerList.size() == 0)
			return;
		cout << "Name\tNum\tDepartment\tUserStatus" << endl;
		for (auto it : mBorrowerList)
		{
			cout << it.mUserName << "\t" << it.mUserNum << "\t"\
				<< it.mDepartment << "\t\t" << GetUserStatus(it.mStatus) << endl;
		}
	}
	else
	{
		cout << "There's nobody here." << endl;
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

