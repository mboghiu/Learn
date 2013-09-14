#include <sstream>
#include <iostream>
#include <algorithm>

#include "invest.hpp"


/////////////// Offer ///////////////

Offer::Offer(double invest, double profit) :
    m_cost(invest),
    m_benefit(profit)
{ }

std::string Offer::ToString() const
{
    std::ostringstream oss;

    oss << "("
        << "I:\033[36m" << m_cost << "\033[0m,"
        << "P:\033[36m" << m_benefit << "\033[0m"
        << ")";

    return (std::move(oss.str()));
}

/////////////// Solution ///////////////

std::string Solution::ToString() const
{
    return ToString(32);
}

std::string Solution::ToString(int color) const
{
    std::ostringstream oss;

    oss << "\033[" << color << "m" << std::endl
        << "Portfolio: "
        << "\033[0m";

    for (auto& offer : m_portfolio)
        oss << offer.ToString() << " | ";

    oss << std::endl;

    oss << "\033[" << color << "m";
    oss << "Total invested: " << m_invested << std::endl;
    oss << "Total profit:   " << m_total_profit << std::endl;
    oss << "\033[0m";

    return (std::move(oss.str()));
}

void Solution::AddOffer(const Offer& offer)
{
    m_portfolio.push_back(offer);
    m_invested += offer.m_cost;
    m_total_profit += offer.m_benefit;
}

bool operator==(const Offer& lhs, const Offer& rhs)
{
    return (lhs.m_cost == rhs.m_cost and lhs.m_benefit == rhs.m_benefit);
}

void Solution::RemoveOffer(const Offer& offer)
{
    m_portfolio.erase(std::find(m_portfolio.begin(), m_portfolio.end(), offer));
    m_invested -= offer.m_cost;
    m_total_profit -= offer.m_benefit;
}

/////////////// Bank ///////////////

Bank::Bank(double capital, const std::vector<Offer>& offers) :
    m_offers(offers),
    m_capital(capital)
{ }

void Bank::_extendPortfolio(size_t next, double& investedSoFar, double potentialProfit, Solution& solutionCandidate)
{
    if (next == m_offers.size())
    {
        _test_solution(solutionCandidate);
    }
    else
    {
        std::cout << "trying to extend with @" << next << "-->" << m_offers.at(next).ToString()
                  << " investedSoFar: " << investedSoFar << " potentialProfit: " << potentialProfit;

        Offer candidateOffer = m_offers.at(next);

        if (investedSoFar + candidateOffer.m_cost <= m_capital)
        {
            solutionCandidate.AddOffer(candidateOffer);
            investedSoFar += candidateOffer.m_cost;
            
            std::cout << std::endl << "ACCEPTING offer " << candidateOffer.ToString() << "; candidate solution: " << solutionCandidate.ToString();

            _extendPortfolio(next + 1, investedSoFar, potentialProfit, solutionCandidate);
        }
        
        if (potentialProfit - candidateOffer.m_benefit >= m_optimalSolution.m_total_profit)
        {
            solutionCandidate.RemoveOffer(candidateOffer);
            investedSoFar -= candidateOffer.m_cost;

            std::cout << std::endl << "REJECTING ofofer " << candidateOffer.ToString() << "; candidate solution: " << solutionCandidate.ToString();

            _extendPortfolio(next + 1, investedSoFar, potentialProfit - candidateOffer.m_benefit, solutionCandidate);
        }
    }
}

void Bank::_test_solution(const Solution& solutionCandidate)
{
    std::cout << "\033[31mTesting solution\033[0m" << solutionCandidate.ToString(31) << std::endl;

    if (solutionCandidate.m_total_profit > m_optimalSolution.m_total_profit or
       (solutionCandidate.m_total_profit == m_optimalSolution.m_total_profit and
        solutionCandidate.m_invested < m_optimalSolution.m_invested))
    {
        m_optimalSolution = solutionCandidate;
    }    
}

static inline double GetSum(const std::vector<Offer>& offers)
{
    double totalPotentialProfit = 0.0f;

    for (auto& offer : offers)
        totalPotentialProfit += offer.m_benefit;

    return totalPotentialProfit;
}

const Solution& Bank::BuildPortfolio()
{
    Solution solutionCandidate;

    double investedSoFar = 0.0f;

    std::cout << "start ------------------------------------------------------------------------" << std::endl;

    _extendPortfolio(0, investedSoFar, GetSum(m_offers), solutionCandidate);

    std::cout << "end ------------------------------------------------------------------------" << std::endl;
    
    return m_optimalSolution;
}
