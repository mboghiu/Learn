#include <string>

#include "test.hpp"
#include "tree.hpp"

int main()
{
    bt<int> tree;

    tree.Insert(3);
    Test<std::string>("3|", tree.BFTraverse());
    Test<std::string>("3|", tree.DFTraverse_preorder());
    Test<std::string>("3|", tree.DFTraverse_inorder());
    Test<std::string>("3|", tree.DFTraverse_postorder());

    // After first 3 values, BFT and DFT-preorder are the same
    tree.Insert(4);
    tree.Insert(5);
    Test<std::string>("3|4|5|", tree.BFTraverse());
    Test<std::string>("3|4|5|", tree.DFTraverse_preorder());
    Test<std::string>("4|3|5|", tree.DFTraverse_inorder());
    Test<std::string>("4|5|3|", tree.DFTraverse_postorder());

    tree.Insert(6);
    tree.Insert(7);
    tree.Insert(8);
    tree.Insert(9);
    Test<std::string>("3|4|5|6|8|7|9|", tree.BFTraverse());
    Test<std::string>("3|4|6|8|5|7|9|", tree.DFTraverse_preorder());
    Test<std::string>("6|4|8|3|7|5|9|", tree.DFTraverse_inorder());
    Test<std::string>("6|8|4|7|9|5|3|", tree.DFTraverse_postorder());

    return 0;
}
