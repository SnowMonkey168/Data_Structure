//
//  main.cpp
//  Stack
//
//  Created by Frank Lee on 2018/11/30.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include <iostream>
#include "ArrayStack.hpp"
#include "LinkStack.hpp"
#include "QueueViaStacks.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // 基于数组的栈实现
    ArrayStack<int> p(15);
    for (int i = 1; i <= 15; i++)
    {
        p.push(i*10);
    }
    cout<<"The size of stack is "<<p.size()<<endl;
    cout<<"The stack is empty: "<<p.isEmpty()<<endl;
    int topValue;
    if (p.top(topValue)) {
        cout<<"The top element is "<<topValue<<endl;
    } else {
        cout<<"The top element is null."<<endl;
    }
    cout<<"The all elements are "<<endl;
    while(!p.isEmpty())
    {
        int element;
        if (p.pop(element)) {
            cout<<element<<" ";
        } else {
            cout<<"ArrayStack p has no any element."<<endl;
        }
    }
    cout<<endl;
    cout<<endl;
    
    // 基于单链表的栈实现
    LinkStack<string> lstack;
    lstack.push("Hamamatsu");
    lstack.push("Juphoon");
    lstack.push("RongCloud");
    
    cout<<"The size of LinkStack is "<<lstack.size()<<endl;
    string topElement;
    if (lstack.top(topElement)) {
        cout<<"The top element of LinkStack is "<<topElement<<endl;
    } else {
        cout<<"The top element of LinkStack does not exist."<<endl;
    }
    while(!lstack.isEmpty()) {
        lstack.pop(topElement);
    };
    cout<<"The size of LinkStack is "<<lstack.size()<<" after popping all LinkStack elements."<<endl<<endl;
    
    
    // 用两个栈实现队列
    LinkStack<int> stack1, stack2;
    QueueViaStacks<int> queue(stack1, stack2);
    int queueValue;
    for (int i = 1; i <= 7; i++)
    {
        queue.push(i * 10);
    }
    queue.pop(queueValue);
    queue.push(1314);
    queue.push(1212);
    cout<<"The QueueViaStacks elements:"<<endl;
    while(queue.pop(queueValue))
    {
        cout<<queueValue<<" ";
    };
    cout<<endl<<endl;
    
    return 0;
}
