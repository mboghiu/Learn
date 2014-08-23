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
        node<T>* top = nullptr;
};


template<typename T>
void stack<T>::push(const T& value)
{
    if (top == nullptr)
    {
        top = new node<T>(value);
    }
    else
    {
        auto t = new node<T>(value);
        t->next = top;
        top = t;
    }
}

template<typename T>
void stack<T>::pop()
{
    auto t = top;
    top = top->next;
    delete t;
}

template<typename T>
const T& stack<T>::peek() const
{
    return top->value;
}

template<typename T>
void stack<T>::print()
{
//    for (auto it = top; it != nullptr; it = it->next)
//        std::cout << it->value << "-->";
//    std::cout << std::endl;
}

