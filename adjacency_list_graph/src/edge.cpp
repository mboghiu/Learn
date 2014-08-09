#include "edge.hpp"

bool operator==(const edge& lhs, const edge& rhs)
{
    return lhs.from == rhs.from && lhs.to == rhs.to;
}
