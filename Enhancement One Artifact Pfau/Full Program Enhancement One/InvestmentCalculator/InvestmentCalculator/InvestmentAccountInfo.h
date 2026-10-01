#ifndef INVESTMENTCALCULATOR_INVESTMENTACCOUNTINFO_H_
#define INVESTMENTCALCULATOR_INVESTMENTACCOUNTINFO_H_

#include <iostream> // Input output

using namespace std;


class InvestmentAccountInfo {
public:

	// Constructor
	InvestmentAccountInfo();

	// Setters
	void SetInitialInvestAmount(double t_initialInvestAmount);

	void SetMonthlyDeposit(double t_monthlyDeposit);

	void SetAnnualInterest(double t_ANNUALINTEREST);

	void SetNumYears(int t_numYears);


	// Getters
	double GetInitialInvestAmount() const;

	double GetMonthlyDeposit() const;

	double GetAnnualInterest() const;

	int GetNumYears() const;

	

private:
	double m_initialInvestAmount; // Holds the initial investment amount
	double m_monthlyDeposit; // Holds the monthly deposit
	double m_ANNUALINTEREST;
	int m_numYears;
	
	
};

#endif //INVESTMENTCALCULATOR_INVESTMENTACCOUNTINFO_H_
