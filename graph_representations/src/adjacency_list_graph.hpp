#ifndef _ADJACENCY_LIST_GRAPH
#define _ADJACENCY_LIST_GRAPH

/////////////// Edje and AdjNode //////////////////

struct Edge
{
    Edge() = delete;
    Edge(size_t from, size_t to) :
        m_from(from),
        m_to(to),
        m_next(0)
    { }

    size_t m_from;
    size_t m_to;

    Edge* m_next;
};

template<typename T>
struct AdjNode
{
    T m_value;
};

/////////////// AdjacencyListGraph //////////////////

template<typename T>
class AdjacencyListGraph
{
    public:
        AdjacencyListGraph() = delete;
        AdjacencyListGraph(size_t numberOfNodes);

        void AddEdge(size_t start, size_t end);
        void RemoveEdge(size_t start, size_t end);

        bool AreAdjacent(size_t nodeX, size_t nodeY) const;
        const std::vector<size_t> GetNeighbours(size_t node) const;

        size_t GetSize() const;

        void Print() const;

    private:
        std::set<AdjNode<T>> m_nodes;
        std::vector<Edge*> m_graph;
};

template<typename T>
AdjacencyListGraph<T>::AdjacencyListGraph(size_t numberOfNodes)
{
    for (size_t mockNode = 0; mockNode < numberOfNodes; mockNode++)
        m_graph.push_back(0);
}

template<typename T>
void AdjacencyListGraph<T>::AddEdge(size_t start, size_t end)
{
    Edge* edge = new Edge(start, end);

    if (m_graph.at(start) == 0)
    {
        m_graph.at(start) = edge;
        return;
    }

    Edge* insertPlace = m_graph.at(start);
    while (insertPlace->m_next != 0)
        insertPlace = insertPlace->m_next;
    insertPlace ->m_next = edge;
}

template<typename T>
void AdjacencyListGraph<T>::RemoveEdge(size_t /*start*/, size_t /*end*/)
{
    // adj remove edge
}

template<typename T>
bool AdjacencyListGraph<T>::AreAdjacent(size_t /*nodeX*/, size_t /*nodeY*/) const
{
    // TODO adj are adjacent
    return true;
}

template<typename T>
const std::vector<size_t> AdjacencyListGraph<T>::GetNeighbours(size_t /*node*/) const
{
    std::vector<size_t> neighbours;

    // TODO adj get neighbours

    return (std::move(neighbours));
}

template<typename T>
size_t AdjacencyListGraph<T>::GetSize() const
{
    return m_graph.size();
}

template<typename T>
void AdjacencyListGraph<T>::Print() const
{
    for (size_t index = 0; index < m_graph.size(); index++)
    {
        std::cout << "\033[37m" << index << "--> \033[0m";
        for (Edge* edge = m_graph.at(index); edge != 0; edge = edge->m_next)
            std::cout << "(" << edge->m_from << "," << edge->m_to << ") ";
        std::cout << "\033[31m->//\033[0m" << std::endl;
    }
}

#endif // _ADJACENCY_LIST_GRAPH
