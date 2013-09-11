#ifndef _MATRIX_GRAPH
#define _MATRIX_GRAPH

#include <vector>
#include <map>
#include <iostream>
#include <cmath>

/////////////// Node //////////////////

template<typename T>
struct Node
{
    T m_value;
};

/////////////// MatrixGraph //////////////////

template<typename T>
class MatrixGraph
{
    public:
        MatrixGraph() = delete;
        MatrixGraph(size_t numberOfNodes);

        void AddEdge(size_t start, size_t end);
        void RemoveEdge(size_t start, size_t end);

        void SetNodeValue(size_t node, const T& value);
        const T& GetNodeValue(size_t node) const;

        bool AreAdjacent(size_t nodeX, size_t nodeY) const;
        const std::vector<size_t> GetNeighbours(size_t node) const;

        void Print() const;

    private:
        size_t m_nodeCount;
        std::map<size_t, Node<T>> m_nodes;
        std::vector<bool> m_graph;
};

/////////////// MatrixGraph implementation //////////////////


template<typename T>
MatrixGraph<T>::MatrixGraph(size_t numberOfNodes) :
    m_nodeCount(numberOfNodes)
{
    m_graph.resize(static_cast<size_t>(pow(static_cast<double>(m_nodeCount), 2)));

    for (size_t index = 0; index < m_graph.size(); index++)
        m_graph.at(index) = false;
}

template<typename T>
void MatrixGraph<T>::AddEdge(size_t start, size_t end)
{
    m_graph.at(start * m_nodeCount + end) = true;
}

template<typename T>
void MatrixGraph<T>::RemoveEdge(size_t start, size_t end)
{
    m_graph.at(start * m_nodeCount + end) = false;
}

template<typename T>
void MatrixGraph<T>::SetNodeValue(size_t /*node*/, const T& /*value*/)
{
    // TODO set node value
}

template<typename T>
const T& MatrixGraph<T>::GetNodeValue(size_t node) const
{
    // TODO get node value
    return m_graph.at(node);
}

template<typename T>
bool MatrixGraph<T>::AreAdjacent(size_t nodeX, size_t nodeY) const
{
    return m_graph.at(nodeX * m_nodeCount + nodeY);
}

template<typename T>
const std::vector<size_t> MatrixGraph<T>::GetNeighbours(size_t node) const
{
    std::vector<size_t> neighbours;

    for (size_t index = 0; index < m_nodeCount; index++)
        if (m_graph.at(node * m_nodeCount + index))
            neighbours.push_back(index);

    return (std::move(neighbours));
}

template<typename T>
void MatrixGraph<T>::Print() const
{
    /* List column header */

    std::cout << "* ";

    for (size_t index = 0; index < m_nodeCount; index++)
    {
        std::cout << "\033[37m" << index << " \033[0m";
    }

    std::cout << std::endl;

    /* List rows */

    for (size_t index = 0; index < m_graph.size(); index++)
    {
        /* List row header */
        if ( index % m_nodeCount == 0 )
            std::cout << "\033[37m" << (index / m_nodeCount) << " \033[0m";

        std::cout << (m_graph.at(index) ? "1 " : "0 ");

        /* New line at end of row */
        if (((index + 1) % m_nodeCount) == 0)
            std::cout << std::endl;
    }
}


#endif // _MATRIX_GRAPH
