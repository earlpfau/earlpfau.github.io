#ifndef INVESTMENTCALCULATOR_INPUTOUTPUT_H_
#define INVESTMENTCALCULATOR_INPUTOUTPUT_H_


#include <iostream> // Input output
#include <iomanip> // Used to set the percision of digits after the decimal point
#include <sstream> // Used to create a string with '$' and a user number to output in reports
				   // so its aligned to the right without issues.
#include "InvestmentAccountInfo.h" // So we can use data and methods that was created
#include "AllCalculations.h" // Used to do the calculations from the menu

using namespace std;

class InputOutput {
public:
	// Temp variables for setting and getting data from InvestmentAccountInfo
	double tempInvestmentAmount;
	double tempMonthlyDeposit;
	double tempInterestRate;
	int tempNumYears;
	
	// These all declare methods
	void printHeader(); // Method that prints the header for user information
	void printReportHeader(); // Method that prints the header for the report with out monthly deposits
	void getInitialInfo(InvestmentAccountInfo& UserInfo); // Used to get the initial information from the user
	void printInitialInfo(const InvestmentAccountInfo& UserInfo); // Used to print the initial information
	void menuSelection(InvestmentAccountInfo& UserInfo); // Prints the menu that the user can chose from to update information
	void printDetails(int m_yearIndex, double m_balance, double m_interestEarnedThisYear); // Prints details for both reports
	void printReportHeaderWithDeposit(); // Method that prints the header for the report with monthly deposits

private:
	int m_yearIndex; // Stores the current year for use in the printDetails and loops
	double m_balance; // Stores the balance for printing
	double m_interestEarnedThisYear; // Stores the interest earned for printing

};


#endif //INVESTMENTCALCULATOR_INPUTOUTPUT_H_