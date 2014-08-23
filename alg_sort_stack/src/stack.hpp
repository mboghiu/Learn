#pragma once

#include <stack>
#include <sstream>
#include <string>

#include "node.hpp"

template<typename T>
class stack
{
    public:
        void push(const T& value);
        void pop();
        void sort();

        std::string print();
        
        const T& peek() const;

        bool empty() const;

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
bool stack<T>::empty() const
{
    return top == nullptr;
}

template<typename T>
void stack<T>::sort()
{
    stack<T>* t = new stack<T>();
    
    while (!empty())
    {
        auto val = peek(); pop();

        while (!t->empty() && t->peek() > val)
        {
            push(t->peek()); t->pop();
        }
        t->push(val);
    }

    while(!t->empty())
    {
        push(t->peek());
        t->pop();
    }
}

template<typename T>
std::string stack<T>::print()
{
    std::stringstream ss;
    for (auto it = top; it != nullptr; it = it->next)
        ss << it->value << "-->";
    ss << "|" << std::endl;
    return std::move(ss.str());
}

