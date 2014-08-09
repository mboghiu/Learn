#include "bst.hpp"

#include <sstream>
#include <algorithm>
#include <iostream>

///////////////// insert

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

void bst::insert(const std::vector<int>& sorted)
{
    auto n = sorted.size();

    if (n == 1)
    {
        insert(sorted[0]);
        return;
    }

    insert(sorted[n/2]);

    insert(std::vector<int>(sorted.begin(), sorted.begin() + n/2));
    insert(std::vector<int>(sorted.begin() + n/2 + 1, sorted.end()));
}

///////////////// balanced

static int maxdepth(node* n)
{
    if (n == nullptr)
        return 0;
    else
        return 1 + std::max(maxdepth(n->left), maxdepth(n->right));
}

static int mindepth(node* n)
{
    if (n == nullptr)
        return 0;
    else
        return 1 + std::min(mindepth(n->left), mindepth(n->right));
}

bool bst::isBalanced() const
{
    return (maxdepth(_tree) - mindepth(_tree) <= 1);
}

///////////////// inoder

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
