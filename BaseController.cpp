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
void BaseController::buildMenu(){ // �������� ����������� ����

	this->view->addMenuItem("1. ��������� ���������� �� �����");
	this->view->addMenuItem("2. �������� ���������� � ����");
	this->view->addMenuItem("3. �������� ����������");
}
//*--------------------------------------------------------------------------------
bool BaseController::doStandartMenuSwitch(char userChoise){ // ��������� ������ ������������
	bool ret = false; // ���� �� ��������� ����������� ��������
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
		this->view->all(this->model->all()); // ����� ��� ������ �� ������ (all) � �������� �� �� ����������� �� ����� �� ������
		ret = true; break;
	}
	return ret;
}

//*--------------------------------------------------------------------------------
void BaseController::renderMenu(){
	char userChoise = '\0'; // ���� ����� �������� ����� ������������. ����� ���� � �� ��������
	while (true)
	{
		userChoise = this->view->renderMenu(); // �������� ������� ������ - ������� ����
		if (userChoise == '0') { return; } // ���� ������������ ������ 0 - ����� �� �������
		if (!this->doStandartMenuSwitch(userChoise)){
			// ������������� ����
		}

	}
}