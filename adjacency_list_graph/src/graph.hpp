#pragma once

#include <map>
#include <set>

#include "node.hpp"

class graph
{
    public:
        void add(const node& n);

    private:
        std::map<node, std::set<node>> _graph;
};
