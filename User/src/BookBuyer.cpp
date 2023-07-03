/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: BookBuyer.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */

#include "BookBuyer.h"

BookBuyer::BookBuyer(BookService* bookService) : UserBase(bookService)
{
	mBookService = bookService;
	mBookManager = bookService->GetBookManager();
}

bool BookBuyer::AddBook(const vector<string> bookMsg)
{
	if (mBookManager->AddBook(bookMsg))
	{
		RegisterPurchase(bookMsg);
		return true;
	}
	return false;
}

void BookBuyer::RegisterPurchase(vector<string> bookMsg)
{
	PurchaseRecord record;
	record.mBookName = bookMsg[1];
	record.mPrice = atof(bookMsg[2].c_str());
	record.mCount = atoi(bookMsg[6].c_str());
	record.mSource = bookMsg[7];
	mRecord.push_back(record);
}
