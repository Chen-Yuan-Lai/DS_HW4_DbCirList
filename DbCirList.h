#ifndef DBCIRLIST_H
#define DBCIRLIST_H
using namespace std;

template <class T>
class DbCirList
{
    class Node;

public:
    DbCirList();
    // copy constructor
    DbCirList(const DbCirList &c);
    ~DbCirList();
    void InsertBack(const T s);
    void InsertFront(const T s);
    void RemoveBack();
    void RemoveFront();

    class Iterator;
    Iterator begin() const { return Iterator(first); }
    Iterator end() const { return Iterator(first->left); }

    template <class U>
    friend ostream &operator<<(ostream &os, DbCirList &s);
    // biderectonal iterator
    class Iterator
    {
    public:
        Iterator(Node *startNode = 0) : current(startNode) {}

        T &operator*() const { return current->data; }
        T *operator->() const { return &current->data; }

        Iterator &operator++()
        {
            current = current->right;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator old = *this;
            current = current->right;
            return old;
        }

        Iterator &operator--()
        {
            current = current->left;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator old = *this;
            current = current->left;
            return old;
        }
        bool operator!=(const Iterator right) const
        {
            return current != right.current;
        }
        bool operator==(const Iterator right) const
        {
            return current == right.current;
        }

    private:
        Node *current;
    };

private:
    class Node
    {
    public:
        T data;
        Node *left, *right;
        Node(T element = 0) : data(element), left(0), right(0) {}
    };
    Node *first;
};
#endif