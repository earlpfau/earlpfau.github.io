#ifndef INVESTMENTCALCULATOR_ALLCALCULATIONS_H_
#define INVESTMENTCALCULATOR_ALLCALCULATIONS_H_

#include "InvestmentAccountInfo.h" // Used to pass variables by reference to do calcualtions with
#include "InputOutput.h" // Used to call the printDetails for printing information in the reports
using namespace std;

class AllCalculations {
public:
	// Calculates and prints the report with out monthly deposits
	void calculateBalanceWithoutMonthlyDeposit(double& m_initialInvestAmount, double& m_ANNUALINTEREST, int& m_numYears);
	// Calculates and prints the report with monthly deposits
	void balanceWithMonthlyDeposit(double& m_initialInvestment, double& m_monthlyDeposit, double& m_ANNUALINTEREST, int& m_numYears);

	// Variables used in the calculations
	int m_yearIndex;
	double m_balance;
	double m_interestEarnedThisYear;

};
#endif //INVESTMENTCALCULATOR_ALLCALCULATIONS_H_