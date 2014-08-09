#include "test.hpp"
#include "bst.hpp"

int main()
{
    bst tree;

    tree.insert({1, 2, 3});

    test(true, tree.isBalanced());

    return 0;
}
