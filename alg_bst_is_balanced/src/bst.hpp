#pragma once

#include <string>

#include "node.hpp"

class bst
{
public:
    void insert(int v);
    
    std::string inorder() const;

private:
    node* _tree = nullptr;
};
