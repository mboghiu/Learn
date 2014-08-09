#include "test.hpp"
#include "bst.hpp"

#include <string>

int main()
{
    bst tree;

    tree.insert(4);
    test<std::string>("4", tree.inorder());

    tree.insert(6);
    test<std::string>("46", tree.inorder());

    tree.insert(6);
    test<std::string>("466", tree.inorder());

    tree.insert(1);
    tree.insert(2);
    tree.insert(9);
    test<std::string>("124669", tree.inorder());

    return 0;
}
