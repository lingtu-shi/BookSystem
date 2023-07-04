/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: UI.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */

#include "SystemUI.h"
#include <iostream>

void SystemUI::GetUI()
{
	cout << "********Book System********" << endl;
	cout << "*****Enter Mode*****" << endl;
	cout << "b/borrower : enter borrower mode" << endl;
	cout << "k/keeper : enter keeper mode" << endl;
	cout << "bu/buyer : enter buyer mode" << endl;
	cout << "a/admin : enter UserManager" << endl;
	cout << "help/h : to get help" << endl;
	cout << "quit/q : to exit" << endl << endl;
}

void SystemUI::GetBuyerUI()
{
	cout << "*****Buyer Mode*****" << endl;
	cout << "*****Input command:(command parameters)*****" << endl;
	cout << "add [BookName] [BookPrice] [BookNum] [Author] \
[Pulishing house] [Count] [Purchase Source]" << endl;
	cout << "print : to print all books" << endl;
	cout << "printBS : to print all books source" << endl;
	cout << "search [BookName]/[BookPrice]/[BookName BookPrice]  : to search book" << endl;
	cout << "help/h : to get help" << endl;
	cout << "quit/q : to exit" << endl << endl;
}

void SystemUI::GetKeeperUI()
{
	cout << "*****Keeper Mode*****" << endl;
	cout << "*****Input command:(command parameters)*****" << endl;
	cout << "print : to print all books" << endl;
	cout << "search [BookName]/[BookPrice]/[BookName BookPrice]  : to search book" << endl;
	cout << "sort : to sort book map" << endl;
	cout << "classify : to divided into three categories by book price(~50,50~100,100~)" << endl;
	cout << "setstate [BookName] [BookLastState] [BookState]: to set BookState" << endl;
	cout << "==>BookState[]={ Available(/a), Lost(/l), Destoryed(/d), OnLoan(/o), Purchasing(/p)}" << endl;
	cout << "help/h : to get help" << endl;
	cout << "quit/q : to exit" << endl << endl;
}

void SystemUI::GetBorrowerUI()
{
	cout << "*****Borrower Mode*****" << endl;
	cout << "*****Input command:(command parameters)*****" << endl;
	cout << "print : to print all books" << endl;
	cout << "search [BookName]/[BookPrice]/[BookName BookPrice]  : to search book" << endl;
	cout << "borrow [BookName] : to borrow book" << endl;
	cout << "return [BookName] : to return book" << endl;
	cout << "lost [BookName] : to register lost book" << endl;
	cout << "help/h : to get help" << endl;
	cout << "quit/q : to exit" << endl << endl;
}

void SystemUI::GetAdminUI()
{
	cout << "*****Admin Mode*****" << endl;
	cout << "*****Input command:(command parameters)*****" << endl;
	cout << "add [UserName] [UserNum] [Department] [UserStatus]" << endl;
	cout << "==>UserStatus[]={ borrower(/b), keeper(/k), buyer(/bu)}" << endl;
	cout << "update [UserName] [UserNum] [Department] [UserStatus]" << endl;
	cout << "search [UserNum]" << endl;
	cout << "print : to print all user" << endl;
	cout << "help/h : to get help" << endl;
	cout << "quit/q : to exit" << endl << endl;
}
