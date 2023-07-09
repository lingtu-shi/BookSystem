/*
 * @Author: Administrator
 * @Date: June 2023
 * @FilePath: main.cpp
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: Book system entry
 */

#include <sstream>
#include <vector>
#include <iostream>

#include "BookManager.h"
#include "BookService.h"
#include "UserManager.h"

#include "BookBuyer.h"
#include "BookKeeper.h"
#include "Borrower.h"

#include "SystemUI.h"

using namespace std;
int main()
{
	SystemUI ui;
	BookManager* bookManager = new BookManager();
	UserManager* userManager = new UserManager();
	BookService bookService(bookManager, userManager);
	BookBuyer bookBuyer(&bookService);
	BookKeeper bookKeeper(&bookService);
	Borrower borrower(&bookService);
	int mode = DEFAULT_MODE;
	long long enterUser = -1;
	ui.GetUI();
	string input;
	while (true)
	{
		input = "";
		while (input == "")
		{
			cout << "$";
			getline(cin, input); // 读取一行输入
		}

		vector<string> command; // 用于存放切割后的字符串
		istringstream iss(input); // 创建字符串流对象，并初始化为读取input
		string parameter;
		while (iss >> parameter)
		{
			command.push_back(parameter); // 将切割后的字符串添加到vector中
		}
		bool res;
		if (mode == DEFAULT_MODE)
		{
			if (command[0] == "b" || command[0] == "borrower")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				mode = BORROWER_MODE;
				cout << "Enter User Num:" << endl;
			}
			else if (command[0] == "k" || command[0] == "keeper")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				mode = KEEPER_MODE;
				cout << "Enter User Num:" << endl;
			}
			else if (command[0] == "bu" || command[0] == "buyer")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				mode = BUYER_MODE;
				cout << "Enter User Num:" << endl;
			}
			else if (command[0] == "a" || command[0] == "admin")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				mode = ADMIN_MODE;
				ui.GetAdminUI();
			}
			else if (command[0] == "help" || command[0] == "h")
			{
				ui.GetUI();
				continue;
			}
			else if (command[0] == "quit" || command[0] == "q")
			{
				break;
			}
			else
			{
				cout << "Input Error!" << endl;
				continue;
			}
		}
		else if (mode == BORROWER_MODE)
		{
			if (enterUser == -1)
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					cout << "Enter User Num:" << endl;
					continue;
				}
				enterUser = atoi(command[0].c_str());
				if (bookService.GetUserManager()->MatchUser(enterUser, "borrower"))
				{
					ui.GetBorrowerUI();
					continue;
				}
				else
				{
					cout << "WARN: user not found!" << endl;
					enterUser = -1;
					mode = DEFAULT_MODE;
					ui.GetUI();
					continue;
				}
			}
			if (command[0] == "print")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				borrower.PrintBook();
			}
			if (command[0] == "printbookmap")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				borrower.PrintBookMap();
			}
			else if (command[0] == "search")
			{
				if (command.size() != ONE_PARAM && command.size() != TWO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				borrower.SearchBook(command[1]);
			}
			else if (command[0] == "borrow")
			{
				if (command.size() != ONE_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				//TODO: Apply Keeper
				borrower.SetBookState(command[1], BookState::mAvailable, BookState::mOnLoan);
			}
			else if (command[0] == "return")
			{
				if (command.size() != ONE_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				borrower.SetBookState(command[1], BookState::mOnLoan, BookState::mAvailable);
			}
			else if (command[0] == "lost")
			{
				if (command.size() != ONE_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				borrower.SetBookState(command[1], BookState::mOnLoan, BookState::mLost);
			}
			else if (command[0] == "help" || command[0] == "h")
			{
				ui.GetBorrowerUI();
				continue;
			}
			else if (command[0] == "quit" || command[0] == "q")
			{
				mode = DEFAULT_MODE;
				enterUser = -1;
				ui.GetUI();
				continue;
			}
			else
			{
				cout << command[0] << endl;
				cout << "Input Error!" << endl;
			}
		}
		else if (mode == KEEPER_MODE)
		{
			if (enterUser == -1)
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					cout << "Enter User Num:" << endl;
					continue;
				}
				enterUser = atoi(command[0].c_str());
				if (bookService.GetUserManager()->MatchUser(enterUser, "keeper"))
				{
					ui.GetKeeperUI();
					continue;
				}
				else
				{
					cout << "WARN: user not found!" << endl;
					enterUser = -1;
					mode = DEFAULT_MODE;
					ui.GetUI();
					continue;
				}
			}
			if (command[0] == "print")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookKeeper.PrintBook();
			}
			if (command[0] == "printbookmap")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookKeeper.PrintBookMap();
			}
			else if (command[0] == "search")
			{
				if (command.size() != ONE_PARAM && command.size() != TWO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookKeeper.SearchBook(command[1]);
			}
			else if (command[0] == "sort")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookKeeper.SortBook();
			}
			else if (command[0] == "classify")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookKeeper.ClassifyBook();
			}
			else if (command[0] == "setstate")
			{
				if (command.size() != SET_BOOK_STATE_COM_NUM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookKeeper.SetBookState(command[1], bookService.SetBookState(command[2]), bookService.SetBookState(command[3]));
			}
			else if (command[0] == "help" || command[0] == "h")
			{
				ui.GetKeeperUI();
				continue;
			}
			else if (command[0] == "quit" || command[0] == "q")
			{
				mode = DEFAULT_MODE;
				enterUser = -1;
				ui.GetUI();
				continue;
			}
			else
			{
				cout << "Input Error!" << endl;
			}
		}
		else if (mode == BUYER_MODE)
		{
			if (enterUser == -1)
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					cout << "Enter User Num:" << endl;
					continue;
				}
				enterUser = atoi(command[0].c_str());
				if (bookService.GetUserManager()->MatchUser(enterUser, "buyer"))
				{
					ui.GetBuyerUI();
					continue;
				}
				else
				{
					cout << "WARN: user not found!" << endl;
					enterUser = -1;
					mode = DEFAULT_MODE;
					ui.GetUI();
					continue;
				}
			}
			if (command[0] == "add")
			{
				if (command.size() != ADD_BOOK_COM_NUM || atof(command[2].c_str()) == 0)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				res = bookBuyer.AddBook(command);
			}
			else if (command[0] == "print")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookBuyer.PrintBook();
			}
			else if (command[0] == "printbookmap")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookBuyer.PrintBookMap();
			}
			else if (command[0] == "printBS")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookBuyer.PrintBookBS();
			}
			else if (command[0] == "search")
			{
				if (command.size() != ONE_PARAM && command.size() != TWO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				bookBuyer.SearchBook(command[1]);
			}
			else if (command[0] == "help" || command[0] == "h")
			{
				ui.GetBuyerUI();
				continue;
			}
			else if (command[0] == "quit" || command[0] == "q")
			{
				mode = DEFAULT_MODE;
				enterUser = -1;
				ui.GetUI();
				continue;
			}
			else
			{
				cout << "Input Error!" << endl;
			}
		}
		else if (mode == ADMIN_MODE)
		{
			if (command[0] == "add")
			{
				if (command.size() != ADD_USER_COM_NUM || atof(command[2].c_str()) == 0)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				res = userManager->AddUser(command);
			}
			else if (command[0] == "update")
			{
				if (command.size() != UPDATE_USER_COM_NUM || atol(command[2].c_str()) == 0)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				res = userManager->UpdateUser(command);
			}
			else if (command[0] == "search")
			{
				if (command.size() != ONE_PARAM && atol(command[1].c_str()) == 0)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				userManager->SearchUser(atol(command[1].c_str()));
			}
			else if (command[0] == "del")
			{
				if (command.size() != ONE_PARAM && atol(command[1].c_str()) == 0)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				userManager->DelUser(atol(command[1].c_str()));
			}
			else if (command[0] == "print")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				userManager->PrintUser();
			}
			else if (command[0] == "printbu")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				userManager->PrintBuyer();
			}
			else if (command[0] == "printk")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				userManager->PrintKeeper();
			}
			else if (command[0] == "printb")
			{
				if (command.size() != NO_PARAM)
				{
					cout << "Input Error!" << endl;
					continue;
				}
				userManager->PrintBorrower();
			}
			else if (command[0] == "help" || command[0] == "h")
			{
				ui.GetAdminUI();
				continue;
			}
			else if (command[0] == "quit" || command[0] == "q")
			{
				mode = DEFAULT_MODE;
				ui.GetUI();
				continue;
			}
			else
			{
				cout << "Input Error!" << endl;
			}
		}
	}
	delete bookManager;
	delete userManager;
	return 0;
}
