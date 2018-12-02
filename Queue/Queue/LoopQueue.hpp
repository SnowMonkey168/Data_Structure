//
//  LoopQueue.hpp
//  基于数组的循环队列实现
//
//  Created by Frank Lee on 2018/12/1.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef LoopQueue_hpp
#define LoopQueue_hpp

template <typename T>
class LoopQueue
{
public:
    LoopQueue(int c = 10);
    ~LoopQueue();
    
    bool isEmpty();
    int size();
    bool push(T t);
    bool pop(T& t);
    
private:
    int capacity;
    int begin;
    int end;
    T* queue;
};

template <typename T>
LoopQueue<T>::LoopQueue(int c):capacity(c), begin(0), end(0), queue(nullptr)
{
    queue = new T[capacity];
}

template <typename T>
LoopQueue<T>::~LoopQueue()
{
    delete[] queue;
}

template <typename T>
bool LoopQueue<T>::isEmpty()
{
    if (begin == end)
        return true;
    return false;
}

template <typename T>
int LoopQueue<T>::size()
{
    return (end - begin + capacity) % capacity;
}

template <typename T>
bool LoopQueue<T>::push(T t)
{
    if ((end + 1)%capacity == begin)
    {
        return false;
    }
    queue[end] = t;
    end = (end + 1) % capacity;
    return true;
}

template <typename T>
bool LoopQueue<T>::pop(T& t)
{
    if (begin == end) {
        return false;
    }
    t = queue[begin];
    begin = (begin + 1)%capacity;
    return true;
}

#endif /* LoopQueue_hpp */
