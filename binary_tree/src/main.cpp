#include <string>

#include "test.hpp"
#include "tree.hpp"

int main()
{
    bt<int> tree;

    tree.Insert(3);
    Test<std::string>("3|", tree.BFTraverse());

    tree.Insert(4);
    Test<std::string>("3|4|", tree.BFTraverse());

    tree.Insert(5);
    Test<std::string>("3|4|5|", tree.BFTraverse());

    tree.Insert(6);
    tree.Insert(7);
    Test<std::string>("3|4|5|6|7|", tree.BFTraverse());


    return 0;
}
