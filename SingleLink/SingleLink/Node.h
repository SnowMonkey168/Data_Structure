//
//  Node.h
//  SingleLink
//
//  Created by Frank Lee on 2018/11/20.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef Node_h
#define Node_h
template <typename T>
class Node
{
public:
    T _value;
    Node* _next;
public:
    Node() = default;
    Node(T value, Node* next):_value(value), _next(next) {}
};

#endif /* Node_h */
