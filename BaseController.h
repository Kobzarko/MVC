#pragma once
#include "BaseView.h"
#include "BaseModel.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//*--------------------------------------------------------------------------------


class BaseController
{
public:
	BaseController();
	~BaseController();

	virtual void renderMenu();
	virtual void buildMenu();
	bool doStandartMenuSwitch(char); // ��������� ������������ ����

protected:
	vector<string> menuUser;
	BaseModel* model;
	BaseView* view;
};

