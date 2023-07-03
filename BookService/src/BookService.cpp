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
				if (state == BookState::mDestoryed && lastState != BookState::mAvailable)
				{
					return false;
				}
				if (state != BookState::mDestoryed && lastState == BookState::mDestoryed)
				{
					return false;
				}
				if (state != BookState::mAvailable && lastState == BookState::mPurchasing)
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
	if (state == "Available" || state == "a")
	{
		return BookState::mAvailable;
	}
	else if (state == "Lost" || state == "l")
	{
		return BookState::mLost;
	}
	else if (state == "Destoryed" || state == "d")
	{
		return BookState::mDestoryed;
	}
	else if (state == "OnLoan" || state == "o")
	{
		return BookState::mOnLoan;
	}
	else if (state == "Purchasing" || state == "p")
	{
		return BookState::mPurchasing;
	}
	return BookState();
}
