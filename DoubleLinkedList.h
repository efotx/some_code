#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

template <class T>
struct DoubleLinkedNode
{
    explicit DoubleLinkedNode (T value, DoubleLinkedNode *prev = nullptr, DoubleLinkedNode *next = nullptr);

    T data;
    DoubleLinkedNode *prev;
    DoubleLinkedNode *next;
};  

template <class T>
class DoubleLinkedList
{
private:
    DoubleLinkedNode<T> *head;
    size_t msize;

public:
    DoubleLinkedList();

    DoubleLinkedList(size_t size, T value);

    DoubleLinkedList(const DoubleLinkedList<T> &other);

    ~DoubleLinkedList();

    void push_back(T value);

    void pop_back();

    void push_front(T value);

    void pop_front();

    T at(size_t index);

    T operator[] (size_t index);
    T operator[] (size_t index) const;
    DoubleLinkedList<T> & operator+= (const DoubleLinkedList<T> &rhs);

    size_t size();
};


template <typename T>
DoubleLinkedList<T> operator+ (const DoubleLinkedList<T> &lhs, const DoubleLinkedList<T> &rhs);

#include "DoubleLinkedList.hpp"

#endif // DOUBLELINKEDLIST_H_INCLUDED