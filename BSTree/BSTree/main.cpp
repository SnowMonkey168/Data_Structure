//
//  main.cpp
//  BSTree
//
//  Created by Frank Lee on 2018/12/2.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include <iostream>
#include "BSTree.hpp"
#include "BSTree.cpp"
using namespace std;
int main(int argc, const char * argv[]) {
    BSTree<int> t;
    t.insert(62);
    t.insert(58);
    t.insert(47);
    t.insert(51);
    t.insert(35);
    t.insert(37);
    t.insert(88);
    t.insert(73);
    t.insert(99);
    t.insert(93);
    t.insert(95);
    
    cout<<endl<<"中序遍历:"<<endl;
    t.inOrder();
    
    cout<<"The path of finding a certain element:"<<endl;
    t.search_recursion(75);
    cout<<endl;
    
    int max,min;
    if (t.search_minimum(min))
        cout<<"最小值:"<<min<<endl;
    if (t.search_maximum(max))
        cout<<"最大值:"<<max<<endl;
    
    t.remove(99);
    if (t.search_maximum(max))
        cout<<"最大值:"<<max<<endl;
    
    //t.destroy();
    return 0;
}
