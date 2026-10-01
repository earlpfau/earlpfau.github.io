#include <iostream>
// Put the includes that are needed
using namespace std;

#include "AllCalculations.h"

InputOutput InOut; // Creates an instance of InputOutput to use the methods

// Method to do all the calculations and print for the report with out monthly deposits
void AllCalculations::calculateBalanceWithoutMonthlyDeposit(double& m_initialInvestAmount, double& m_ANNUALINTEREST, int& m_numYears) {
	int t_yearIndex; // Index for the outter loop
	int t_monthIndex; // Index for the inner loop
	double t_balance = m_initialInvestAmount; // Sets the balance to be the initial balance
	double t_interestEarnedMonth = 0.0; // Stores the interest earned each month
	double t_interestEarnedThisYear = 0.0; // Stores the interest earned for that year. I could of done this probably with out this one
	
	InOut.printReportHeader(); // Calls to print the header for the report
	// Loop to go through earch year and month to calculate the compounding interest
	for (t_yearIndex = 1; t_yearIndex <= m_numYears; t_yearIndex++) {
		t_interestEarnedThisYear = 0.0; // Resets the interest to 0 before the next 12 months are calculated

		for (t_monthIndex = 1; t_monthIndex <= 12; t_monthIndex++) {
			t_interestEarnedMonth = t_balance * ((m_ANNUALINTEREST / 100.0) / 12);
			t_balance += t_interestEarnedMonth;
			t_interestEarnedThisYear += t_interestEarnedMonth;
		}
		// Calls and passes the information to print the information for the year in the report
		InOut.printReportDetails(t_yearIndex, t_balance, t_interestEarnedThisYear);
	}
	cout << endl;
}

// Method to do all the calculations and print for the report with monthly deposits
void AllCalculations::balanceWithMonthlyDeposit(double& m_initialInvestAmount, double& m_monthlyDeposit, double& m_ANNUALINTEREST, int& m_numYears) {
	int t_yearIndex; // Index for the outter loop
	int t_monthIndex; // Index for the inner loop
	double t_balance = m_initialInvestAmount; // Sets the balance to be the initial balance
	double t_interestEarnedMonth = 0.0; // Stores the interest earned each month
	double t_interestEarnedThisYear = 0.0; // Stores the interest earned for that year. I could of done this probably with out this one
	
	InOut.printReportHeaderWithDeposit(); // Calls to print the header for the report
	// Loop to go through earch year and month to calculate the compounding interest
	for (t_yearIndex = 1; t_yearIndex <= m_numYears; t_yearIndex++) {
		t_interestEarnedThisYear = 0.0; // Resets the interest to 0 before the next 12 months are calculated

		for (t_monthIndex = 1; t_monthIndex <= 12; t_monthIndex++) {
			t_interestEarnedMonth = (t_balance + m_monthlyDeposit) * ((m_ANNUALINTEREST / 100.0) / 12);
			t_balance += t_interestEarnedMonth + m_monthlyDeposit;
			t_interestEarnedThisYear += t_interestEarnedMonth;
		}
		// Calls and passes the information to print the information for the year in the report
		InOut.printReportDetails(t_yearIndex, t_balance, t_interestEarnedThisYear);
	}
	cout << endl;
}


