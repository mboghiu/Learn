#ifndef _BF_ALG
#define _BF_ALG

#include <iostream>

namespace traversal
{
    template<typename Graph>
    void bf(const Graph& graph);
}

//////////// BF ///////////////

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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    _bf(graph, start);    
    std::cout << std::endl;
}


#endif // _BF_ALG
