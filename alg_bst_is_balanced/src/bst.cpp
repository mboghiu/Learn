#include "bst.hpp"
#include <sstream>

static void _insert(int v, node*& n)
{
    if (n == nullptr)
        n = new node(v);
    else if (v < n->data)
        _insert(v, n->left);
    else
        _insert(v, n->right);
}

void bst::insert(int v)
{
    _insert(v, _tree);
}

static void _inoder(std::stringstream& ss, node* n)
{
    if (n == nullptr)
        return;
    _inoder(ss, n->left);
    ss << n->data;
    _inoder(ss, n->right);
}

std::string bst::inorder() const
{
    std::stringstream ss;
    _inoder(ss, _tree);
    return std::move(ss.str());
}
