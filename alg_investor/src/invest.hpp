#ifndef _INVEST_
#define _INVEST_

#include <string>
#include <vector>

/////////////// Offer ///////////////

struct Offer
{
    Offer() = delete;
    Offer(double invest, double profit);

    double m_invest;
    double m_profit;

    std::string ToString() const;
};

/////////////// Solution ///////////////

struct Solution
{
    std::string ToString() const;

    std::vector<Offer> m_portfolio;
    double m_invested = 0.0f;
    double m_total_profit = 0.0f;
};

/////////////// Bank ///////////////

class Bank
{
    public:
        Bank() = delete;
        Bank(double capital, const std::vector<Offer>& offers);

        const Solution& BuildPortfolio();

    private:
        std::vector<Offer> m_offers;
        const double m_capital;
        Solution m_optimalSolution;

        void _extendPortfolio(size_t next, double investedSoFar, double potentialProfit, Solution& solution);
        void _test_solution(const Solution& solution);
};

#endif // _INVEST_
