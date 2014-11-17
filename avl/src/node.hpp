#pragma once

struct node
{
    node(int v, node* p);

    int v;
    node* left;
    node* right;
    node* parent;

    int balance();
};

bool operator==(const node& lhs, const node& rhs);
