/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: MemoryConfig.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: define BookMsg UserMsg
 */

#pragma once
using namespace std;

typedef struct _BookMsg
{
	string mBookName;
	long long mBookNum;
	float mBookPrice;
	string mAuthor;
	string mPublishingHouse;
}BookMsg;

typedef struct _UserMsg
{
	long long mUserNum;
	string mUserName;
	string mDepartment;
}UserMsg;