#pragma once

template<typename T>
struct node
{
    node(const T& v) : value(v), next(nullptr) { }

    size_t size() const
    {
        size_t s = 1;
        for (node* t = next; t != nullptr; t = t->next)
            s++;
        return s;
    }
    
    T value;
    node* next;
};
