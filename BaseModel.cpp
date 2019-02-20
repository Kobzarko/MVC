#include "BaseModel.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//*--------------------------------------------------------------------------------

BaseModel::BaseModel(string fileName) {
	this->fileName = fileName; // Имя файла с данными
	this->dbType = HDD; // Тип хранения информации (не используется - применили для понимание модели в целом)
	this->data = new map <string, int>; // Выделение памяти для хранения информации
	// Подготовка полей для работы с сообщениями об ошибках.
	// 200 - ОК - ошибок нет
	this->errMsg = "OK";
	this->errNum = "200";
}


BaseModel::~BaseModel() {
}


bool BaseModel::update(string word){
	auto it = this->data->find(word);
	if (it != this->data->end()) {
		it->second++;
	}
	else {
		this->data->insert(pair<string, int>(word, 1)); 
	}
	return true;
}

bool BaseModel::create(string word, int wCount){
	this->data->insert(pair<string, int>(word, wCount));
	return true;
}

map<string, int>* BaseModel::all(){ return this->data; }

bool BaseModel::save() {return this->saveToFile(); } // Сохарнить именно  в файл
bool BaseModel::saveToFile(){
	ofstream out(this->fileName, ios_base::out | ios_base::trunc | ios_base::binary);
	if (out.is_open()) {
		for (auto it = this->data->begin(); it != this->data->end(); ++it) { // Перебор дерева
			out << it->first << "\n" << it->second; // Пишу ключ и значение
			if (it != this->data->end()) { out << "\n"; } // Если я не дошел до конца - поставить перенос строки
		}
	}
	else { // Запись сообщения об ошибке
		this->errNum = "100";
		this->errMsg = " Не могу открыть файл на запись";
		return false;
	}
	out.close();
	return true;
}

bool BaseModel::load() { return this->loadFromFile(); } // У нас на данный момент только работа с файлом
bool BaseModel::loadFromFile(){
	ifstream in(this->fileName, ios_base::in | ios_base::binary);
	if (in.is_open()){ // Если файл открыт
		string word;
		int wordCount;
		while (!in.eof()){ // Пока мы не  дошли до конца файла
			in >> word; // Читаем первую строку (ключ)
			if (in.eof()) { break; } // Если дальше читать нечего - останавливаемся
			in >> wordCount; // Читаем вторую строку (значение)
			this->create(word, wordCount); // Создаем запись данных
		}
	}
	else {
		return false;
	}
	in.close();
	return true;
}

string* BaseModel::getLastError(){
	string* ret = new string[2];
	ret[0] = this->errNum;
	ret[1] = this->errMsg;
	return ret;
}

//string* BaseModel::getDataByKey(string key) {
//	for (auto it = this->data->begin(); it != this->data->end(); ++it)
//		if (it->first == key) return &it->second;
//	return nullptr;
//}
//
//
//string* BaseModel::getNodeByKey(string key) {
//	for (auto it = this->data->begin(); it != this->data->end(); ++it)
//		if (it->first == key)
//		{
//			string *s = new string[2];
//			s[0] = it->first;
//			s[1] = it->second;
//			return s;
//		}
//	return nullptr;
//}
//
//string* BaseModel::getNodeByData(string data) {
//
//}