#include <string>

#include "test.hpp"
#include "tree.hpp"

int main()
{
    bt<int> tree;

    tree.Insert(3);
    Test<std::string>("3|", tree.DFTraverse_preorder());
    Test<std::string>("3|", tree.DFTraverse_inorder());
    Test<std::string>("3|", tree.DFTraverse_postorder());
    Test<std::string>("3|", tree.BFTraverse());

    return 0;
}
