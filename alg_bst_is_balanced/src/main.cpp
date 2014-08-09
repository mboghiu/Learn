#include "test.hpp"
#include "bst.hpp"

#include <string>

int main()
{
    bst tree;

    tree.insert(4);
    test<std::string>("4", tree.inorder());

    return 0;
}
