//
//  LinkQueue.hpp
//  Queue
//
//  Created by Frank Lee on 2018/12/1.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef LinkQueue_hpp
#define LinkQueue_hpp

#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node<T>* next;
};

template <typename T>
class LinkQueue
{
public:
    LinkQueue();
    ~LinkQueue();
    
    bool isEmpty();
    int size();
    bool pop(T& t);
    void push(T t);
    
private:
    Node<T>* pHead;
    Node<T>* pEnd;
    int count;
};

template <typename T>
LinkQueue<T>::LinkQueue():pHead(nullptr),pEnd(nullptr),count(0)
{
    pHead = new Node<T>();
    pEnd = pHead;
    //std::cout<<"Execute LinkQueue() = "<<this<<std::endl;
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
    while (pHead->next != nullptr)
    {
        Node<T>* pNode = pHead->next;
        pHead->next = pNode->next;
        delete pNode;
    }
    pHead = nullptr;
    //std::cout<<"Execute ~LinkQueue() = "<<this<<std::endl;
}

template <typename T>
bool LinkQueue<T>::isEmpty()
{
    return count == 0;
}

template <typename T>
int LinkQueue<T>::size()
{
    return count;
}

template <typename T>
bool LinkQueue<T>::pop(T& t)
{
    if (count == 0) {
        return false;
    }
    Node<T>* pNode = pHead->next;
    pHead->next = pNode->next;
    t = pNode->value;
    delete pNode;
    count--;
    return true;
}

template <typename T>
void LinkQueue<T>::push(T t)
{
    if (count == 0)
    {
        pEnd = pHead;
    }
    Node<T>* pNode = new Node<T>();
    pNode->value = t;
    pEnd->next = pNode;
    pEnd = pNode;
    count++;
}
#endif /* LinkQueue_hpp */
