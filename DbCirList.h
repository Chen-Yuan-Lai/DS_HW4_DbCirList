#ifndef DBCIRLIST_H
#define DBCIRLIST_H
using namespace std;

template <class T>
class DbCirList
{
    class Node;

public:
    DbCirList();
    ~DbCirList();
    void Insert(T s);
    void Remove(T s);

    class Iterator;
    Iterator begin();
    Iterator end();

    template <class U>
    friend ostream &operator<<(ostream &os, DbCirList &s);

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
        bool operator!=(const);

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