#pragma once

#include <map>
#include <set>
#include <string>

#include "node.hpp"
#include "edge.hpp"

class graph
{
    public:
        void add(const node& n);
        void add(const edge& e);

        std::string bf(const node& n);

        bool route(const node& from, const node& to);

        void peek() const;

    private:
        std::map<node, std::set<node>> _graph;
};
