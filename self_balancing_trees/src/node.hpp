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

        void AppendLeftChild(Node* const child);
        void AppendRightChild(Node* const child);

        bool HasLeftChild() const;
        bool HasRightChild() const;

        Node<T>* GetLeftChild() const;
        Node<T>* GetRightChild() const;

        size_t GetKey() const;

        int GetLevel() const;

        std::string ToString() const;

    private:
        size_t m_key;

        T m_value;

        int m_level;

        Node* m_left;
        Node* m_right;
};


/////////////// Node implementation /////////////////

template<typename T>
Node<T>::Node(size_t key, const T& value, int level) :
    m_key(key),
    m_value(value),
    m_level(level),
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
std::string Node<T>::ToString() const
{
    std::ostringstream iss;

    iss << "(" << m_key << "," << m_value << "," << m_level << ")";

    return (std::move(iss.str()));
}

#endif // _NODE_HPP
