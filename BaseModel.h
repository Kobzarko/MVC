#pragma once

#include <iostream>
#include <string>
#include <map>
using namespace std;
//*--------------------------------------------------------------------------------
enum dbType { HDD = 0, MySQL, PSql, MSSql, Oracle };

class BaseModel
{
public:
	BaseModel(string fileName);
	~BaseModel();

	virtual bool save();
	virtual bool load();
	
	virtual bool saveToFile();
	virtual bool loadFromFile();


// CRUD
	//Create
	virtual bool create(string word, int wCount);
	virtual bool update(string word);

	// Read
	map<string, int>* all();
	// string* getDataByKey(string key);
	//string* getKeyByData(string data);
	// Update
	// virtual bool update(string*);  
	// Delete
	// virtual bool del(string*);


	string errNum;
	string errMsg;
	string* getLastError();


	// string* getNodeByKey(string key);
	//string* getNodeByData(string data);

	string fileName;
	map<string,int>* data;
	
	dbType dbType;

};

