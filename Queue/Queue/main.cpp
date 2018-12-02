//
//  main.cpp
//  Queue
//
//  Created by Frank Lee on 2018/12/1.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include <iostream>
#include "LoopQueue.hpp"
#include "LinkQueue.hpp"
#include "StackViaQueues.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // 基于数组的循环队列实现
    LoopQueue<string> queue(7);
    queue.push("one");
    queue.push("two");
    queue.push("three");
    queue.push("four");
    queue.push("five");
    queue.push("six");
    queue.push("seven");
    queue.push("eight");
    queue.push("nine");
    cout<<"The size of queue is "<<queue.size()<<endl;
    string value;
    while (queue.pop(value))
    {
        cout<<value<<endl;
    };
    cout<<endl;
    
    // 基于链表的队列实现
    LinkQueue<int> lqueue;
    for (int i = 1; i <= 12; i++)
    {
        lqueue.push(i * 10);
    }
    cout<<"The size of lqueue is "<<lqueue.size()<<endl;
    int value1;
    while(lqueue.pop(value1)) {
        cout<<value1<<" ";
    }
    cout<<endl;
    cout<<"The size of lqueue is "<<lqueue.size()<<" after popping up all elements."<<endl;
    cout<<endl;
    
    // 使用两个队列实现一个栈
    LinkQueue<int> q1, q2;
    StackViaQueues<int> stack(q1, q2);
    for (int i = 1; i <= 5; i++)
    {
        stack.push(i * 10);
    }
    
    cout<<"The origin StackViaQueues:"<<endl;
    int stackValue;
    while (stack.pop(stackValue)) {
        cout<<stackValue<<" ";
    }
    cout<<endl;
    
    for (int i = 1; i <= 5; i++)
    {
        stack.push(i * 10);
    }
    stack.pop(stackValue);
    stack.push(911);
    cout<<"The converted StackViaQueues:"<<endl;
    while (stack.pop(stackValue)) {
        cout<<stackValue<<" ";
    }
    cout<<endl<<endl;
    return 0;
}
