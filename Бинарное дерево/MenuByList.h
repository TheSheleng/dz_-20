#pragma once

#include <string>
#include <iostream>
#include <conio.h>

#define ENTER_BUTT 13
#define CHAR_TO_NUM(num) (num - 49) 

using namespace std;

class MenuByList
{
	int size;
	string mName;
	string* list;

public:
	MenuByList(string mName, initializer_list<string> list);
	~MenuByList();

	int getChoice();

	static void enterPause();
};

