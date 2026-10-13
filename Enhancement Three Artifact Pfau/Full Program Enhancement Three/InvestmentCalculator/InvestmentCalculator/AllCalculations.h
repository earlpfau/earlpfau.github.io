/*
* Date Created: 2025-02-09
* Author: Earl Pfau
*
* Date of Last Update: 2026-09-22
* Updated by: Earl Pfau
*
* Description: This is the header file for AllCalculations.cpp, the calculations for all investment is here.
*
*/

#ifndef INVESTMENTCALCULATOR_ALLCALCULATIONS_H_
#define INVESTMENTCALCULATOR_ALLCALCULATIONS_H_

#include "InvestmentAccountInfo.h" 
#include "InputOutput.h" 

class AllCalculations {
public:
	// Calculates and prints the report with out monthly deposits
	void calculateBalanceWithoutMonthlyDeposit(double m_initialInvestAmount, double m_annualInterest, int m_numYears);
	
	// Calculates and prints the report with monthly deposits
	void calculateBalanceWithMonthlyDeposit(double m_initialInvestAmount, double m_monthlyDeposit, double m_annualInterest, int m_numYears);

};

#endif //INVESTMENTCALCULATOR_ALLCALCULATIONS_H_