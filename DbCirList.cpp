#include <iostream>
#include "DbCirList.h"
using namespace std;

template <class T>
DbCirList<T>::DbCirList()
{
    Node *head = new Node;
    Node *tail = new Node;
    head->left = tail;
    head->right = tail;
    tail->left = head;
    tail->right = head;
    first = head;
}
template <class T>
DbCirList<T>::DbCirList(const DbCirList &c)
{
    Node *head = new Node;
    Node *tail = new Node;
    head->left = tail;
    head->right = tail;
    tail->left = head;
    tail->right = head;
    first = head;

    // copy nodes of c into *this
    typename DbCirList<T>::Iterator i = c.begin();
    i++;
    for (; i != c.end(); i++)
    {
        InsertBack(*i);
    }
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
void DbCirList<T>::InsertBack(const T s)
{ // insert a node to right of the list
    Node *p = new Node(s);
    p->left = first->left->left;
    p->right = first->left;
    first->left->left->right = p;
    first->left->left = p;
}

template <class T>
void DbCirList<T>::InsertFront(const T s)
{
    Node *p = new Node(s);
    p->left = first;
    p->right = first->right;
    first->right = p;
    first->right->left = p;
}

template <class T>
void DbCirList<T>::RemoveBack()
{
    if (first->left->left == first)
        throw "list is empty";
    Node *x = first->left->left;
    x->left->right = x->right;
    x->right->left = x->left;
    delete x;
}

template <class T>
void DbCirList<T>::RemoveFront()
{
    if (first->left->left == first)
        throw "list is empty";
    Node *x = first->right;
    x->left->right = x->right;
    x->right->left = x->left;
    delete x;
}