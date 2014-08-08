#pragma once

template<typename T>
struct Node
{
    Node(const T& data) :
        data(data),
        left(nullptr),
        right(nullptr)
    { }

    T data;
    Node* left;
    Node* right;
};
