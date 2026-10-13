/*
* Date Created: 2025-02-09
* Author: Earl Pfau
* 
* Date of Last Update: 2026-10-04
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
#include <string>
#include <cctype>
#include <algorithm>
#include "InvestmentAccountInfo.h"
#include "AllCalculations.h"



class InputOutput {
public:
	// Variables for setting and getting data from InvestmentAccountInfo
	std::string tempUsername;
	double tempInvestmentAmount;
	double tempMonthlyDeposit;
	double tempInterestRate;
	int tempNumYears;
	std::string savedUser;
	std::string userAnswer;
	std::string userInput;

	void printWelcomeScreen();
	void printHeader();
	void printReportHeader();
	void getInitialInfo(InvestmentAccountInfo& UserInfo);
	void loadUserData(InvestmentAccountInfo& UserInfo);

	std::string getUsername();
	double getUserInvestmentAmount();
	double getUserMonthlyDeposit();
	double getUserInterestRate();
	int getUserNumberYears();
	std::string toLowerCase(std::string userInput);

	void printUserInvestmentInfo(const InvestmentAccountInfo& UserInfo);
	void menuSelection(InvestmentAccountInfo& UserInfo);
	void printReportDetails(int m_yearIndex, double m_balance, double m_interestEarnedThisYear);
	void printReportHeaderWithDeposit();

private:
	int m_yearIndex;
	//double m_balance;
	double m_interestEarnedThisYear;

};


#endif //INVESTMENTCALCULATOR_INPUTOUTPUT_H_