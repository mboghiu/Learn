#ifndef _DF_ALG_
#define _DF_ALG_

#include <iostream>
#include <set>

namespace traversal
{
    template<typename Graph>
    void df(const Graph& graph);

    template<typename Graph>
    void bf(const Graph& graph);

}



//////////// implementation ///////////////

template<typename Graph>
static void _df(const Graph& graph, size_t start, std::set<size_t>& visited)
{
    for (auto neighbour : graph.GetNeighbours(start))
    {
        if (visited.find(neighbour) == visited.end())
        {
            visited.insert(neighbour);
            _df(graph, neighbour, visited);
            std::cout << neighbour << " | ";
        }
    }
}

template<typename Graph>
void traversal::df(const Graph& graph)
{
    size_t start;
    std::cout << "Depth first traversal starting at node: ";
    std::cin >> start;

    std::set<size_t> visited;
    _df(graph, start, visited);    
    std::cout << std::endl;
}

template<typename Graph>
static void _bf(const Graph& /*graph*/, size_t /*start*/)
{
    // TODO recursive routine for BF
}

template<typename Graph>
void traversal::bf(const Graph& graph)
{
    size_t start;
    std::cout << "Breadth first traversal starting at node: ";
    std::cin >> start;

    _bf(graph, start);    
}

#endif // _DF_ALG_
