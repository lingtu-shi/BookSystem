/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: MemoryConfig.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: define BookMsg UserMsg
 */

#pragma once
using namespace std;

enum BookState
{
	mAvailable = 0,
	mLost = 1,
	mDestoryed = 2,
	mOnLoan = 3,
	mPurchasing = 4,
	mBookError = 99
};

enum UserStatus
{
	mBookBuyer = 0,
	mBookKeeper = 1,
	mBorrower = 2,
	mUserError = 99
};

typedef struct
{
	string mBookName;
	long long mBookNum;
	float mBookPrice;
	string mAuthor;
	string mPublishingHouse;
	string mBookSource;
	BookState mBookState;
	string mHolder;
}BookMsg;

typedef struct
{
	long long mUserNum;
	string mUserName;
	string mDepartment;
	UserStatus mStatus;
}UserMsg;

typedef struct
{
	string mBookName;
	string mSource;
	unsigned int mCount;
	float mPrice;
}PurchaseRecord;
