#include "BaseController.h"

#include <iostream>
#include <string>
using namespace std;
//*--------------------------------------------------------------------------------


BaseController::BaseController(){
}


BaseController::~BaseController(){
}

//*--------------------------------------------------------------------------------
void BaseController::buildMenu(){ // Создание конкретного меню

	this->view->addMenuItem("1. Загрузить статистику из файла");
	this->view->addMenuItem("2. Записать статистику в файл");
	this->view->addMenuItem("3. Показать статистику");
}
//*--------------------------------------------------------------------------------
bool BaseController::doStandartMenuSwitch(char userChoise){ // Обработка выбора пользователя
	bool ret = false; // Была ли выполнена стандартная операция
	switch (userChoise)
	{
	case '1':
		if (!this->model->load()) { this->view->renderError(this->model->getLastError()); }
		else { this->view->renderMsg(this->model->getLastError()); };
		ret = true;	break;
	case '2':
		if (!this->model->save()) { this->view->renderError(this->model->getLastError()); } 
		else { this->view->renderMsg(this->model->getLastError()); };
		ret = true;	break;
	case '3':
		this->view->all(this->model->all()); // Взять все данные из модели (all) и передать их на отображение на экран во вьюшку
		ret = true; break;
	}
	return ret;
}

//*--------------------------------------------------------------------------------
void BaseController::renderMenu(){
	char userChoise = '\0'; // Сюда будет загружен выбор пользователя. Можно было и не обнулять
	while (true)
	{
		userChoise = this->view->renderMenu(); // Передача команды вьюшке - вывести меню
		if (userChoise == '0') { return; } // Если пользователь выбрал 0 - выйти из функции
		if (!this->doStandartMenuSwitch(userChoise)){
			// нестандартное меню
		}

	}
}