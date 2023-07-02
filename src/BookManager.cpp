/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: BookManager.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: define BookManager
 */

#include <algorithm>
#include <iostream>

#include "BookManager.h"

void PrintBook(BookMsg book)
{
	cout << book.mBookName << "\t" << book.mBookPrice << "\t" << book.mBookNum\
		<< "\t" << book.mAuthor << "\t" << book.mPublishingHouse << endl;
}

list<BookMsg>::iterator BookManager::IsBookExist(const string& bookName)
{
	for (auto it = mBookMap.begin(); it != mBookMap.end(); it++)
	{
		if (it->mBookName == bookName) {
			return it;
		}
	}
	return mBookMap.end();
}

bool BookManager::AddBook(const vector<string> bookMsg)
{
	auto it = IsBookExist(bookMsg[1]);
	if (it != mBookMap.end())
	{
		char update = false;
		cout << "Book is exist. update?(y/n)";
		cin >> update;
		if (update == 'y')
		{
			cin.ignore(numeric_limits< streamsize >::max(), '\n');
			mBookMap.erase(it);
		}
		else
		{
			cin.ignore(numeric_limits< streamsize >::max(), '\n');
			return false;
		}
	}
	BookMsg book;
	book.mBookName = bookMsg[1];
	book.mBookPrice = atof(bookMsg[2].c_str());
	book.mBookNum = atol(bookMsg[3].c_str());
	book.mAuthor = bookMsg[4];
	book.mPublishingHouse = bookMsg[5];
	mBookMap.push_back(book);
	return true;
}

void BookManager::PrintAllBook(list<BookMsg> bookMap)
{
	if (bookMap.size() != 0)
	{
		cout << "Name\tPrice\tNum\tauthor\tpulishing house" << endl;
		for (const auto& book : bookMap)
		{
			PrintBook(book);
		}
	}
	else
	{
		cout << "Not Found Book!" << endl;
	}
}

bool BookManager::SearchBook(const string& nameOrPrice)
{
	cout << "Name\tPrice\tNum\tauthor\tpulishing house" << endl;
	bool res = false;
	auto it = IsBookExist(nameOrPrice);
	if (it != mBookMap.end())
	{
		PrintBook(*it);
		return true;
	}
	else
	{
		for (auto it = mBookMap.begin(); it != mBookMap.end(); it++)
		{
			if (it->mBookPrice == atof(nameOrPrice.c_str()))
			{
				PrintBook(*it);
				res = true;
			}
		}
	}
	if (res)
	{
		return true;
	}
	else
	{
		cout << "..." << endl;
		cout << nameOrPrice << " not find!" << endl;
	}
	return false;
}

bool CompareByValue(const BookMsg& lhs, const BookMsg& rhs) {
	return lhs.mBookPrice < rhs.mBookPrice;
}

void BookManager::SortBook()
{
	list<BookMsg> mBookMapSort;
	for (auto it = mBookMap.begin(); it != mBookMap.end(); it++)
	{
		mBookMapSort.push_back(*it);
	}
	mBookMapSort.sort(CompareByValue);
	//PrintAllBook(mBookMapSort);
	mBookMap.swap(mBookMapSort);
	cout << "sort OK!" << endl;
}

void BookManager::ClassifyBook()
{
	mBookMaplow50.clear();
	mBookMaplow100.clear();
	mBookMapup100.clear();
	float totalPricelow50 = 0;
	float totalPricelow100 = 0;
	float totalPriceup100 = 0;
	for (auto it = mBookMap.begin(); it != mBookMap.end(); it++)
	{
		if (it->mBookPrice < BOOKPRICE_LEVEL_50)
		{
			mBookMaplow50.push_back(*it);
			totalPricelow50 += it->mBookPrice;
		}
		else if (it->mBookPrice < BOOKPRICE_LEVEL_100)
		{
			mBookMaplow100.push_back(*it);
			totalPricelow100 += it->mBookPrice;
		}
		else
		{
			mBookMapup100.push_back(*it);
			totalPriceup100 += it->mBookPrice;
		}
	}
	cout << "Book Price ~50:" << endl;
	PrintAllBook(mBookMaplow50);
	cout << totalPricelow50 << " <- The total price of books under 50!" << endl;
	cout << "Book Price 50~100:" << endl;
	PrintAllBook(mBookMaplow100);
	cout << totalPricelow100 << " <- The total price of books under 100!" << endl;
	cout << "Book Price 100~:" << endl;
	PrintAllBook(mBookMapup100);
	cout << totalPriceup100 << " <- The total price of books above 100!" << endl;
	mTotalPrice = totalPricelow50 + totalPricelow100 + totalPriceup100;
	cout << mTotalPrice << " <- The total price of books." << endl;
}

string BookManager::TrimString(const string& str) {
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	if (first == string::npos || last == string::npos)
		return "";
	return str.substr(first, last - first + 1);
}
