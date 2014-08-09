#pragma once

struct node
{
    node(int i) : key(i) { }
    int key;
};

bool operator==(const node& lhs, const node& rhs);
bool operator<(const node& lhs, const node& rhs);
