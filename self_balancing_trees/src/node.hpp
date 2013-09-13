#ifndef _NODE_HPP
#define _NODE_HPP

#include <sstream>


/////////////// Node /////////////////

template<typename T>
class Node
{
    public:
        Node() = delete;
        Node(size_t key, const T& value, int level);

        /*
            Modifiers 
        */

        void AppendLeftChild(Node* const child);
        void AppendRightChild(Node* const child);

        void RecomputeHeight();

        /*
            Getters & Checkers
        */

        bool HasLeftChild() const;
        bool HasRightChild() const;

        Node<T>* GetLeftChild() const;
        Node<T>* GetRightChild() const;

        size_t GetKey() const;
        int GetLevel() const;
        int GetHeight() const;
        int GetLoadFactor() const;

        std::string ToString() const;

    private:
        size_t m_key;

        T m_value;

        int m_level;
        int m_height;

        Node* m_left;
        Node* m_right;
};


/////////////// Node implementation /////////////////

template<typename T>
Node<T>::Node(size_t key, const T& value, int level) :
    m_key(key),
    m_value(value),
    m_level(level),
    m_height(0),
    m_left(0),
    m_right(0)
{ }

template<typename T>
void Node<T>::AppendLeftChild(Node* const child)
{
    if (m_left != 0)
    {
        std::cerr << "Cannot overwrite existing left child" << std::endl;
        return;
    }

    m_left = child;
}

template<typename T>
void Node<T>::AppendRightChild(Node* const child)
{
    if (m_right != 0)
    {
        std::cerr << "Cannot overwrite existing right child" << std::endl;
        return;
    }

    m_right = child;
}

template<typename T>
void Node<T>::RecomputeHeight()
{
    if (m_left == nullptr and m_right == nullptr)
        return;

    if (m_left == nullptr)
    {
        m_height = m_right->GetHeight() + 1;
        return;
    }

    if (m_right == nullptr)
    {
        m_height = m_left->GetHeight() + 1;
        return;
    }

    m_height = std::max(m_left->GetHeight(), m_right->GetHeight()) + 1;
}

template<typename T>
bool Node<T>::HasLeftChild() const
{
    return (m_left == nullptr ? false : true);
}

template<typename T>
bool Node<T>::HasRightChild() const
{
    return (m_right == nullptr ? false : true);
}

template<typename T>
Node<T>* Node<T>::GetLeftChild() const
{
    return m_left;
}

template<typename T>
Node<T>* Node<T>::GetRightChild() const
{
    return m_right;
}

template<typename T>
size_t Node<T>::GetKey() const
{
    return m_key;
}

template<typename T>
int Node<T>::GetLevel() const
{
    return m_level;
}

template<typename T>
int Node<T>::GetHeight() const
{
    return m_height;
}

template<typename T>
int Node<T>::GetLoadFactor() const
{
    if (m_left == nullptr and m_right == nullptr)
        return 0;

    if (m_left == nullptr)
        return (0 - m_right->GetHeight());

    if (m_right == nullptr)
        return (m_left->GetHeight());

    return (m_left->GetHeight() - m_right->GetHeight());
}

template<typename T>
std::string Node<T>::ToString() const
{
    std::ostringstream iss;

    iss << "(k:\033[1;37m" << m_key << "\033[0m,v:" << m_value << ",L:" << m_level << ",H:" << m_height << ")";

    return (std::move(iss.str()));
}

#endif // _NODE_HPP
