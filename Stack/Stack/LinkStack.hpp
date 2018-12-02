//
//  LinkStack.hpp
//  Stack
//
//  Created by Frank Lee on 2018/12/1.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef LinkStack_hpp
#define LinkStack_hpp

template <typename T>
struct Node
{
    T value;
    Node<T>* next;
};

template <typename T>
class LinkStack
{
public:
    LinkStack();
    ~LinkStack();
    
    bool isEmpty();
    int size();
    void push(T t);
    bool pop(T& t);
    bool top(T& t);
private:
    Node<T>* phead;
    int count;
};

template <typename T>
LinkStack<T>::LinkStack()
{
    phead = new Node<T>();
    count = 0;
}

template <typename T>
LinkStack<T>::~LinkStack()
{
    while (phead->next != nullptr)
    {
        Node<T>* pnode = phead->next;
        phead->next = pnode->next;
        delete pnode;
    }
    phead = nullptr;
}

template <typename T>
int LinkStack<T>::size()
{
    return count;
}

template <typename T>
bool LinkStack<T>::isEmpty()
{
    return count == 0;
}

template <typename T>
void LinkStack<T>::push(T t)
{
    Node<T>* pNode = new Node<T>();
    pNode->value = t;
    pNode->next = phead->next;
    phead->next = pNode;
    count++;
}

template <typename T>
bool LinkStack<T>::pop(T& t)
{
    if (phead->next != nullptr) {
        Node<T>* pDel = phead->next;
        phead->next = pDel->next;
        t = pDel->value;
        delete pDel;
        count--;
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool LinkStack<T>::top(T& t)
{
    if (phead->next != nullptr) {
        t = phead->next->value;
        return true;
    } else {
        return false;
    }
}

#endif /* LinkStack_hpp */
