//
//  QueueViaStacks.hpp
//  Stack
//
//  Created by Frank Lee on 2018/12/1.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef QueueViaStacks_hpp
#define QueueViaStacks_hpp

#include "LinkStack.hpp"
#include <iostream>

template <typename T>
class QueueViaStacks
{
public:
    QueueViaStacks(LinkStack<T>&, LinkStack<T>&);
    ~QueueViaStacks();
    void push(T t);
    bool pop(T& t);
private:
    LinkStack<T> &stack1,&stack2;
};

template <typename T>
QueueViaStacks<T>::QueueViaStacks(LinkStack<T>& s1, LinkStack<T>& s2):stack1(s1),stack2(s2){}

template <typename T>
QueueViaStacks<T>::~QueueViaStacks()
{
    std::cout<<"Execute ~QueueViaStacks()"<<std::endl;
}

template <typename T>
void QueueViaStacks<T>::push(T t)
{
    stack1.push(t);
}

template <typename T>
bool QueueViaStacks<T>::pop(T& t)
{
    if (stack1.size() <= 0 && stack2.size() <= 0)
    {
        return false;
    }
    int temp;
    if (stack2.size() <= 0)
    {
        while(stack1.pop(temp))
        {
            stack2.push(temp);
        };
    }
    return stack2.pop(t);
}
#endif /* QueueViaStacks_hpp */
