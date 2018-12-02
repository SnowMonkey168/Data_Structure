//
//  DoubleLink.cpp
//  DoubleLink
//
//  Created by Frank Lee on 2018/11/21.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include "DoubleLink.hpp"

template <typename T>
DoubleLink<T>::DoubleLink():count(0)
{
    phead = new Node<T>(0, nullptr, nullptr);
    phead->next_ptr = phead;
    phead->pre_ptr = phead;
  
}

template <typename T>
Node<T>* DoubleLink<T>::getHead()
{
    return phead;
}

template <typename T>
int DoubleLink<T>::size()
{
    return count;
}

template <typename T>
bool DoubleLink<T>::isEmpty()
{
    return count == 0;
}

template <typename T>
T DoubleLink<T>::get(int index)
{
    Node<T>* node = getNode(index);
    return node->_value;
}

template <typename T>
T DoubleLink<T>::get_front()
{
    return phead->next_ptr->_value;
}

template <typename T>
T DoubleLink<T>::get_last()
{
    return phead->pre_ptr->_value;
}

template <typename T>
Node<T>* DoubleLink<T>::getNode(int index)
{
    if (index >= count || index < 0)
        return nullptr;
    if (index <= count / 2) //如果在前半部分
    {
        Node<T>* pnode = phead->next_ptr;
        while (index)
        {
            pnode = pnode->next_ptr;
            index--;
        }
        return pnode;
    }
    
    index = count - 1 - index; //如果在后半部分
    Node<T>* pnode = phead->pre_ptr;
    while (index) {
        pnode = pnode->pre_ptr;
        index--;
    }
    return pnode;
}

template <typename T>
Node<T>* DoubleLink<T>::insert_front(T value)
{
    Node<T>* newNode = new Node<T>(value, phead, phead->next_ptr);
    phead->next_ptr->pre_ptr = newNode;
    phead->next_ptr = newNode;
    count++;
    return newNode;
}

template <typename T>
Node<T>* DoubleLink<T>::insert_last(T value)
{
    Node<T>* newNode = new Node<T>(value, phead->pre_ptr, phead);
    phead->pre_ptr->next_ptr = newNode;
    phead->pre_ptr = newNode;
    count++;
    return newNode;
}

/**
 将节点插到index位置之前
 */
template <typename T>
Node<T>* DoubleLink<T>::insert(int index, T value)
{
    if(index==0)
        return insert_front(value);
    
    Node<T>* pNode = getNode(index);
    if(pNode == nullptr)
        return nullptr;
    Node<T>* newNode = new Node<T>(value, pNode->pre_ptr, pNode);
    pNode->pre_ptr->next_ptr = newNode;
    pNode->pre_ptr = newNode;
    count++;
    return newNode;
}

/**
 删除链表第一个节点
 @return 返回删除后链表第一个节点
 */
template <typename T>
Node<T>* DoubleLink<T>::delete_front()
{
    if (count == 0) {
        return nullptr;
    }
    Node<T>* pnode = phead->next_ptr;
    phead->next_ptr = pnode->next_ptr;
    pnode->next_ptr->pre_ptr = phead;
    delete pnode;
    count--;
    return phead->next_ptr;
}

/**
 删除链表的末尾节点
 @return 返回删除后链表尾部元素
 */
template <typename T>
Node<T>* DoubleLink<T>::delete_last()
{
    if (count == 0) {
        return nullptr;
    }
    Node<T>* pnode = phead->pre_ptr;
    pnode->pre_ptr->next_ptr = phead;
    phead->pre_ptr = pnode->pre_ptr;
    delete pnode;
    count--;
    return phead->pre_ptr;
}

template <typename T>
Node<T>* DoubleLink<T>::del(int index)
{
    if (index == 0)
        return delete_front();
    if (index == count-1)
        return delete_last();
    if (index < 0 || index >= count)
        return nullptr;
    Node<T>* pnode = getNode(index);
    pnode->pre_ptr->next_ptr = pnode->next_ptr;
    pnode->next_ptr->pre_ptr = pnode->pre_ptr;
    
    Node<T>* ptemp = pnode->pre_ptr;
    delete pnode;
    count--;
    return ptemp;
}














