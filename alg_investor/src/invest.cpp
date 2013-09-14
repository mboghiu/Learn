#include <sstream>
#include <iostream>

#include "invest.hpp"


/////////////// Offer ///////////////

Offer::Offer(double invest, double profit) :
    m_invest(invest),
    m_profit(profit)
{ }

std::string Offer::ToString() const
{
    std::ostringstream oss;

    oss << "("
        << "I:\033[36m" << m_invest << "\033[0m,"
        << "P:\033[36m" << m_profit << "\033[0m"
        << ")";

    return (std::move(oss.str()));
}

/////////////// Solution ///////////////

std::string Solution::ToString() const
{
    std::ostringstream oss;

    oss << std::endl
        << "Portfolio: ";

    for (auto& offer : m_portfolio)
        oss << offer.ToString() << " ";

    oss << std::endl;

    oss << "Total invested: " << m_invested << std::endl;
    oss << "Total profit:   " << m_total_profit << std::endl;

    return (std::move(oss.str()));
}

/////////////// Bank ///////////////

Bank::Bank(double capital, const std::vector<Offer>& offers) :
    m_offers(offers),
    m_capital(capital)
{ }

void Bank::_extendPortfolio(size_t next, double investedSoFar, double potentialProfit, Solution& solution)
{
    if (next == m_offers.size())
    {
        _test_solution(solution);
    }
    else
    {
        Offer candidate = m_offers.at(next);

        /*
            TRY accepting it
        */

        if (investedSoFar + candidate.m_invest <= m_capital)
        {
            solution.m_portfolio.push_back(candidate);
            _extendPortfolio(next + 1, investedSoFar + candidate.m_invest, potentialProfit, solution);
        }
        
        /*
            TRY rejecting it
        */

        if (potentialProfit - candidate.m_profit >= m_optimalSolution.m_total_profit)
        {
            _extendPortfolio(next + 1, investedSoFar, potentialProfit - candidate.m_profit, solution);
        }
    }
}

void Bank::_test_solution(const Solution& solution)
{
    if (solution.m_total_profit > m_optimalSolution.m_total_profit or
       (solution.m_total_profit == m_optimalSolution.m_total_profit and
        solution.m_invested < m_optimalSolution.m_invested))
    {
        m_optimalSolution = solution;
    }    
}

const Solution& Bank::BuildPortfolio()
{
    double totalPotentialProfit = 0.0f;

    for (auto& offer : m_offers)
        totalPotentialProfit += offer.m_profit;

    Solution solution;
    _extendPortfolio(0, 0.0f, totalPotentialProfit, solution);
    
    return m_optimalSolution;
}
