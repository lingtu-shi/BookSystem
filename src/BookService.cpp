/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: BookService.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: Manage book status.
 */
#include "BookService.h"
#include <iostream>

using namespace std;
BookService::BookService(BookManager& bookManager)
{
	mBookManager = bookManager;
}

void BookService::GetBookState(const string& bookName)
{
	auto bookVec = mBookManager.GetBook(bookName);
	for (auto book : bookVec)
	{
		if (book != nullptr)
		{
			cout << book->mBookState << endl;
		}
	}
}

bool BookService::SetBookState(const string& bookName, BookState lastState, BookState state)
{
	auto bookVec = mBookManager.GetBook(bookName);
	for (auto book : bookVec)
	{
		if (book != nullptr)
		{
			if (book->mBookState == lastState)
			{
				if (state == BookState::mOnLoan && lastState != BookState::mAvailable)
				{
					return false;
				}
				book->mBookState = state;
				return true;
			}
		}
	}
	return false;
}

string BookService::GetBookSource(const string& bookName)
{
	auto bookVec = mBookManager.GetBook(bookName);
	if (bookVec.front() != nullptr)
	{
		return bookVec.front()->mBookSource;
	}
	return string();
}

string BookService::GetBookState(BookState state)
{
	string BookState[] = {
		"mAvailable",
		"mLost",
		"mDestoryed",
		"mOnLoan",
		"mPurchasing"
	};
	return BookState[state];
}

BookState BookService::SetBookState(string state)
{
	if (state == "mAvailable")
	{
		return BookState::mAvailable;
	}
	else if (state == "mLost")
	{
		return BookState::mLost;
	}
	else if (state == "mDestoryed")
	{
		return BookState::mDestoryed;
	}
	else if (state == "mOnLoan")
	{
		return BookState::mOnLoan;
	}
	else if (state == "mPurchasing")
	{
		return BookState::mPurchasing;
	}
	return BookState();
}
