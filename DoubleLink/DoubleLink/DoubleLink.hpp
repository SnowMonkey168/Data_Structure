//
//  DoubleLink.hpp
//  DoubleLink
//
//  Created by Frank Lee on 2018/11/21.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef DoubleLink_hpp
#define DoubleLink_hpp

#include "Node.h"

template <typename T>
class DoubleLink
{
public:
    typedef Node<T>* pointer;
public:
    DoubleLink();
    ~DoubleLink(){};
public:
    Node<T>* insert(int index, T value);
    Node<T>* insert_front(T value);
    Node<T>* insert_last(T value);
    
    Node<T>* del(int index);
    Node<T>* delete_front();
    Node<T>* delete_last();
    
    bool isEmpty();
    int size();
    
    T get(int index);
    T get_front();
    T get_last();
    Node<T>* getHead();
    
private:
    Node<T>* phead;
    int count;
private:
    Node<T>* getNode(int index);
};

#endif /* DoubleLink_hpp */
