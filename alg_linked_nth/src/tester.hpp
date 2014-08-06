#pragma once

#include <iostream>

template<typename T>
void Test(const T& expected, const T& actual)
{
    if (expected == actual)
        std::cout << "\033[32mPASS\033[0m" << std::endl;
    else
        std::cout << "\033[31mFAIL\033[0m" << std::endl;
}
