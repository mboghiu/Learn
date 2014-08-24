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

void _rotate_right(node* node)
{
    auto x = node;
    auto y = node->parent;
    auto z = node->parent->parent;

    if (node->parent->left == node)
    {
        // right-rotate
        auto temp = y->right;
        y->right = z;
        z->left = temp;
    }
    else
    {
        // left-rotate
        z.left = x;
        auto temp = x->left;
        x->left = y;
        y->right = temp;

        // right-rotate
        _rotate_right(y);
    }
}

node* _find_first_node_with_an_unbalanced_grandparent(node* n)
{
    while (n->parent != nullptr && n->parent->parent != nullptr)
        if (std::abs(n->parent->parent->balance()) == 2)
            return n;
        else
            n = n->parent;

    return nullptr;
}

void _maybe_rebalance(node* node)
{
    auto n = _find_first_node_with_an_unbalanced_grandparent(node);

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


