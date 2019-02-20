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
	void renderError(string* = nullptr); // Вывод результатов обработки операции
	void renderMsg(string* = nullptr); // Вывод результатов обработки операции
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
// Создание эелемента списка
	virtual string* create();
	string msgKey;
	string msgVal;

//*--------------------------------------------------------------------------------
//  Вспомогательные окна
	string getString(string msg = "");


};

