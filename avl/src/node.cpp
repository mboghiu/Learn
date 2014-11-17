#include "node.hpp"

#include <algorithm>

bool operator==(const node& lhs, const node& rhs)
{
    return (lhs.v == rhs.v) && (lhs.left == rhs.left) && (lhs.right == rhs.right);
}

node::node(int v, node* p) :
    v(v),
    left(nullptr),
    right(nullptr)
{
    parent = p;
}

    static int _height(node* n)
    {
        if (n == nullptr)
            return 0;

        if (n->left == nullptr && n->right == nullptr)
            return 1;

        return 1 + std::max(_height(n->left), _height(n->right));
    }

int node::balance()
{
    return _height(this->right) - _height(this->left);
}
