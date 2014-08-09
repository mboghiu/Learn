#include "test.hpp"
#include "graph.hpp"

int main()
{
    graph g;

    g.add(1);
    g.add(2);
    g.add(3);
    g.add(4);
    g.add(5);
    g.add(6);
    g.add(7);

    g.add(edge(1, 2));

    return 0;
}
