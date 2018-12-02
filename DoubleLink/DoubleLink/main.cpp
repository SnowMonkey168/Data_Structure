//
//  main.cpp
//  DoubleLink
//
//  Created by Frank Lee on 2018/11/21.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include <iostream>
#include "DoubleLink.hpp"
#include "DoubleLink.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    DoubleLink<int> dlink;
    for (int i = 0; i < 10; i++)
    {
        dlink.insert(0, i * 10);
    }
    dlink.insert_front(131);
    dlink.insert(2, 361);
    dlink.insert_last(711);
    dlink.insert_last(456);
    dlink.delete_last();
    dlink.del(3);
    
    DoubleLink<int>::pointer ptr = dlink.getHead();
    ptr = ptr->next_ptr;
    while (ptr != dlink.getHead())
    {
        cout<<ptr->_value<<endl;
        ptr = ptr->next_ptr;
    }
    return 0;
}
