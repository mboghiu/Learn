#pragma once

#include <iostream>

template<typename T>
class Stack
{
    public:
        Stack() = default;
        Stack(const T& value, Stack* const next) :
            m_have(true),
            m_next(next),
            m_data(value)
        { }

        Stack* Push(const T& value);

        void Print();

    private:
        bool m_have = false;
        Stack* const m_next = nullptr;
        T m_data;
};

template<typename T>
Stack<T>* Stack<T>::Push(const T& value)
{
    if (!m_have)
    {
        m_data = value;
        m_have = true;
        return this;
    }
    else
    {
        auto s = new Stack<T>(value, this);
        return s; 
    }
}

template<typename T>
void Stack<T>::Print()
{
    for (Stack* i = this; i != nullptr; i = i->m_next)
        std::cout << (i->m_have ? i->m_data : -1) << std::endl;
}
