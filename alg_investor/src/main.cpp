#include <iostream>
#include <cstdio>
#include <vector>

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

        std::cout << "Building portfolio for capital \033[1;37m"
                  << capital << "\033[0m with \033[1;37m" << n << "\033[0m offers: ";

        for (auto& offer : offers)
            std::cout << offer.ToString() << " ";

        std::cout << std::endl;

        ///////////// Process ///////////

        std::cout << Bank(capital, offers).BuildPortfolio().ToString();
    }
}
