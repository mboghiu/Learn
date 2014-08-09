#include "node.hpp"

bool operator==(const node& lhs, const node& rhs)
{
    return lhs.key == rhs.key;
}

bool operator==(const edge& lhs, const edge& rhs)
{
    return lhs.from == rhs.from && lhs.to == rhs.to;
}
