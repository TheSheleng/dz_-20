#include <conio.h>
#include <iostream>

#include "Functions.h"

using namespace std;

#define BUFF_SIZE 15

void Insert(Tree& tree)
{
    system("cls");
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->GetEnglish();

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->GetRussian();

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    system("cls");
    tree.Print(tree.GetRoot());
    system("pause");;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[BUFF_SIZE] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[BUFF_SIZE] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    system("pause");
}

void TreeSave(const Tree& tree)
{
    const char EXTENSION[] = ".txt";
    char fName[BUFF_SIZE + 4]{};

    cout << "Enter an file name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(fName, BUFF_SIZE);
    strcat_s(fName, EXTENSION), fName;

    ofstream file;
    file.open(fName);


    if (file.is_open())
    {
        if (tree.GetRoot() != nullptr)
        {
            Node* temp = tree.Min(tree.GetRoot());
            
            while (temp != nullptr)
            {
                file << temp->GetEnglish() << "\t\t" << temp->GetRussian() << endl;
                temp = tree.Next(temp);
            }
        }

        file.close();
    }
}

void EditNode(const Tree& tree)
{
    char key[BUFF_SIZE]{};
    char nStr[BUFF_SIZE]{};
    Node* temp = nullptr;

    while (temp == nullptr)
    {
        cout << "Enter a kay: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(key, BUFF_SIZE);
        temp = tree.Search(tree.GetRoot(), key);
    }

    cout << "Enter a new str eng: ";
    cin.getline(nStr, BUFF_SIZE);
    for (int i = 0; nStr[i] != '\0'; i++)
        temp->GetEnglish()[i] = nStr[i];

    cout << "Enter a new str rus: ";
    cin.getline(nStr, BUFF_SIZE);
    for (int i = 0; nStr[i] != '\0'; i++)
        temp->GetRussian()[i] = nStr[i];

}
