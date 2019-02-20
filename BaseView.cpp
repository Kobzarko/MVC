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
	this->addMenuItem("0. Вернуться"); // В обязательном порядке мы обрабатываем выход - значит во всех меню убдет этот пункт
	this->menuTitle = "Базовое меню"; // Этой надписи мы теоретически нигде не увидим
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
	cout << "\n+--------------- \t" << this->menuTitle << "\t --------------+\n"; // Вывод заголовка меню
	copy(this->menuItem.begin(), this->menuItem.end(), ostream_iterator<string>(cout, "\n")); // Копирую весь массив от начала до конца в поток cout с разделителем \n
	return _getch(); // Вернуть выбор пользователя
}

//*--------------------------------------------------------------------------------
void BaseView::renderError(string* err){ // Вывод информации об ошибке
	cout << "\n+--------------- Error --------------------+";
	cout << "\n Что-то пошло не так";
	cout << "\n+------------------------------------------+\n";
}

//*--------------------------------------------------------------------------------
void BaseView::renderMsg(string* msg ){ // Вывод некого сообщения
	cout << "\n+--------------- Msg ----------------------+";
	cout << "\n Все хорошо";
	cout << "\n+------------------------------------------+\n";
}

//*--------------------------------------------------------------------------------
void BaseView::all(map<string, int>* data){ // Выводит на экран полученное дерево
	cout << "\n";
	for (auto it = data->begin(); it != data->end(); ++it) { // Загружает в переменную it ноду дерева, начиная с первой, и работает пока не дойдет до конца
		cout << it->first << " : " << it->second << endl; // Выводит на экран ключ (first) и значение (second)
	}
	cout << "\n";
}

//*--------------------------------------------------------------------------------
// Выводит 1 элемент списка
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
// Задать вопрос пользователю и получить от него ответ в виде строки
string  BaseView::getString(string msg){
	if (msg == "") { msg = "Введите чегото"; };
	cout << "\n+--------------- Введите --------------------+";
	cout << "\n " << msg;
	cout << "\n+------------------------------------------+\n";
	string ret;
	cin >> ret;
	return ret;
}