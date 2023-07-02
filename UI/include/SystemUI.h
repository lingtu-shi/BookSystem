/*
 * @Author: Administrator
 * @Date: July 2023
 * @FilePath: UI.h
 * Copyright (c) 2023 by BAOSIGHT,All Rights Reserved. 
 * @Description: 
 */
#pragma once
#define DEFAULT_MODE 0
#define BORROWER_MODE 1
#define KEEPER_MODE 2
#define BUYER_MODE 3
#define ADMIN_MODE 4
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
