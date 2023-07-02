/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: BookBuyer.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */
#pragma once
#include "UserBase.h"

class BookBuyer : public UserBase
{
public:
	BookBuyer(BookService* bookService);
	bool AddBook(const vector<string> bookMsg);

private:
	void RegisterPurchase(vector<string> bookMsg);

private:
	list<PurchaseRecord> mRecord;
};
