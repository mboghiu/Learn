#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>

#include "utils.hpp"

#include "invest.hpp"

int main()
{
    while (true)
    {
        ///////////// Read user input ////////////

        double capital;

        int n;

        std::vector<Offer> offers; 

        utils::read_input<Offer>(std::cin, capital, n, offers);

        if (capital == 0.0f)
            exit(0);

        ///////////// Process ///////////

        std::cout << "Building portfolio for capital \033[1;37m"
                  << capital << "\033[0m with \033[1;37m" << n << "\033[0m offers: ";

        for (auto& offer : offers)
            std::cout << offer.ToString() << " ";

        std::cout << std::endl;

        std::stack<Offer> portfolio = Bank(capital, offers).BuildPortfolio();

        ///////////// Print results ///////////

        std::cout << "\033[32mPortfolio: \033[0m";

        while (!portfolio.empty())
        {
            std::cout << portfolio.top().ToString() << " ";
            portfolio.pop();
        }

        std::cout << std::endl;
    }

    return 0;
}
