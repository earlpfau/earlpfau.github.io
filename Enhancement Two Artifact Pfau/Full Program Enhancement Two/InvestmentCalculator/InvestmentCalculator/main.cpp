/*
 * Date Created: 2025-02-09
 * Author: Earl Pfau
 * 
 * Date Updated: 2026-09-17
 * Updated by: Earl Pfau
 * 
 * Description: The Investment Calculator App, Calculates the compounding interest by calculating
 *				the monthly deposits firt then calculating the interest.
				Takes user input for Initial Investment Amount, Monthly Deposit, Annual Interest,
 *				Number of years and outputs yearly balance with and without extra monthly deposits.
 *				Allows the user to change initial input and then diaplays the information again.
 *				
 * 
 */

#include <iostream> 

using namespace std;

#include "InputOutput.h" 
#include "InvestmentAccountInfo.h" 
#include "AllCalculations.h" 

int main() {
	double initialInvestAmount;
	double annualInterest;
	double monthlyDeposit;
	int numYears;

	InvestmentAccountInfo UserInfo; 
	InputOutput InOut; 
	AllCalculations AllCalc; 

	InOut.printWelcomeScreen();
	system("pause");
	InOut.printHeader();  
	InOut.getInitialInfo(UserInfo); 
	system("pause"); 

	// Uses the getters from InvestmentAccountInfo to get the private variables
	initialInvestAmount = UserInfo.GetInitialInvestAmount(); 
	annualInterest = UserInfo.GetAnnualInterest();
	monthlyDeposit = UserInfo.GetMonthlyDeposit();
	numYears = UserInfo.GetNumYears();
	
	// Calls both calculations and prints the reports to the screen
	AllCalc.calculateBalanceWithoutMonthlyDeposit(initialInvestAmount, annualInterest, numYears);
	AllCalc.calculateBalanceWithMonthlyDeposit(initialInvestAmount, monthlyDeposit, annualInterest, numYears);
 
	system("pause");
	
	InOut.menuSelection(UserInfo);
	
	return 0;
}