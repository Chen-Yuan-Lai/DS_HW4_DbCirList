#include <iostream>
#include "DbCirList.h"
using namespace std;

template <class T>
DbCirList<T>::DbCirList()
{
    Node *head = new Node;
    head->left = head;
    head->right = head;
    first = head;
}

template <class T>
DbCirList<T>::~DbCirList()
{
    first->left->right = 0;
    first->left = 0;
    Node *cur = first;
    while (cur != 0)
    {
        Node *temp = cur;
        cur = cur->right;
        delete temp;
    }
}

template <class T>
void DbCirList<T>::Insert(T s)
{ // insert a node to right of the list
    Node p = new Node(s);
    p->left = first->left;
    p->right = first->left->right;
    first->left->right->left = p;
    first->left->right = p;
}
