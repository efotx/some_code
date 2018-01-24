#ifndef DOUBLELINKEDLIST_HPP_INCLUDED
#define DOUBLELINKEDLIST_HPP_INCLUDED

#include "DoubleLinkedList.h"

template <class T>
DoubleLinkedNode<T>::DoubleLinkedNode (T value, DoubleLinkedNode *prev, DoubleLinkedNode *next) : data(value), prev(prev), next(next) {}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), msize(0) {}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(size_t size, T value) : head(new DoubleLinkedNode<T>(value)), msize(size)
{
    DoubleLinkedNode<T> *tempHead = head; //указатель для перемещения по списку
    for (size_t i = 1; i < msize; ++i)
    {
        DoubleLinkedNode<T> *temp = tempHead; //вспомогательный для определения prev
        tempHead -> next = new DoubleLinkedNode<T>(value, temp);
        tempHead = tempHead -> next;

    }
}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> &other) : head (new DoubleLinkedNode<T>(other.head -> data)), msize(other.msize)
{
    DoubleLinkedNode<T> *otherData = other.head; //указатель для перемещения по other
    DoubleLinkedNode<T> *tempHead = head;
    for (size_t i = 1; i < msize; ++i)
    {
        DoubleLinkedNode<T> *temp = tempHead;
        otherData = otherData -> next;
        tempHead -> next = new DoubleLinkedNode<T>(otherData -> data, temp);
        tempHead = tempHead -> next;
    }
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while (head)
    {
        DoubleLinkedNode<T> *temp = head;
        head = head -> next;
        delete temp;
    }
}

template <class T>
void DoubleLinkedList<T>::push_back(T value)
{
    if (msize == 0)
    {
        head = new DoubleLinkedNode<T>(value);
        ++msize;
        return;
    }
    DoubleLinkedNode<T> *tempHead = head;
    DoubleLinkedNode<T> *temp = nullptr;
    for (size_t i = 0; i < (msize - 1); ++i)
    {
        temp = tempHead;
        tempHead = tempHead -> next;
    }
    tempHead -> next = new DoubleLinkedNode<T>(value, temp);
    ++msize;
}

template <class T>
void DoubleLinkedList<T>::pop_back()
{
    if (msize == 0)
    {
        return;
    }
    DoubleLinkedNode<T> *tempHead = head;
    for (size_t i = 0; i < (msize - 1); ++i)
    {
        tempHead = tempHead -> next;
    }
    delete tempHead;
    --msize;
}

template <class T>
void DoubleLinkedList<T>::push_front(T value)
{
    if (msize == 0)
    {
        head = new DoubleLinkedNode<T>(value);
        ++msize;
        return;
    }
    DoubleLinkedNode<T> *temp = new DoubleLinkedNode<T>(value);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    ++msize;
}

template <class T>
void DoubleLinkedList<T>::pop_front()
{
    if (msize == 0)
    {
        return;
    }
    DoubleLinkedNode<T> *temp = head;
    head = head -> next;
    delete temp;
    --msize;
}

template <class T>
T DoubleLinkedList<T>::at(size_t index)
{
    if ( index >= msize || index < 0)
    {
        throw std::overflow_error("out of size");
    }
    DoubleLinkedNode<T> *tempHead = head;
    for (size_t i = 0; i < index; ++i)
    {
        tempHead = tempHead -> next;
    }
    return tempHead -> data;
}

template <class T>
size_t DoubleLinkedList<T>::size()
{
    return msize;
}

template <typename T>
T DoubleLinkedList<T>::operator[] (size_t index)
{
    return at(index);
}

template <typename T>
T DoubleLinkedList<T>::operator[] (size_t index) const
{
    DoubleLinkedNode<T> *tempHead = head;
        for (size_t i = 0; i < index; ++i)
        {
            tempHead = tempHead -> next;
        }
        return tempHead -> data;
}

template <typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator+= (const DoubleLinkedList<T> &rhs)
{
    DoubleLinkedNode<T> *runner = head;
    for ( ; runner -> next != nullptr; runner = runner -> next)
    {}

    DoubleLinkedList<T> temp(rhs);
    runner -> next = temp.head;
    temp.head = nullptr;
    runner -> next -> prev = runner;
    msize += rhs.msize;

    return *this;
}

template <typename T>
DoubleLinkedList<T> operator+ (const DoubleLinkedList<T> &lhs, const DoubleLinkedList<T> &rhs)
{
    DoubleLinkedList<T> out(lhs);
    out += rhs;
    return out;
}

#endif // DOUBLELINKEDLIST_HPP_INCLUDED