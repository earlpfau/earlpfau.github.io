/*
* Date Created: 2025-02-09
* Author: Earl Pfau
*
* Date of Last Update: 2026-09-22
* Updated by: Earl Pfau
*
* Description:
*
*/

#include <iostream>
#include "AllCalculations.h"

using namespace std;

InputOutput InOut; 

// Method to do all the calculations and print for the report with out monthly deposits
void AllCalculations::calculateBalanceWithoutMonthlyDeposit(double m_initialInvestAmount, double m_annualInterest, int m_numYears) {
	int t_yearIndex; 
	int t_monthIndex; 
	double t_balance = m_initialInvestAmount; 
	double t_interestEarnedMonth = 0.0; 
	double t_interestEarnedThisYear = 0.0; 
	const double t_monthlyRate = (m_annualInterest / 100.00) / 12.0; 

	InOut.printReportHeader(); 

	for (t_yearIndex = 1; t_yearIndex <= m_numYears; t_yearIndex++) {
		t_interestEarnedThisYear = 0.0; 
	
		for (t_monthIndex = 1; t_monthIndex <= 12; t_monthIndex++) {
			t_interestEarnedMonth = t_balance * t_monthlyRate;
			t_balance += t_interestEarnedMonth;
			t_interestEarnedThisYear += t_interestEarnedMonth;
		}
		
		InOut.printReportDetails(t_yearIndex, t_balance, t_interestEarnedThisYear);
	}
	cout << '\n';
}

// Method to do all the calculations and print for the report with monthly deposits
void AllCalculations::calculateBalanceWithMonthlyDeposit(double m_initialInvestAmount, double m_monthlyDeposit, double m_annualInterest, int m_numYears) {
	int t_yearIndex; 
	int t_monthIndex; 
	double t_balance = m_initialInvestAmount; 
	double t_interestEarnedMonth = 0.0; 
	double t_interestEarnedThisYear = 0.0;
	const double t_monthlyRate = (m_annualInterest / 100.0) / 12.0;
	
	InOut.printReportHeaderWithDeposit(); 

	for (t_yearIndex = 1; t_yearIndex <= m_numYears; t_yearIndex++) {
		t_interestEarnedThisYear = 0.0;

		for (t_monthIndex = 1; t_monthIndex <= 12; t_monthIndex++) {
			t_balance += m_monthlyDeposit;
			t_interestEarnedMonth = t_balance * t_monthlyRate;
			t_balance += t_interestEarnedMonth;
			t_interestEarnedThisYear += t_interestEarnedMonth;
		}
		
		InOut.printReportDetails(t_yearIndex, t_balance, t_interestEarnedThisYear);
	}
	cout << '\n';
}

