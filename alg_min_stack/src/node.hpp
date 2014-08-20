#pragma once

template<typename T>
struct node
{
    node(const T& v, const T& min) : value(v), next(nullptr), min(min) { }
    
    T value;
    node* next;
    T min;
};
