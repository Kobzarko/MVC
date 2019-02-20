#include "BaseModel.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//*--------------------------------------------------------------------------------

BaseModel::BaseModel(string fileName) {
	this->fileName = fileName; // ��� ����� � �������
	this->dbType = HDD; // ��� �������� ���������� (�� ������������ - ��������� ��� ��������� ������ � �����)
	this->data = new map <string, int>; // ��������� ������ ��� �������� ����������
	// ���������� ����� ��� ������ � ����������� �� �������.
	// 200 - �� - ������ ���
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

bool BaseModel::save() {return this->saveToFile(); } // ��������� ������  � ����
bool BaseModel::saveToFile(){
	ofstream out(this->fileName, ios_base::out | ios_base::trunc | ios_base::binary);
	if (out.is_open()) {
		for (auto it = this->data->begin(); it != this->data->end(); ++it) { // ������� ������
			out << it->first << "\n" << it->second; // ���� ���� � ��������
			if (it != this->data->end()) { out << "\n"; } // ���� � �� ����� �� ����� - ��������� ������� ������
		}
	}
	else { // ������ ��������� �� ������
		this->errNum = "100";
		this->errMsg = " �� ���� ������� ���� �� ������";
		return false;
	}
	out.close();
	return true;
}

bool BaseModel::load() { return this->loadFromFile(); } // � ��� �� ������ ������ ������ ������ � ������
bool BaseModel::loadFromFile(){
	ifstream in(this->fileName, ios_base::in | ios_base::binary);
	if (in.is_open()){ // ���� ���� ������
		string word;
		int wordCount;
		while (!in.eof()){ // ���� �� ��  ����� �� ����� �����
			in >> word; // ������ ������ ������ (����)
			if (in.eof()) { break; } // ���� ������ ������ ������ - ���������������
			in >> wordCount; // ������ ������ ������ (��������)
			this->create(word, wordCount); // ������� ������ ������
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