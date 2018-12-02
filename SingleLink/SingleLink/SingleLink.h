//
//  SingleLink.h
//  SingleLink
//
//  Created by Frank Lee on 2018/11/20.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef SingleLink_h
#define SingleLink_h

#include "Node.h"

template <typename T>
class SingleLink
{
public:
    typedef Node<T>* pointer;
    SingleLink();
    ~SingleLink();
    
    int size();
    bool isEmpty();
    
    Node<T>* insert(int index, T t);
    Node<T>* insert_head(T t);
    Node<T>* insert_last(T t);
    
    Node<T>* del(int index);
    Node<T>* delete_head();
    Node<T>* delete_last();
    
    T get(int index);
    T get_head();
    T get_last();
    
    Node<T>* getHead();
    Node<T>* reverse_list(); //翻转链表
    
private:
    int count;
    Node<T>* phead;
    
private:
    Node<T>* getNode(int index);
};

#endif /* SingleLink_h */
