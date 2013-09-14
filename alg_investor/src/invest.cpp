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
    std::ostringstream iss;

    iss << "("
        << "I:\033[36m" << m_invest << "\033[0m,"
        << "P:\033[36m" << m_profit << "\033[0m"
        << ")";

    return (std::move(iss.str()));
}


/////////////// Bank ///////////////

Bank::Bank(double capital, const std::vector<Offer>& offers) :
    m_offers(offers),
    m_capital(capital),
    m_invested(0),
    m_potentialProfit(0)
{ }

//static void ExtendPortfolio(std::stack<Offer>& partialPortfolio, double& profitSoFar, double& investmentSoFar, const std::vector<Offer>& offers)
//{
//
//}

std::stack<Offer> Bank::BuildPortfolio()
{
    std::stack<Offer> portfolio;

    
    return (std::move(portfolio));
}
