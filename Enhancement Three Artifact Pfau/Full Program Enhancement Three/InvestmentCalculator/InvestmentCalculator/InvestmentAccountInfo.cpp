/*
* Date Created: 2025-02-09
* Author: Earl Pfau
*
* Date of Last Update: 2026-09-22
* Updated by: Earl Pfau
*
* Description: This holds all the user investment information to keep it away from everything else.
*
*/

#include "InvestmentAccountInfo.h"

using namespace std;

// Constructor
InvestmentAccountInfo::InvestmentAccountInfo() {
	m_username = "";
	m_initialInvestAmount = 0.0;
	m_monthlyDeposit = 0.0;
	m_ANNUALINTEREST = 0.0;
	m_numYears = 0;
}

// Setters
void InvestmentAccountInfo::SetUsername(string t_username) {
	m_username = t_username;
}
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
string InvestmentAccountInfo::GetUsername() const {
	return m_username;
}
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

