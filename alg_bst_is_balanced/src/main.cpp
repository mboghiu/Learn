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

    test(false, tree.isBalanced());

    bst tree2;
    tree2.insert(4);
    tree2.insert(3);
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(2);
    tree2.insert(1);
    test(false, tree2.isBalanced());

    bst tree3;
    tree3.insert(2);
    tree3.insert(1);
    tree3.insert(3);
    test(true, tree3.isBalanced());

    bst tree4;
    tree4.insert(2);
    tree4.insert(1);
    test(true, tree4.isBalanced());
    return 0;
}
