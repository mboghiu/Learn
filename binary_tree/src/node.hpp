#pragma once

template<typename T>
struct Node
{
    Node() :
        have(false),
        next(nullptr)
    { }

    Node(const T& data) :
        data(data),
        have(true),
        next(nullptr)
    { }

    Node(const T& data, Node* next) :
        data(data),
        have(true),
        next(next)
    { }

    T data;
    bool have;
    Node* next;
};
