#pragma once

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
class Stack
{
    public:
        Stack() = default;
        Stack(const T& value, Stack* const next) :
            m_data(value),
            m_have(true),
            m_next(next),
            m_top(this)
        { }

        void Push(const T& value);

        void Print();
        std::string ToString();

    private:
        T m_data;
        bool m_have = false;
        Stack* const m_next = nullptr;
        Stack* m_top = this;
};

template<typename T>
void Stack<T>::Push(const T& value)
{
    if (!m_top->m_have)
    {
        m_top->m_data = value;
        m_top->m_have = true;
    }
    else
    {
        m_top = new Stack<T>(value, m_top);
    }
}

template<typename T>
void Stack<T>::Print()
{
    std::cout << ToString() << std::endl;
}

template<typename T>
std::string Stack<T>::ToString()
{
    std::stringstream ss;
    for (Stack* i = m_top; i != nullptr; i = i->m_next)
        ss << (i->m_have ? i->m_data : -1) << " | ";
    return std::move(ss.str());
}
