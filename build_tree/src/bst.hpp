#pragma once

#include <string>
#include <vector>

#include "node.hpp"

class bst
{
public:
    void insert(int v);

    void insert(const std::vector<int>& sorted);

    bool isBalanced() const;
    
    std::string inorder() const;

private:
    node* _tree = nullptr;
};
