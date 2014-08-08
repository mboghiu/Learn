#pragma once

template<typename T>
struct Node
{
    Node(const T& data) :
        data(data),
        next(nullptr)
    { }

    T data;
    Node* left;
    Node* right;
};
