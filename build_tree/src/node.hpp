#pragma once

/////// binary tree node

struct node
{
    node(int v) :
        data(v),
        left(nullptr),
        right(nullptr)
    { }
    
    int data;
    node* left;
    node* right;
};
