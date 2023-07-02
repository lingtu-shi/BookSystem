/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: Borrower.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */
#pragma once
#include "UserBase.h"

class Borrower : public UserBase
{
public:
	Borrower(BookService* bookService);
	bool SetBookState(const string& name, BookState lastState, BookState state);
private:

};
