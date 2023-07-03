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
	mPurchasing
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
}UserMsg;

typedef struct
{
	string mBookName;
	string mSource;
	unsigned int mCount;
	float mPrice;
}PurchaseRecord;
