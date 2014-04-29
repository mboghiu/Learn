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

        void _rotate_right(Node<T>* subtreeRoot);
        void _rotate_left(Node<T>* subtreeRoot);

        void _insert(size_t key, const T& value, Node<T>* tree);
        void _maybe_rebalance(Node<T>* tree);
};



/////////////// AVL implementation /////////////////


template<typename T>
void AVL<T>::insert(size_t key, const T& value)
{
    if (m_root == nullptr)
    {
        m_root = new Node<T>(key, value, 0);
        return;
    }
        
    _insert(key, value, m_root);
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


/////////////////// Helpers /////////////////////

template<typename T>
void AVL<T>::_rotate_right(Node<T>* subtreeRoot)
{
    /*
        STEP#1 pivot = Root.OS
    */ 
    Node<T>* pivot = subtreeRoot->GetLeftChild();

    assert(pivot->HasLeftChild() or pivot->HasRightChild()); // otherwise we shouldn't be rotating
    
    /*
        STEP#2 Root.OS = pivot.RS (or pivot.OS is only child)
    */
    if (pivot->HasRightChild())
    {
        subtreeRoot->SetLeftChild(pivot->GetRightChild());
        /*
            STEP#3 pivot.RS = root
        */
        pivot->SetRightChild(subtreeRoot);
    }
    else
    {
        subtreeRoot->SetLeftChild(pivot->GetLeftChild());
        /*
            STEP#3 pivot.OS = root
        */
        pivot->SetLeftChild(subtreeRoot);
    }

    /*
        STEP#4 Root = pivot
    */
    subtreeRoot = pivot;
}

template<typename T>
void AVL<T>::_rotate_left(Node<T>* /*subtreeRoot*/)
{
    // TODO rotate left
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
        return;
    }

    tree->RecomputeHeight();

    _maybe_rebalance(tree);
}

template<typename T>
void AVL<T>::_maybe_rebalance(Node<T>* tree)
{
    int lf = tree->GetLoadFactor();

    if (lf < -1)
    {
        std::cout << "rotate left: " << tree->ToString() << std::endl;
        _rotate_left(tree);
        return;
    }
 
    if (lf > 1)
    {
        std::cout << "rotate right: " << tree->ToString() << std::endl;
        _rotate_right(tree);
        return;
    }
}

#endif // _AVL_TREE
