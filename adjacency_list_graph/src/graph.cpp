#include "graph.hpp"

#include <utility>
#include <iostream>

void graph::add(const node& n)
{
    _graph[n] = std::set<node>();
}

void graph::add(const edge& e)
{
    _graph[e.from].insert(e.to);
}

void graph::peek() const
{
    for (auto pair : _graph)
    {
        std::cout << pair.first.key << "--> ";
        for (auto node : pair.second)
            std::cout << node.key << " ";
        std::cout << std::endl;
    }
}

#include <sstream>
#include <queue>

std::string graph::bf(const node& n)
{
    std::stringstream ss;

    std::queue<node> q;
    q.push(n);

    std::set<node> visited;
    visited.insert(n);

    while (!q.empty())
    {
        auto next = q.front();
        visited.insert(next);
        ss << next.key << "|";
        for (auto neighbour : _graph[next])
            if (visited.find(neighbour) == visited.end())
                q.push(neighbour);
        q.pop();
    }
        
    return std::move(ss.str());
}

bool graph::route(const node& from, const node& to)
{
    std::queue<node> q;
    q.push(from);

    std::set<node> visited;
    visited.insert(from);

    while(!q.empty())
    {
        auto next = q.front();

        if (next == to)
            return true;

        visited.insert(next);

        for (auto n : _graph[next])
            if (visited.find(n) == visited.end())
                q.push(n);

        q.pop();
    }

    return false;
}
