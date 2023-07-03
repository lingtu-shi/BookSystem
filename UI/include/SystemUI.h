/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: UI.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */
#pragma once
//UI Mode
#define DEFAULT_MODE 0
#define BORROWER_MODE 1
#define KEEPER_MODE 2
#define BUYER_MODE 3
#define ADMIN_MODE 4

//UI Command
#define NO_PARAM 1
#define ONE_PARAM 2
#define TWO_PARAM 3
#define ADD_BOOK_COM_NUM 8
#define SET_BOOK_STATE_COM_NUM 4
#define ADD_USER_COM_NUM 5
#define UPDATE_USER_COM_NUM 5

using namespace std;

class SystemUI
{
public:
	void GetUI();
	void GetBuyerUI();
	void GetKeeperUI();
	void GetBorrowerUI();
	void GetAdminUI();

private:

};
