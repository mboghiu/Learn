#include "test.hpp"
#include "node.hpp"

#include <sstream>
#include <string>
#include <queue>

template<typename T>
std::string bft_newline(node<T>* root)
{
    if (root == nullptr)
        return "";

    std::stringstream ss;

    std::queue<node<T>> q;
    q.push(*root);

    while(!q.empty())
    {
        auto n = q.front();
        ss << n.value;
        if (n.left != nullptr) q.push(*n.left);
        if (n.right != nullptr) q.push(*n.right);
        q.pop();
    }

    return std::move(ss.str());
}

int main()
{
    test<std::string>("", bft_newline<int>(nullptr));
    test<std::string>("3", bft_newline<int>(new node<int>(3)));
    test<std::string>("A", bft_newline<std::string>(new node<std::string>("A")));

    test<std::string>("AKC", bft_newline<std::string>(
            new node<std::string>("A",
                new node<std::string>("K"),
                new node<std::string>("C")
            )));

    return 0;
}
