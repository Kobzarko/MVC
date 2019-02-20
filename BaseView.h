#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
class BaseView
{
public:
	BaseView();
	~BaseView();


//*--------------------------------------------------------------------------------
// Msg functions
	void renderError(string* = nullptr); // ����� ����������� ��������� ��������
	void renderMsg(string* = nullptr); // ����� ����������� ��������� ��������
//	void renderMsg(char* = nullptr); //    

//*--------------------------------------------------------------------------------
// Menu functions
	void changeMenuTitle(string);
	void changeMenuTitle(const char*);

	string menuTitle;
	vector<string> menuItem;

	void addMenuItem( const char*);
	char renderMenu();

	virtual void all(map<string, int>*);
	virtual void renderNode(string *);

//*--------------------------------------------------------------------------------
// �������� ��������� ������
	virtual string* create();
	string msgKey;
	string msgVal;

//*--------------------------------------------------------------------------------
//  ��������������� ����
	string getString(string msg = "");


};

