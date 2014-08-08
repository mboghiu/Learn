#pragma once

#include <string>
#include <sstream>

#include "node.hpp"
#include "queue.hpp"

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
        Node* _tree = nullptr;

        void _RecursiveInsert(Node*& where, const T& value, bool& done);
};

template<typename T>
void bt<T>::Insert(const T& value)
{
    bool done = false;
    _RecursiveInsert(_tree, value, done);
}

template<typename T>
void bt<T>::_RecursiveInsert(Node*& node, const T& value, bool& done)
{
    if (done)
        return;

    if (node == nullptr)
    {
        node = new Node(value);
        done = true;
        return;
    }

    _RecursiveInsert(node->left, value, done);
    _RecursiveInsert(node->right, value, done);
}

template<typename T>
std::string bt<T>::BFTraverse() const
{
    if (_tree == nullptr)
        return "";

    std::stringstream ss;

    Queue<Node> queue;
    queue.Push(*_tree);

    while (queue.Peek() != nullptr)
    {
        auto front = queue.Pop()->m_data;

        ss << front.data << "|";

        if (front.left != nullptr)
            queue.Push(*front.left);
        if (front.right != nullptr)
            queue.Push(*front.right);
    }

    return std::move(ss.str());
}
