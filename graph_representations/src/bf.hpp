#ifndef _BF_ALG
#define _BF_ALG

#include <iostream>
#include <set>
#include <queue>

namespace traversal
{
    template<typename Graph>
    void bf(const Graph& graph);
}

//////////// BF ///////////////

template<typename Graph>
static bool IsVisited(const std::set<size_t>& visited, size_t node)
{
    return (visited.find(node) != visited.end());
}

template<typename Graph>
static void _bf_with_a_queue(const Graph& graph, size_t start)
{
    std::set<size_t> visited;
    std::queue<size_t> waiting;

    waiting.push(start);

    while (!waiting.empty())
    {
        size_t current = waiting.front();
        waiting.pop();

        if (!IsVisited(visited, current))
            std::cout << current << " | "; // apply f()

        visited.insert(current);

        for (auto neighbour : graph.GetNeighbours(current))
            if (!IsVisited(visited, neighbour))
                waiting.push(neighbour);
    }
}

template<typename Graph>
void traversal::bf(const Graph& graph)
{
    size_t start;
    std::cout << "Breadth first traversal starting at node: ";
    std::cin >> start;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    _bf_with_a_queue(graph, start);    
    std::cout << std::endl;
}


#endif // _BF_ALG
