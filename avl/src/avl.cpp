#include "avl.hpp"

#include <cmath>

node* _insert(node* parent, node*& root, int value)
{
    if (root == nullptr)
    {
        root = new node(value, parent);
        return root;
    }
    else if (value < root->v)
        return _insert(root, root->left, value);
    else
        return _insert(root, root->right, value);
}

void _rotate_left(node*)
{
}

void _rotate_right(node*)
{
}

node* _find_first_node_with_an_unbalanced_parent(node* n)
{
    while (n->parent != nullptr)
        if (std::abs(n->parent->balance()) == 2)
            return n;
        else
            n = n->parent;

    return nullptr;
}

void _maybe_rebalance(node* node)
{
    auto n = _find_first_node_with_an_unbalanced_parent(node);

    if (n == nullptr)
        return;

    if (n->parent->balance() > 0 /* right-heavy*/)
        _rotate_left(n);
    else
        _rotate_right(n);
}

void avl::insert(int value)
{
    _maybe_rebalance(_insert(nullptr, _root, value));
}

void remove(int /*value*/)
{

}

bool search(int /*value*/)
{
    return true;
}


