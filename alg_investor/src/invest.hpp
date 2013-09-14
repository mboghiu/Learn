#ifndef _INVEST_
#define _INVEST_

#include <string>
#include <vector>
#include <stack>

/////////////// Offer ///////////////

struct Offer
{
    Offer() = delete;
    Offer(double invest, double profit);

    double m_invest;
    double m_profit;

    std::string ToString() const;
};

/////////////// Bank ///////////////

class Bank
{
    public:
        Bank() = delete;
        Bank(double capital, const std::vector<Offer>& offers);

        std::stack<Offer> BuildPortfolio();

    private:
        std::vector<Offer> m_offers;
        double m_capital;

        double m_invested;
        double m_potentialProfit;
};

#endif // _INVEST_
