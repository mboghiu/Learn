#pragma once

#include <iostream>
#include <stack>

#include "node.hpp"

template<typename T>
class stack
{
    public:
        void push(const T& value);
        void pop();
        void print();
        
        const T& peek() const;

    private:
        node<T>* current = nullptr;
        std::stack<node<T>*> tops;
        size_t threshold = 3;
};


template<typename T>
void stack<T>::push(const T& value)
{
    if (current == nullptr)
    {
        current = new node<T>(value);
    }
    else if (current->size() == threshold)
    {
        tops.push(current);
        current = new node<T>(value);
    }
    else
    {
        auto t = new node<T>(value);
        t->next = current;
        current = t;
    }
}

template<typename T>
void stack<T>::pop()
{
    auto t = current;
    current = current->next;
    if (current == nullptr)
        current = tops.top();
    delete t;
}

template<typename T>
const T& stack<T>::peek() const
{
    return current->value;
}

template<typename T>
void stack<T>::print()
{
//    for (auto it = top; it != nullptr; it = it->next)
//        std::cout << it->value << "-->";
//    std::cout << std::endl;
}

