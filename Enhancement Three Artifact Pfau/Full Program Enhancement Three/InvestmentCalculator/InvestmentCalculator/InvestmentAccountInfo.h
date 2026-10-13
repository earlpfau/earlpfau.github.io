/*
* Date Created: 2025-02-09
* Author: Earl Pfau
*
* Date of Last Update: 2026-09-22
* Updated by: Earl Pfau
*
* Description: This is the header file for investrmentAccountInfo.cpp
*
*/

#ifndef INVESTMENTCALCULATOR_INVESTMENTACCOUNTINFO_H_
#define INVESTMENTCALCULATOR_INVESTMENTACCOUNTINFO_H_

#include <iostream>
#include <string>


class InvestmentAccountInfo {
public:

	// Constructor
	InvestmentAccountInfo();

	// Setters
	void SetUsername(std::string t_username);

	void SetInitialInvestAmount(double t_initialInvestAmount);

	void SetMonthlyDeposit(double t_monthlyDeposit);

	void SetAnnualInterest(double t_ANNUALINTEREST);

	void SetNumYears(int t_numYears);


	// Getters
	std::string GetUsername() const;

	double GetInitialInvestAmount() const;

	double GetMonthlyDeposit() const;

	double GetAnnualInterest() const;

	int GetNumYears() const;



private:
	std::string m_username;
	double m_initialInvestAmount;
	double m_monthlyDeposit;
	double m_ANNUALINTEREST;
	int m_numYears;


};

#endif //INVESTMENTCALCULATOR_INVESTMENTACCOUNTINFO_H_