#include "test.hpp"
#include "node.hpp"

#include <sstream>
#include <string>
#include <queue>
#include <cmath>

template<typename T>
std::string bft_newline(node<T>* root)
{
    if (root == nullptr)
        return "";

    std::stringstream ss;

    std::queue<node<T>> q;
    q.push(*root);

    int depth = 0;
    int missing_nodes_next_level = 0;
    double nodes_on_this_level = std::pow(2, depth) - missing_nodes_next_level;

    while(!q.empty())
    {
        auto n = q.front();
        q.pop();
        nodes_on_this_level--;

        ss << n.value << (nodes_on_this_level == 0 ? "\n" : "");
        if (n.left != nullptr) q.push(*n.left);
        else missing_nodes_next_level++;
        if (n.right != nullptr) q.push(*n.right);
        else missing_nodes_next_level++;

        if (nodes_on_this_level == 0)
        {
            depth++;
            nodes_on_this_level = std::pow(2, depth) - missing_nodes_next_level;
            missing_nodes_next_level = 0;
        }
    }

    return std::move(ss.str().substr(0, ss.str().find_last_of('\n')));
}

int main()
{
    test<std::string>("", bft_newline<int>(nullptr));
    test<std::string>("3", bft_newline<int>(new node<int>(3)));
    test<std::string>("A", bft_newline<std::string>(new node<std::string>("A")));

    test<std::string>("A\nKC", bft_newline<std::string>(
            new node<std::string>("A",
                new node<std::string>("K"),
                new node<std::string>("C")
            )));

    test<std::string>("A\nKC\nDE", bft_newline<std::string>(
            new node<std::string>("A",
                new node<std::string>("K",
                    nullptr,
                    new node<std::string>("D")),
                new node<std::string>("C",
                    nullptr,
                    new node<std::string>("E"))
            )));

    return 0;
}
