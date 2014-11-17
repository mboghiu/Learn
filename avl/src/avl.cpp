#include "avl.hpp"

#include <cmath>

node&_insert(node* parent, node*& root, int value)
{
    if (root == nullptr)
    {
        root = new node(value, parent);
        return *root;
    }
    else if (value < root->v)
        return _insert(root, root->left, value);
    else
        return _insert(root, root->right, value);
}

void _rotate_left(node&) { }
void _rotate_right(node& root)
{
    auto& x = root;
    auto& y = *x.parent;
    auto& z = *y.parent;

    if (*y.left == root)
    {
        // right-rotate
        auto temp = y.right;
        y.right = &z;
        z.left = temp;
    }
    else
    {
        // left-rotate
        z.left = &x;
        auto temp = x.left;
        x.left = &y;
        y.right = temp;

        // right-rotate
        _rotate_right(y);
    }
}

void _maybe_rebalance(node& root)
{
    node* n = &root;
    while (n->parent != nullptr && n->parent->parent != nullptr)
        if (std::abs(n->parent->parent->balance()) == 2)
            break;
        else
            n = n->parent;

    if (n == nullptr || n->parent == nullptr || n->parent->parent == nullptr)
        return;

    if (n->parent->balance() > 0 /* right-heavy*/)
        _rotate_left(*n);
    else
        _rotate_right(*n);
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

#include <iostream>
#include <list>
#include <queue>

void avl::print() const
{
    if (_root == nullptr)
        return;

    std::queue<node> q;
    q.push(*_root);

    std::list<std::list<node>> lists;

    auto depth = 0;
    lists.push_front(std::list<node>());
    auto nodes = std::pow(2, depth); 

    while(!q.empty())
    {
        auto n = q.front();
        q.pop();
        nodes--;

        std::list<node>& current_level = lists.front();
        current_level.push_front(n);

        if (n.left == nullptr)
        {
            if (n.right != nullptr)
                q.push(node(-1, nullptr));
        }
        else q.push(*n.left);

        if (n.right == nullptr)
        {
            if (n.left != nullptr)
                q.push(node(-1, nullptr));
        }
        else q.push(*n.right);

        if (nodes == 0)
        {
            depth++;
            lists.push_back(std::list<node>());
            nodes = std::pow(2, depth);
        }
    }

    auto l = 0;
    for (auto level : lists)
    {
        std::cout << "level: " << l << "--> ";
        for (auto node : level)
            std::cout << node.v << " ";
        std::cout << std::endl;
        l++;
    }
}
