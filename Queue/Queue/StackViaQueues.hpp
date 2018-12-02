//
//  StackViaQueues.hpp
//  Queue
//
//  Created by Frank Lee on 2018/12/1.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef StackViaQueues_hpp
#define StackViaQueues_hpp

#include <iostream>
#include "LinkQueue.hpp"

template <typename T>
class StackViaQueues
{
public:
    StackViaQueues(LinkQueue<T>&, LinkQueue<T>&);
    ~StackViaQueues();
    void push(T t);
    bool pop(T& t);
    
private:
    LinkQueue<T> &queue1, &queue2;
};

template <typename T>
StackViaQueues<T>::StackViaQueues(LinkQueue<T>& q1, LinkQueue<T>& q2):queue1(q1), queue2(q2){}

template <typename T>
StackViaQueues<T>::~StackViaQueues<T>()
{
    std::cout<<"Execute ~StackViaQueues"<<std::endl;
}

template <typename T>
void StackViaQueues<T>::push(T t)
{
    if (queue2.isEmpty()) {
        queue1.push(t);
    } else {
        queue2.push(t);
    }
}

template <typename T>
bool StackViaQueues<T>::pop(T &t)
{
    if (queue1.isEmpty() && queue2.isEmpty())
    {
        return false;
    }
    
    T temp;
    if(!queue2.isEmpty())
    {
        int length = queue2.size();
        while(length > 1)
        {
            if(queue2.pop(temp))
            {
                queue1.push(temp);
                length--;
            } else {
                break;
            }
        }
        if (queue2.pop(t)) {
            return true;
        } else {
            return false;
        }
    }
    
    if (!queue1.isEmpty())
    {
        int length = queue1.size();
        while (length > 1) {
            if (queue1.pop(temp)) {
                queue2.push(temp);
                length--;
            } else {
                break;
            }
        }
        if (queue1.pop(t)) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}


#endif /* StackViaQueues_hpp */
