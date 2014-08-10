#include "test.hpp"

#include <bitset>
#include <iostream>

int mask_for_setting_bits_to_zero_between_two_indexes(int/* n*/, int i, int j)
{
    int max = ~0;
    std::cout << "max:      " << std::bitset<32>(max) << " = " << max << std::endl; 
    std::cout << "1:        " << std::bitset<32>(1)   << " = " << 1 << std::endl; 
    std::cout << "1<<j:     " << std::bitset<32>(1<<j)<< " = " << 1<<j << "(j=" << j << ")" << std::endl; 
    std::cout << "(1<<j)-1: " << std::bitset<32>((1<<j)-1) << std::endl;

    // i 1's starting right
    int right = (1 << i) - 1;
    std::cout << "right: " << std::bitset<32>(right) << std::endl;

    // 32-j 1's starting left
    int left =  ~0 ^ ((1 << j) - 1);
    std::cout << "left:  " << std::bitset<32>(left) << std::endl;
    
    int mask = right | left;
    std::cout << "mask:  " << std::bitset<32>(mask) << std::endl;

    return mask;
}

int make_substring(int n, int m, int i, int j)
{
    std::cout << "n:      " << std::bitset<32>(n) << std::endl; 
    std::cout << "m << i: " << std::bitset<32>(m << i) << std::endl; 
    std::cout << std::endl;

    int mask = mask_for_setting_bits_to_zero_between_two_indexes(n, i, j); 

    return (n & mask) | (m << i);
}

int main()
{
    std::cout << std::endl << std::endl;
    test(1108, make_substring(1024, 21, 2, 6));

    return 0;
}
