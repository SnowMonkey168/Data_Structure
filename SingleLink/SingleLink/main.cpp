//
//  main.cpp
//  SingleLink
//
//  Created by Frank Lee on 2018/11/20.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include <iostream>
#include "SingleLink.h"
#include "SingleLink.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    SingleLink<int> link;
    for(int i = 0; i < 10; i++)
    {
        link.insert(i, i*10);
    }
    
    link.insert_head(361);
    link.insert_head(911);
    link.insert_last(271);
    link.delete_last();
    cout<< "link.size() = "<<link.size()<<endl;
    
    SingleLink<int>:: pointer ptr = link.getHead();
    while(ptr != nullptr)
    {
        cout<<ptr->_value<<" ";
        ptr = ptr->_next;
    }
    cout<<endl;
    
    cout<<"翻转列表"<<endl;
    link.reverse_list();
    //link.insert_head(711);
    //link.insert_last(101);
    link.delete_last();
    ptr = link.getHead();
    cout<< "link.size() = "<<link.size()<<endl;
    while(ptr != nullptr)
    {
        cout<<ptr->_value<<" ";
        ptr = ptr->_next;
    }
    cout<<endl;
    
    return 0;
}
