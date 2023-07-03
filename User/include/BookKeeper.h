/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: BookKeeper.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */

#pragma once
#include "UserBase.h"

class BookKeeper : public UserBase
{
public:
	BookKeeper(BookService* bookService);
	void SortBook();
	void ClassifyBook();
	bool SetBookState(const string& name, BookState lastState, BookState state);
private:

};

