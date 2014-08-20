#pragma once

template<typename T>
struct node
{
    node(T v) : value(v), left(nullptr), right(nullptr) { }
    node(T v, node* l, node* r) : value(v), left(l), right(r) { }
    T value;
    node* left;
    node* right;
};
