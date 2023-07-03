/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: BookKeeper.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */

#include "BookKeeper.h"

BookKeeper::BookKeeper(BookService* bookService) : UserBase(bookService)
{
	mBookService = bookService;
	mBookManager = bookService->GetBookManager();
}

void BookKeeper::SortBook()
{
	mBookManager->SortBook();
}

void BookKeeper::ClassifyBook()
{
	mBookManager->ClassifyBook();
}

bool BookKeeper::SetBookState(const string& name, BookState lastState, BookState state)
{
	return mBookService->SetBookState(name, lastState, state);
}
