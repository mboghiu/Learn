#pragma once

#include "node.hpp"

struct edge
{
    edge(const node& from, const node& to) :
        from(from),
        to(to)
    { }

    node from;
    node to;
};

bool operator==(const edge& lhs, const edge& rhs);
