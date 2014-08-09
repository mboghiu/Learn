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
        bool toggleInsert = false;

        void _RecursiveInsert(Node*& where, const T& value);
};

template<typename T>
void bt<T>::Insert(const T& value)
{
    _RecursiveInsert(_tree, value);
}

template<typename T>
void bt<T>::_RecursiveInsert(Node*& node, const T& value)
{
    if (node == nullptr)
    {
        node = new Node(value);
        toggleInsert = !toggleInsert;
        return;
    }

    if (node-> left == nullptr)
        _RecursiveInsert(node->left, value);
    else if (node->right == nullptr)
        _RecursiveInsert(node->right, value);
    else
        // no particular kind of tree
        toggleInsert?
            _RecursiveInsert(node->left, value) :
            _RecursiveInsert(node->right, value);
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

///////// preorder

static void _preorder(std::stringstream& ss, Node* node)
{
    if (node == nullptr)
        return;

    ss << node->data << "|";
    _preorder(ss, node->left);
    _preorder(ss, node->right);
}

template<typename T>
std::string bt<T>::DFTraverse_preorder() const
{
    std::stringstream ss;
    _preorder(ss, _tree);
    return std::move(ss.str());
}

///////// inorder

static void _inorder(std::stringstream& ss, Node* node)
{
    if (node == nullptr)
        return;

    _inorder(ss, node->left);
    ss << node->data << "|";
    _inorder(ss, node->right);
}

template<typename T>
std::string bt<T>::DFTraverse_inorder() const
{
    std::stringstream ss;
    _inorder(ss, _tree);
    return std::move(ss.str());
}

///////// postorder

static void _postorder(std::stringstream& ss, Node* node)
{
    if (node == nullptr)
        return;

    _postorder(ss, node->left);
    _postorder(ss, node->right);
    ss << node->data << "|";
}

template<typename T>
std::string bt<T>::DFTraverse_postorder() const
{
    std::stringstream ss;
    _postorder(ss, _tree);
    return std::move(ss.str());
}
