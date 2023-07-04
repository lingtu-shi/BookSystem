/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: Borrower.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */

#include "Borrower.h"

Borrower::Borrower(BookService* bookService) : UserBase(bookService)
{
	mBookService = bookService;
	mBookManager = bookService->GetBookManager();
}

bool Borrower::SetBookState(const string& name, BookState lastState, BookState state)
{
	return mBookService->SetBookState(name, lastState, state);
}
