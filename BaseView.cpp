#include "BaseView.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <iterator>
using namespace std;
//*--------------------------------------------------------------------------------


BaseView::BaseView(){
	this->addMenuItem("0. ���������"); // � ������������ ������� �� ������������ ����� - ������ �� ���� ���� ����� ���� �����
	this->menuTitle = "������� ����"; // ���� ������� �� ������������ ����� �� ������
}


BaseView::~BaseView()
{
}


//*--------------------------------------------------------------------------------
void BaseView::changeMenuTitle(string menuTitle){ this->menuTitle = menuTitle; }
void BaseView::changeMenuTitle(const char* menuTitle){ this->menuTitle = menuTitle; }
void BaseView::addMenuItem(const char* menuItem){this->menuItem.push_back(menuItem);}

//*--------------------------------------------------------------------------------
char BaseView::renderMenu(){
	cout << "\n+--------------- \t" << this->menuTitle << "\t --------------+\n"; // ����� ��������� ����
	copy(this->menuItem.begin(), this->menuItem.end(), ostream_iterator<string>(cout, "\n")); // ������� ���� ������ �� ������ �� ����� � ����� cout � ������������ \n
	return _getch(); // ������� ����� ������������
}

//*--------------------------------------------------------------------------------
void BaseView::renderError(string* err){ // ����� ���������� �� ������
	cout << "\n+--------------- Error --------------------+";
	cout << "\n ���-�� ����� �� ���";
	cout << "\n+------------------------------------------+\n";
}

//*--------------------------------------------------------------------------------
void BaseView::renderMsg(string* msg ){ // ����� ������ ���������
	cout << "\n+--------------- Msg ----------------------+";
	cout << "\n ��� ������";
	cout << "\n+------------------------------------------+\n";
}

//*--------------------------------------------------------------------------------
void BaseView::all(map<string, int>* data){ // ������� �� ����� ���������� ������
	cout << "\n";
	for (auto it = data->begin(); it != data->end(); ++it) { // ��������� � ���������� it ���� ������, ������� � ������, � �������� ���� �� ������ �� �����
		cout << it->first << " : " << it->second << endl; // ������� �� ����� ���� (first) � �������� (second)
	}
	cout << "\n";
}

//*--------------------------------------------------------------------------------
// ������� 1 ������� ������
void BaseView::renderNode(string *node) {
	cout << node[0] << " : " << node[1] << endl;
}

//*--------------------------------------------------------------------------------
string*  BaseView::create(){
	char* tmp = new char[1000];
	string *ret = new string[2];
	cout << "\n " << this->msgKey;
	// cin.ignore();
	gets_s(tmp, 1000);
	ret[0] = tmp;
	cout << " " << this->msgVal;
	// cin.ignore();
	gets_s(tmp, 1000);
	ret[1] = tmp;
	return ret;
}

//*--------------------------------------------------------------------------------
// ������ ������ ������������ � �������� �� ���� ����� � ���� ������
string  BaseView::getString(string msg){
	if (msg == "") { msg = "������� ������"; };
	cout << "\n+--------------- ������� --------------------+";
	cout << "\n " << msg;
	cout << "\n+------------------------------------------+\n";
	string ret;
	cin >> ret;
	return ret;
}