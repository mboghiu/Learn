#ifndef _DF_ALG_
#define _DF_ALG_

#include <iostream>
#include <set>
#include <stack>

namespace traversal
{
    template<typename Graph>
    void df(const Graph& graph);
}

//////////// DF helpers (inside this compilation unit) ///////////////

static bool IsVisited(const std::set<size_t>& visited, size_t node)
{
    return (visited.find(node) != visited.end());
}

template<typename Graph>
static void _df(const Graph& graph, size_t start, std::set<size_t>& visited)
{
    visited.insert(start);       // mark as visited
    std::cout << start << " | "; // apply f()

    for (auto neighbour : graph.GetNeighbours(start))
        if (!IsVisited(visited, neighbour))
            _df(graph, neighbour, visited);
}

template<typename Graph>
static void _df_with_a_stack(const Graph& graph, size_t start)
{
    std::set<size_t> visited;
    std::stack<size_t> waiting;

    waiting.push(start);

    while (!waiting.empty())
    {
        // Get top of stack
        size_t current = waiting.top();
        waiting.pop();

        // Do something with the node (if we haven't already)
        if (!IsVisited(visited, current))
            std::cout << current << " | ";

        // Mark as visited
        visited.insert(current);

        // Add all its unvisited neighbours to the stack
        const std::vector<size_t>& neighbours = graph.GetNeighbours(current);

        for (std::vector<size_t>::const_iterator it = neighbours.end() - 1; it >= neighbours.begin(); it--)
            if (!IsVisited(visited, *it))
                waiting.push(*it);
    }
}

////////// Public ///////////////

template<typename Graph>
void traversal::df(const Graph& graph)
{
    size_t start;
    std::cout << "Depth first traversal starting at node: ";
    std::cin >> start;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::set<size_t> visited;

    _df(graph, start, visited);    
    std::cout << std::endl << "\033[36m";

    _df_with_a_stack(graph, start);
    std::cout << "\033[0m" << std::endl;
}

#endif // _DF_ALG_
