#include "MenuByList.h"

MenuByList::MenuByList(string mName, initializer_list<string> list)
{
    this->mName = mName;

    size = list.size();
    this->list = new string[size];

    for (int i = 0; i < size; i++)
        this->list[i] = list.begin()[i];
}

MenuByList::~MenuByList()
{
    delete[] list;
}

int MenuByList::getChoice()
{
    system("cls");

    int selected = 0;
    while (true)
    {
        cout << "\n      " << mName << endl << endl;
        for (int i = 0; i < size; i++)
            cout << (selected == i ? "\t > " : "\t") << i + 1 << "." << list[i] << endl;
        cout << "\n (Press num or ENTER to confirm)" << endl;

        int butt = CHAR_TO_NUM(_getch()); system("cls");
        if (butt >= 0 && butt < size) selected = butt;
        else if (butt == CHAR_TO_NUM(ENTER_BUTT)) return selected;
    }
}

void MenuByList::enterPause()
{
    while (true) if (_getch() == ENTER_BUTT) break;
}