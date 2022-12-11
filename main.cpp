#include <iostream>
#include "DbCirList.h"
#include "DbCirList.cpp"
using namespace std;

int main()
{
    DbCirList<int> a;
    a.InsertBack(1);
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