#pragma once

#include <map>
#include <set>

#include "node.hpp"
#include "edge.hpp"

class graph
{
    public:
        void add(const node& n);
        void add(const edge& e);

    private:
        std::map<node, std::set<node>> _graph;
};
