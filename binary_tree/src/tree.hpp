#pragma once

#include <string>
#include <sstream>

#include "node.hpp"


template<typename T>
class bt
{
    public:
        void Insert(const T& value);
        void Delete(const T& value); 
        bool Search(const T& value) const;
        
        std::string DFTraverse_preorder() const;
        std::string DFTraverse_inorder() const;
        std::string DFTraverse_postorder() const;

        std::string BFTraverse() const;

    private:
        Node<T>* _tree = nullptr;

        void _RecursiveInsert(Node<T>*& where, const T& value, bool& done);
};

template<typename T>
void bt<T>::Insert(const T& value)
{
    bool done = false;
    _RecursiveInsert(_tree, value, done);
}

template<typename T>
void bt<T>::_RecursiveInsert(Node<T>*& node, const T& value, bool& done)
{
    if (done)
        return;

    if (node == nullptr)
    {
        node = new Node<T>(value);
        done = true;
        return;
    }

    _RecursiveInsert(node->left, value, done);
    _RecursiveInsert(node->right, value, done);
}










