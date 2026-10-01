

using namespace std;

#include "InvestmentAccountInfo.h"


// Constructor
InvestmentAccountInfo::InvestmentAccountInfo() {
	m_initialInvestAmount = 0.0;
	m_monthlyDeposit = 0.0;
	m_ANNUALINTEREST = 0.0;
	m_numYears = 0;
}

// Setters
void InvestmentAccountInfo::SetInitialInvestAmount(double t_initialInvestAmount) {
	 m_initialInvestAmount = t_initialInvestAmount;
}
void InvestmentAccountInfo::SetMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}
void InvestmentAccountInfo::SetAnnualInterest(double t_ANNUALINTEREST) {
	m_ANNUALINTEREST = t_ANNUALINTEREST;
}
void InvestmentAccountInfo::SetNumYears(int t_numYears) {
	m_numYears = t_numYears;
}


// Getters
double InvestmentAccountInfo::GetInitialInvestAmount() const {
	return m_initialInvestAmount;
}
double InvestmentAccountInfo::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}
double InvestmentAccountInfo::GetAnnualInterest() const {
	return m_ANNUALINTEREST;
}
int InvestmentAccountInfo::GetNumYears() const {
	return m_numYears;
}




