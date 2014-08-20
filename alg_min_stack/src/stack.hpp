#pragma once

#include <iostream>

#include "node.hpp"

template<typename T>
class stack
{
    public:
        void push(const T& value);
        void pop();
        void print();
        
        const T& peek() const;
        const T& min() const;

    private:
        node<T>* top = nullptr;
};


template<typename T>
void stack<T>::push(const T& value)
{
    if (top == nullptr)
    {
        top = new node<T>(value, value);
    }
    else
    {
        auto t = top;
        top = new node<T>(value, std::min(t->value, value));
        top->next = t;
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
const T& stack<T>::min() const
{
    return top->min;
}

template<typename T>
void stack<T>::print()
{
    for (auto it = top; it != nullptr; it = it->next)
        std::cout << it->value << "-->";
    std::cout << std::endl;
}

