//
//  BSTree.cpp
//  BSTree
//
//  Created by Frank Lee on 2018/12/2.
//  Copyright © 2018 Frank Lee. All rights reserved.
//

#include <iostream>
#include "BSTree.hpp"

template <typename T>
BSTree<T>::BSTree():root(nullptr){}

template <typename T>
BSTree<T>::~BSTree()
{
    std::cout<<"Execute ~BSTree()"<<std::endl;
    destroy(root);
}

template <typename T>
void BSTree<T>::insert(T key)
{
    BSNode<T>* pparent = nullptr;
    BSNode<T>* pnode = root;
    
    while (pnode != nullptr)  //寻找合适的插入位置
    {
        pparent = pnode;
        if (key > pnode->value)
            pnode = pnode->rchild;
        else if (key < pnode->value)
            pnode = pnode->lchild;
        else
            break;
    }
    
    pnode = new BSNode<T>(key);
    if (pparent == nullptr)   //如果是空树,则新节点为根
    {
        root = pnode;
    }
    else
    {
        if (key > pparent->value)
            pparent->rchild = pnode;
        else
            pparent->lchild = pnode;
    }
    pnode->parent = pparent;  //指明新节点的父节点
}

/**
 通过“迭代”的方式，查找指定元素的节点
 */
template <typename T>
BSNode<T>* BSTree<T>::search_iterator(T key)
{
    BSNode<T>* pnode = root;
    while (pnode != nullptr)
    {
        if (key == pnode->value)
            return pnode;
        if (key > pnode->value)
            pnode = pnode->rchild;
        else
            pnode = pnode->lchild;
    }
    return nullptr;
}

/**
 通过“递归”的方式，查找指定元素的节点
 */
template <typename T>
BSNode<T>* BSTree<T>::search_recursion(T key)
{
    return search(root, key);
}

template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* &pnode, T key)
{
    if (pnode == nullptr)
        return nullptr;
    if (pnode->value == key)
        return pnode;
    std::cout<<"-->"<<pnode->value<<" ";//输出查找路径
    return (key > pnode->value) ? search(pnode->rchild, key) : search(pnode->lchild, key);
}

/**
 删除指定节点
 删除二叉排序树的某个节点有三种情况：
 1.被删除节点同时有左子树与右子树:处理方式是用该节点的前驱节点替换该节点
 2.被删除节点只有左子树或只有右子树:用子树替换被删节点
 3.被删除节点没有子树:直接删除节点
 */
template <typename T>
void BSTree<T>::remove(T key)
{
    remove(root, key);
}

template <typename T>
void BSTree<T>::remove(BSNode<T>* pnode, T key)
{
    if (pnode != nullptr)
    {
        if (pnode->value == key)
        {
            BSNode<T>* pdel = nullptr;
            
            if (pnode->lchild == nullptr || pnode->rchild == nullptr)
                pdel = pnode;//情况2&3:被删节点只有左子树或右子树，或没有孩子
            else
                pdel = predecessor(pnode);//情况1:被删节点同时有左右子树，则删除该节点的前驱
            
            //[关键点]此时,被删节点 pdel 只有一个孩子(或没有孩子):保存该孩子指针
            BSNode<T>* pchild = nullptr;
            if (pdel->lchild != nullptr)
                pchild = pdel->lchild;
            else
                pchild = pdel->rchild;
            
            //让孩子指向被删除节点的父节点
            if (pchild != nullptr)
                pchild->parent = pdel->parent;
            
            if (pdel->parent == nullptr)
                root = pchild; //如果要删除的节点是头节点，注意更改root的值
            else if (pdel->parent->lchild == pdel)
                pdel->parent->lchild = pchild;
            else
                pdel->parent->rchild = pchild;
            
            if (pnode->value != pdel->value)
                pnode->value = pdel->value;
            delete pdel;
        }
        else if (key > pnode->value)
        {
            remove(pnode->rchild, key);
        }
        else
        {
            remove(pnode->lchild, key);
        }
    }
}


/**
 寻找前驱节点
 */
template <typename T>
BSNode<T>* BSTree<T>::predecessor(BSNode<T> *pnode)
{
    if (pnode->lchild != nullptr)
    {
        pnode = pnode->lchild;
        while (pnode->rchild != nullptr)
        {
            pnode = pnode->rchild;
        }
        return pnode;
    }
    
    BSNode<T>* pparent = pnode->parent;
    while (pparent != nullptr && pparent->lchild == pnode)
    {
        pnode = pparent;
        pparent = pparent->parent;
    }
    return pparent;
}

/**
 寻找后继节点
 */
template <typename T>
BSNode<T>* BSTree<T>::successor(BSNode<T> *pnode)
{
    if(pnode->rchild != nullptr)
    {
        pnode = pnode->rchild;
        while (pnode->lchild != nullptr)
        {
            pnode = pnode->lchild;
        }
        return pnode;
    }
    
    BSNode<T>* pparent = pnode->parent;
    while (pparent != nullptr && pparent->rchild == pnode)
    {
        pnode = pparent;
        pparent = pparent->parent;
    }
    return pparent;
}

/**
 中序遍历算法
 */
template <typename T>
void BSTree<T>::inOrder()
{
    inOrder(root);
    std::cout<<std::endl;
}

template <typename T>
void BSTree<T>::inOrder(BSNode<T>* &p) //此处不涉及对 p 的修改(写操作), 故使用 &p
{
    if (p != nullptr)
    {
        inOrder(p->lchild);
        std::cout<<p->value<<" ";
        inOrder(p->rchild);
    }
}

/**
 前序遍历算法
 */
template <typename T>
void BSTree<T>::preOrder()
{
    preOrder(root);
    std::cout<<std::endl;
}

template <typename T>
void BSTree<T>::preOrder(BSNode<T>* &p)
{
    if (p != nullptr)
    {
        std::cout<<p->value<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

/**
 后序遍历算法
 */
template <typename T>
void BSTree<T>::postOrder()
{
    postOrder(root);
    std::cout<<std::endl;
}

template <typename T>
void BSTree<T>::postOrder(BSNode<T>* &p)
{
    if (p != nullptr)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        std::cout<<p->value<<" ";
    }
}

template <typename T>
bool BSTree<T>::search_minimum(T& t)
{
    if (root == nullptr)
        return false;
    BSNode<T>* p = root;
    while (p->lchild != nullptr)
    {
        p = p->lchild;
    }
    t = p->value;
    return true;
}

template <typename T>
bool BSTree<T>::search_maximum(T& t)
{
    if (root == nullptr)
        return false;
    BSNode<T>* p = root;
    while (p->rchild != nullptr)
    {
        p = p->rchild;
    }
    t = p->value;
    return true;
}

template <typename T>
void BSTree<T>::destroy()
{
    destroy(root);
    std::cout<<"Destroy BSTress"<<std::endl;
}

template <typename T>
void BSTree<T>::destroy(BSNode<T>* &p)
{
    if (p != nullptr)
    {
        if(p->lchild != nullptr)
            destroy(p->lchild);
        if(p->rchild != nullptr)
            destroy(p->rchild);
        delete p;
        p = nullptr;
    }
}
