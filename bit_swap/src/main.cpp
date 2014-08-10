#include "test.hpp"

#include <bitset>
#include <iostream>

uint32_t swap(uint32_t a)
{
    return ((a & 0xaaaaaaaa) >> 1) | ((a & 0x55555555) << 1);
}

int main()
{
    test<uint32_t>(34, swap(17));

    return 0;
}
