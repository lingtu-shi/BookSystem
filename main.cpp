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
#include "UserManager.h"

using namespace std;
void GetUI();
int main()
{
	BookManager bookManager;
	UserManager userManager;
	string input;
	GetUI();
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
		if (command[0] == "badd")
		{
			if (command.size() != 6 || atof(command[2].c_str()) == 0)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			res = bookManager.AddBook(command);
		}
		else if (command[0] == "bprint")
		{
			if (command.size() != 1)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			bookManager.PrintAllBook(bookManager.GetBookMap());
		}
		else if (command[0] == "bsearch")
		{
			if (command.size() != 2 && command.size() != 3)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			bookManager.SearchBook(command[1]);
		}
		else if (command[0] == "bsort")
		{
			if (command.size() != 1)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			bookManager.SortBook();
		}
		else if (command[0] == "bclassify")
		{
			if (command.size() != 1)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			bookManager.ClassifyBook();
		}
		else if (command[0] == "uadd")
		{
			if (command.size() != 4 || atof(command[2].c_str()) == 0)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			res = userManager.AddUser(command);
		}
		else if (command[0] == "uupdate")
		{
			if (command.size() != 4 || atol(command[2].c_str()) == 0)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			res = userManager.UpdateUser(command);
		}
		else if (command[0] == "usearch")
		{
			if (command.size() != 2 && atol(command[1].c_str()) == 0)
			{
				cout << "Input Error!" << endl;
				continue;
			}
			userManager.SearchUser(atol(command[1].c_str()));
		}
		else if (command[0] == "help" || command[0] == "h")
		{
			GetUI();
			continue;
		}
		else if (command[0] == "quit" || command[0] == "q")
		{
			break;
		}
		else
		{
			cout << "Input Error!" << endl;
		}
	}
	return 0;
}

void GetUI()
{
	cout << "*****Input command:(command parameters)*****" << endl;
	cout << "badd [BookName] [BookPrice] [BookNum] [Author] [Pulishing house]" << endl;
	cout << "bprint : to print all books" << endl;
	cout << "bsearch [BookName/BookPrice/BookName BookPrice]  : to search book" << endl;
	cout << "bsort : to sort book map" << endl;
	cout << "bclassify : to divided into three categories by book price(~50,50~100,100~)" << endl;
	cout << "uadd [UserName] [UserNum] [Department]" << endl;
	cout << "uupdate [UserName] [UserNum] [Department]" << endl;
	cout << "usearch [UserNum]" << endl;
	cout << "help/h : to get help" << endl;
	cout << "quit/q : to exit" << endl << endl;
}
