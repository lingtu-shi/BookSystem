/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: BookManager.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: define BookManager
 */

#pragma once

#include <string>
#include <list>
#include <vector>

#include "MemoryConfig.h"

#define BOOKPRICE_LEVEL_50 50
#define BOOKPRICE_LEVEL_100 100

using namespace std;
class BookManager
{
public:
	bool AddBook(const vector<string> bookMsg);
	void PrintAllBook(list<BookMsg> bookMap);
	void PrintBookMap(list<BookMsg> bookMap);
	bool SearchBook(const string& nameOrPrice);
	void SortBook();
	void ClassifyBook();
	vector<BookMsg*> GetBook(const string& name);
	list<BookMsg> GetBookMap() { return mBookMap; }
private:
	vector<list<BookMsg>::iterator>  IsBookExist(const string& nameOrPrice);
	string TrimString(const string& str);
private:
	list<BookMsg> mBookMap;
	list<BookMsg> mBookMaplow50;
	list<BookMsg> mBookMaplow100;
	list<BookMsg> mBookMapup100;
	float mTotalPrice;
}; 
