#pragma once

struct Node
{
    Node(int data) :
        data(data),
        left(nullptr),
        right(nullptr)
    { }

    int data;
    Node* left;
    Node* right;
};
