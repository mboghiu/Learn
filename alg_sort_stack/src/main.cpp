#include "test.hpp"
#include "stack.hpp"

#include <iostream>
#include <string>

int main()
{
    stack<int> s;
    s.push(10);
    s.push(1);
    s.push(3);
    s.push(0);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(11);

    s.sort();
    test<std::string>("0-->1-->3-->7-->8-->9-->10-->11-->|\n", s.print());
    
    return 0;
}
