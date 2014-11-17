#pragma once

#include "node.hpp"

class avl
{
    public:
        void insert(int value);
        void remove(int value);
        bool search(int value);

        void print() const;

    private:
        node* _root = nullptr;
        void _rotateL();
        void _rotateR();
};
