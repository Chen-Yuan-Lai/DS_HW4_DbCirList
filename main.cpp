#include <iostream>
#include "DbCirList.h"
#include "DbCirList.cpp"
using namespace std;

int main()
{
    DbCirList<int> a;
    while (1)
    {
        int option;
        int num;
        cout << "1) InsertBack 2) InsertFront "
             << "3) RemoveBack 4) RemoveFront "
             << "5) Output(Forward) 6) Output(Backward): ";
        cin >> option;
        cout << endl;
        if (option == 1)
        {
            cout << "Enter input number: " << endl;
            cin >> num;
            a.InsertBack(num);
            cout << endl;
        }
        else if (option == 2)
        {
            cout << "Enter input number: " << endl;
            cin >> num;
            a.InsertFront(num);
            cout << endl;
        }
        else if (option == 3)
        {
            cout << "Enter number: " << endl;
        }
    }

    a.InsertBack(2);
    a.InsertBack(3);
    a.InsertBack(4);
    a.InsertBack(5);

    DbCirList<int> b = a;
    for (DbCirList<int>::Iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    for (DbCirList<int>::Iterator i = b.begin(); i != b.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}