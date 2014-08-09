#pragma once

struct node
{
    node(int i) : key(i) { }
    int key;
};

struct edge
{
    edge(const node& from, const node& to) :
        from(from),
        to(to)
    { }

    node from;
    node to;
};

bool operator==(const node& lhs, const node& rhs);
bool operator==(const edge& lhs, const edge& rhs);
