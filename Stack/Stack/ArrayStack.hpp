//
//  ArrayStack.h
/*
 count 为栈的元素数量，capacity为栈的容量，count<=capacity，当栈满的时候，count = capacity。
 本实现中不支持栈的动态扩容，栈满的时候无法再插入元素。栈的容量在定义栈的时候就需要指定，默认的栈容量为10。
 */
//  Created by Frank Lee on 2018/11/30.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef ArrayStack_h
#define ArrayStack_h

template<typename T>
class ArrayStack
{
public:
    ArrayStack(int s = 10); //默认的栈容量为 10
    ~ArrayStack();
    
public:
    bool top(T& t); //获取栈顶元素
    void push(T t); //压栈操作
    bool pop(T& t); //弹栈操作
    bool isEmpty(); //判空操作
    int size(); //求栈的大小
    
private:
    int count; //栈的元素数量
    int capacity; //栈的容量
    T* array; //底层为数组
};

template <typename T>
ArrayStack<T>::ArrayStack(int s):count(0), capacity(s), array(nullptr)
{
    array = new T[capacity];
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
    if (array)
    {
        delete[] array;
        array = nullptr;
    }
}

template <typename T>
bool ArrayStack<T>::isEmpty()
{
    return count == 0;
}

template <typename T>
int ArrayStack<T>::size()
{
    return count;
}

template <typename T>
void ArrayStack<T>::push(T t)
{
    if (count != capacity)
    {
        array[count++] = t;
    }
}

template <typename T>
bool ArrayStack<T>::pop(T& t)
{
    if (count != 0) {
        t = array[--count];
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool ArrayStack<T>::top(T& t)
{
    if (count != 0) {
        t = array[count - 1];
        return true;
    } else {
        return false;
    }
}
#endif /* ArrayStack_h */
