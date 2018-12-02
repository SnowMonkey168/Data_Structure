//
//  SingleLink.cpp
//  SingleLink
//
//  Created by Frank Lee on 2018/11/21.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include <stdio.h>
#include "SingleLink.h"

template <typename T>
SingleLink<T>::SingleLink():count(0), phead(nullptr)
{
    phead = new Node<T>();
    phead->_next = nullptr;
}

template <typename T>
SingleLink<T>::~SingleLink()
{
    Node<T>* pNode = phead->_next;
    while (pNode != nullptr)
    {
        Node<T>* temp = pNode;
        pNode = pNode->_next;
        delete temp;
    }
}

template <typename T>
Node<T>* SingleLink<T>::getNode(int index)
{
    if(index > count || index < 0)
    {
        return nullptr;
    }
    int temp = 0;
    Node<T>* preNode = phead;
    while (temp < index)
    {
        temp++;
        preNode = preNode->_next;
    }
    return preNode;
}

template <typename T>
int SingleLink<T>::size()
{
    return count;
}

template <typename T>
bool SingleLink<T>::isEmpty()
{
    return count == 0;
}

template <typename T>
Node<T>* SingleLink<T>::getHead()
{
    return phead->_next;
}

template <typename T>
Node<T>* SingleLink<T>::insert(int index, T t)
{
    Node<T>* preNode = getNode(index);
    if (preNode)
    {
        Node<T>* newNode = new Node<T>(t,preNode->_next);
        preNode->_next = newNode;
        count++;
        return newNode;
    }
    return nullptr;
}

template <typename T>
Node<T>* SingleLink<T>::insert_head(T t)
{
    return insert(0, t);
}

template <typename T>
Node<T>* SingleLink<T>::insert_last(T t)
{
    return insert(count, t);
}

template <typename T>
Node<T>* SingleLink<T>::del(int index)
{
    if (isEmpty())
    {
        return nullptr;
    }
    
    Node<T>* ptrNode = getNode(index);
    Node<T>* delNode = ptrNode->_next;
    
    ptrNode->_next = delNode->_next;
    count --;
    delete delNode;
    return ptrNode->_next;
}

template <typename T>
Node<T>* SingleLink<T>::delete_head()
{
    return del(0);
}

template <typename T>
Node<T>* SingleLink<T>::delete_last()
{
    return del(count-1);
}

template <typename T>
Node<T>* SingleLink<T>::reverse_list()
{
    Node<T>* pNode = phead;
    Node<T>* pPrevious = nullptr;
    while(pNode != nullptr)
    {
        Node<T>* pNext = pNode->_next;
        if (pNext == nullptr)
        {
            phead->_next = pNode;
        }
        
        if (pPrevious == phead) {
            pNode->_next = nullptr;
        } else {
            pNode->_next = pPrevious;
        }
        pPrevious = pNode;
        pNode = pNext;
    }
    return phead;
}












