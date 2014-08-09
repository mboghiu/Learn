#include "test.hpp"
#include "graph.hpp"

#include <string>

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
    g.add(edge(2, 3));
    g.add(edge(2, 7));
    g.add(edge(2, 4));
    g.add(edge(4, 6));
    g.add(edge(5, 7));
    g.add(edge(7, 5));

    Test<std::string>("2|3|4|7|6|5|", g.bf(2));
    Test(true, g.route(2,5));
    Test(true, g.route(1,5));
    Test(false, g.route(4,1));

    return 0;
}
