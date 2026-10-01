/*
 * Date: 2025-02-09
 * Author: Earl Pfau
 * 
 * Description: Takes user input for Initial Investment Amount, Monthly Deposit, Annual Interest,
 *				Number of years and outputs yearly balance with and without extra monthly deposits.
 *				Allows the user to change initial input and then diaplays the information again.
 * 
 */

#include <iostream> // Input output
using namespace std;

#include "InputOutput.h" // Used to print to the screen and get user input for the most part
#include "InvestmentAccountInfo.h" // So we can create an instance of the class InvestmentAccountInfo
#include "AllCalculations.h" // Used to do the calculations for the initial user input

int main() {
	double initialInvestAmount;
	double annualInterest;
	double monthlyDeposit;
	int numYears;

	InvestmentAccountInfo UserInfo; // Creates an instance of the class to store the user data
	InputOutput InOut; // Creates an instance of the class for use in using the methods 
	AllCalculations AllCalc; // Creates an instance of the class for calling calculation methods

	

	InOut.printHeader();  // Calls the method from InputOutput
	InOut.getInitialInfo(UserInfo); // Gets the initial user input
	InOut.printInitialInfo(UserInfo); // Prints the initial user input 
	system("pause"); // Waits for the user to press any key and it also displays "Press any key to continue . . ."

	// Uses the getters from InvestmentAccountInfo to get the private variables
	initialInvestAmount = UserInfo.GetInitialInvestAmount(); 
	annualInterest = UserInfo.GetAnnualInterest();
	monthlyDeposit = UserInfo.GetMonthlyDeposit();
	numYears = UserInfo.GetNumYears();
	
	// Calls both calculations and prints the reports to the screen
	AllCalc.calculateBalanceWithoutMonthlyDeposit(initialInvestAmount, annualInterest, numYears);
	AllCalc.balanceWithMonthlyDeposit(initialInvestAmount, monthlyDeposit, annualInterest, numYears);
 
	system("pause"); // Waits for the user to press any key and it also displays "Press any key to continue . . ."
	// Menu to allow the user to change information and then allows then to either quit or print the reports
	InOut.menuSelection(UserInfo);
	
	return 0;
}