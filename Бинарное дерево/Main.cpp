#include <conio.h>
#include <iostream>

#include "Functions.h"
#include "Tree.h"
#include "MenuByList.h"

static int a;

using namespace std;

int main()
{
	Tree tree;

	enum
	{
		MM_INSERT,
		MM_REMOVE,
		MM_SEARCH,
		MM_EDIT,
		MM_PRINT,
		MM_SAVE,
		MM_EXIT
	};

	MenuByList mainMenu("Main menu:", {
		"Insert node",
		"Remove node",
		"Search node",
		"Edit Node",
		"Print node",
		"Save file",
		"Exit"
	});
	
	bool exit = false;
	while (!exit)
	{
		switch (mainMenu.getChoice())
		{
		case MM_INSERT: Insert(tree); break;
		case MM_REMOVE: Remove(tree); break;
		case MM_SEARCH: Search(tree); break;
		case MM_EDIT: EditNode(tree); break;
		case MM_PRINT: Print(tree); break;
		case MM_SAVE: TreeSave(tree); break;
		case MM_EXIT: exit = true; break;

		default: break;
		}
	}
}