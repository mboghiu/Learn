#include "node.hpp"

bool operator==(const node& lhs, const node& rhs)
{
    return lhs.key == rhs.key;
}

bool operator<(const node& lhs, const node& rhs)
{
    return lhs.key < rhs.key;
}
