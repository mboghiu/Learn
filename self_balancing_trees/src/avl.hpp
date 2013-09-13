#ifndef _AVL_TREE
#define _AVL_TREE

#include <iostream>
#include <string>
#include <queue>

#include "node.hpp"

/////////////// AVL /////////////////

template<typename T>
class AVL
{
    public:
        void insert(size_t key, const T& value);
        void remove(size_t key);
        const T& lookup(size_t key) const;
        void Print() const;

    private:
        Node<T>* m_root = 0;

        void rebalance(Node<T>* subtreeRoot);
        void rotate_right(Node<T>* subtreeRoot);
        void rotate_left(Node<T>* subtreeRoot);

        void _insert(size_t key, const T& value, Node<T>* tree);
};



/////////////// AVL implementation /////////////////


template<typename T>
void AVL<T>::insert(size_t key, const T& value)
{
    // TODO insert
    if (m_root == nullptr)
    {
        m_root = new Node<T>(key, value, 0);
        return;
    }
        
    _insert(key, value, m_root);
}

template<typename T>
void AVL<T>::_insert(size_t key, const T& value, Node<T>* tree)
{
    /* simple insert into a binary tree */
    if (key < tree->GetKey())
    {
        if (tree->HasLeftChild())
            _insert(key, value, tree->GetLeftChild());
        else
            tree->AppendLeftChild(new Node<T>(key, value, tree->GetLevel() + 1));
    }
    else if (key > tree->GetKey())
    {
        if (tree->HasRightChild())
            _insert(key, value, tree->GetRightChild());
        else
            tree->AppendRightChild(new Node<T>(key, value, tree->GetLevel() + 1));
    }
    else
    {
        std::cout << "Sorry, we don't allow duplicate keys." << std::endl;
    }
}

template<typename T>
void AVL<T>::remove(size_t key)
{
    // TODO remove
    std::cout << key << std::endl;
}

template<typename T>
const T& AVL<T>::lookup(size_t key) const
{
    // TODO lookup
    T* value = new T;
    std::cout << key << std::endl;

    return *value;
}

template<typename T>
void AVL<T>::Print() const
{
    std::cout << "AVL" << std::endl;

    std::queue<const Node<T>*> toPrint;
    toPrint.push(m_root);

    int currentLevel = 0;

    while (!toPrint.empty())
    {
        const Node<T>* current = toPrint.front();
        toPrint.pop();

        if (current->GetLevel() > currentLevel)
        {
            std::cout << std::endl;
            currentLevel++;
        }

        std::cout << current->ToString();

        if (current->HasLeftChild())
            toPrint.push(current->GetLeftChild());
        if (current->HasRightChild())
            toPrint.push(current->GetRightChild());
    }

    std::cout << std::endl;
}


#endif // _AVL_TREE
