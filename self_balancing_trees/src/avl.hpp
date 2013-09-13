#ifndef _AVL_TREE
#define _AVL_TREE


/////////////// Node /////////////////

template<typename T>
struct Node
{
    size_t m_key;
    T m_value;
    Node* m_left = 0;
    Node* m_right = 0;
};

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
        Node<T>* m_root;

        void rebalance(Node<T>* subtreeRoot);
        void rotate_right(Node<T>* subtreeRoot);
        void rotate_left(Node<T>* subtreeRoot);
};



/////////////// AVL implementation /////////////////



#endif // _AVL_TREE
