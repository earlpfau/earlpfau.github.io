/*
* Date Created: 2025-02-09
* Author: Earl Pfau
* 
* Date of Last Update: 2026-09-19
* Updated by: Earl Pfau
* 
* Description: This is the header file for InputOutput.cpp, it only delcares methods and variables.
*			   other files that are needed for this file is InvestmentAccountInfo.h and AllCalculations.h
* 
*/


#ifndef INVESTMENTCALCULATOR_INPUTOUTPUT_H_
#define INVESTMENTCALCULATOR_INPUTOUTPUT_H_


#include <iostream>
#include <iomanip>
#include <sstream>
#include "InvestmentAccountInfo.h"
#include "AllCalculations.h"

using namespace std;

class InputOutput {
public:
	// Temp variables for setting and getting data from InvestmentAccountInfo
	double tempInvestmentAmount;
	double tempMonthlyDeposit;
	double tempInterestRate;
	int tempNumYears;
	
	void printWelcomeScreen();
	void printHeader();
	void printReportHeader();
	void getInitialInfo(InvestmentAccountInfo& UserInfo); 
	void printUserInvestmentInfo(const InvestmentAccountInfo& UserInfo);
	void menuSelection(InvestmentAccountInfo& UserInfo);
	void printReportDetails(int m_yearIndex, double m_balance, double m_interestEarnedThisYear);
	void printReportHeaderWithDeposit();

private:
	int m_yearIndex;
	double m_balance;
	double m_interestEarnedThisYear;

};


#endif //INVESTMENTCALCULATOR_INPUTOUTPUT_H_