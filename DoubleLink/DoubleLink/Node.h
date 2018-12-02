//
//  Node.h
//  DoubleLink
//
//  Created by Frank Lee on 2018/11/21.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <typename T>
class Node {
public:
    T _value;
    Node<T>* pre_ptr;//指向直接前驱的指针
    Node<T>* next_ptr;//指向直接后继的指针
public:
    Node() = default;
    Node(T value, Node<T>* preptr, Node<T>* nextptr):_value(value), pre_ptr(preptr), next_ptr(nextptr){}
};

#endif /* Node_h */
