//
//  BSTree.hpp
//  BSTree
//
//  Created by Frank Lee on 2018/12/2.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#ifndef BSTree_hpp
#define BSTree_hpp

template <typename T>
struct BSNode
{
    BSNode() = default;
    BSNode(T t):value(t), lchild(nullptr), rchild(nullptr){}
    
    T value;
    BSNode<T>* lchild;
    BSNode<T>* rchild;
    BSNode<T>* parent;
};

template <typename T>
class BSTree
{
public:
    typedef BSNode<T>* pointer;
    BSTree();
    ~BSTree();
    
    void preOrder();    //前序遍历二叉树
    void inOrder();     //中序遍历二叉树
    void postOrder();   //后序遍历二叉树
    //void layerOrder();//层序遍历二叉树
    
    BSNode<T>* search_recursion(T key); //递归地进行查找
    BSNode<T>* search_iterator(T key);  //迭代地进行查找
    
    bool search_maximum(T&);
    bool search_minimum(T&);
    
    BSNode<T>* successor(BSNode<T>* x); //查找指定节点的后继节点
    BSNode<T>* predecessor(BSNode<T>* x);//查找指定节点的前驱节点
    
    void insert(T key); //插入指定值节点
    void remove(T key); //删除指定值节点
    void destroy();     //销毁二叉树
    
private:
    BSNode<T>* root; //根节点
private:
    BSNode<T>* search(BSNode<T>* &p, T key);
    void remove(BSNode<T>* p, T key);
    void preOrder(BSNode<T>* &p);
    void inOrder(BSNode<T>* &p);
    void postOrder(BSNode<T>* &p);
    void destroy(BSNode<T>* &p);
};

#endif /* BSTree_hpp */
