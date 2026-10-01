/*
* Date Created: 2025-02-09
* Author: Earl Pfau
* 
* Date of Last Update: 2026-09-20
* Updated by: Earl Pfau
*
* Description: This is all the input and output methods for the Investement Calculator app.
*				Prints headers and report details. Gets the users input.					
*
*/
#include "InputOutput.h"
using namespace std;


AllCalculations AllCalc;
	
	/*
	* Prints only once at the begining of the program.
	* Has no input from user.
	*/
	void InputOutput::printWelcomeScreen() {
		cout << "================================================================" << endl;
		cout << "|               Welcome to Investment Calculator               |" << endl;
		cout << "================================================================" << endl;
		cout << "| Calculates compounding interest with monthly deposits and    |" << endl;
		cout << "| without monthly deposits. You get to choose the investment   |" << endl;
		cout << "| amount, monthly deposits, interest rate, and number of years.|" << endl;
		cout << "| Prints both reports at the same time.                        |" << endl;
		cout << "================================================================" << endl << endl;
	}

	/*
	* Used only during data input from the user.
	*/
	void InputOutput::printHeader() {
		cout << "********************************" << endl;
		cout << "********** Data Input **********" << endl;
	}

	/*
	* Prints the header for the report without monthly deposits.
	* Has no input from user.
	*/
	void InputOutput::printReportHeader() {
		cout << endl;
		cout << "==================================================================" << endl;
		cout << setw(61) << right << "Balance and Interest Without Additional Monthly Deposits" << endl;
		cout << "==================================================================" << endl;
		cout << setw(5) << right << "Year" << setw(26) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;
		cout << "------------------------------------------------------------------" << endl;
	}

	/*
	* Prints the header for the report with monthly deposits.
	* Has no input from the user.
	*/
	void InputOutput::printReportHeaderWithDeposit() {
		cout << endl;
		cout << "==================================================================" << endl;
		cout << setw(61) << right << "Balance and Interest With Additional Monthly Deposits" << endl;
		cout << "==================================================================" << endl;
		cout << setw(5) << right << "Year" << setw(26) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;
		cout << "------------------------------------------------------------------" << endl;
	}

	/*
	* Prints and takes in user input for the initial investment information which stores them in temp variables which are then
	* stored in InvestmentAccountInfo class through setters.
	* 
	* This is used right after the welcome screen prints.
	* 
	* The variables that are inputted by the user are:
	*			double tempInvestmentAmount, double tempMonthlyDeposit, double tempInterestRate, int tempNumYears
	*/
	void InputOutput::getInitialInfo(InvestmentAccountInfo &UserInfo) {
		cout << "Investment Amount: $";
		while (!(cin >> tempInvestmentAmount) || tempInvestmentAmount <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number and not zero." << endl;
			cout << "Investment Amount: $";
		}
		UserInfo.SetInitialInvestAmount(tempInvestmentAmount);

		cout << "Monthly Deposit (0 or 0.00): $";
		while (!(cin >> tempMonthlyDeposit) || tempMonthlyDeposit < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number." << endl;
			cout << "Monthly Deposit (0 or 0.00): $";
		}
		UserInfo.SetMonthlyDeposit(tempMonthlyDeposit);

		cout <<"Annual Interest (0-100): ";
		while (!(cin >> tempInterestRate) ||  (tempInterestRate < 0) || (tempInterestRate > 99)  ) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number and less than 100." << endl;
			cout << "Annual Interest (0-100): ";
		}
		UserInfo.SetAnnualInterest(tempInterestRate);

		cout <<"Number of years: ";
		// TODO:: ADD AN ADDITIONAL CONDITION IF tempNumYears > 100....just for the edge case of trying to calculate extreams like 500 years or even greater.
		//			(FOR ENHANCEMTN TWO)
		while (!(cin >> tempNumYears) || tempNumYears < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number." << endl;
			cout << "Number of years: ";
		}
		UserInfo.SetNumYears(tempNumYears);
		cout << endl;
	}

	/*
	* Prints the data for both reports.
	* Has no input from the user.
	*/
	void InputOutput::printReportDetails(int t_yearIndex, double t_balance, double t_interestEarnedThisYear) {
		ostringstream oss1; 
		ostringstream oss2;
		oss1 << fixed << setprecision(2) << "$" << t_balance;
		oss2 << fixed << setprecision(2) << "$" << t_interestEarnedThisYear;
		string outBalance = oss1.str();
		string outInterestEarnedThisYear = oss2.str();
		cout << setw(5) << right << t_yearIndex;
		cout << setw(26) << right << outBalance;
		cout << setw(30) << right << outInterestEarnedThisYear;
		cout << endl << endl;
	}

	/* 
	* Prints the user inputted investment information
	* Has no input from user.
	* 
	*/
	void InputOutput::printUserInvestmentInfo(const InvestmentAccountInfo& UserInfo) {
		cout << endl;
		printHeader();
		cout << fixed << setprecision(2) << "Initial Investment Amount: $" << UserInfo.GetInitialInvestAmount() << endl;
		cout << "Monthly Deposit: $" << UserInfo.GetMonthlyDeposit() << endl;
		cout.unsetf(ios::fixed);
		cout << "Annual Interest: " << UserInfo.GetAnnualInterest() << "%" << endl;
		cout << "Number of years: " << UserInfo.GetNumYears() << endl;
	}

	/*
	* Prints the main menu and uses a switch statment for the uesrs choice.
	*  
	* The variable that is inputted by the user are:
	*			char userChoice - which is set to a null character.
	* 
	*/
	void InputOutput::menuSelection(InvestmentAccountInfo& UserInfo) {
		char userChoice = '\0';
		
		while ( (userChoice != 'q') && (userChoice != 'Q') ) {
			cout << endl;
			cout << "===================================" << endl;
			cout << "===== Please choose an option =====" << endl;
			cout << "-----------------------------------" << endl;
			cout << "1. Enter a new Investment Amount" << endl;
			cout << "2. Enter a new Monthly Deposit" << endl;
			cout << "3. Enter a new Annual Interest Rate" << endl;
			cout << "4. Enter a new Number of Years" << endl;
			cout << "5. Print the reports" << endl << endl;
			cout << "Press 'q' to quit the application" << endl;
			cout << "----------------------------------" << endl << endl;
			cout << "Please enter your selection: ";

			cin >> userChoice;

			switch (userChoice) {
			case '1': {
				cout << "New Investment Amount: $";
				while (!(cin >> tempInvestmentAmount) || tempInvestmentAmount <= 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "New Investment Amount: $";
				}
				UserInfo.SetInitialInvestAmount(tempInvestmentAmount); 
				cout << endl;
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '2': {
				cout << "New Monthly Deposit: $";
				while (!(cin >> tempMonthlyDeposit) || tempMonthlyDeposit < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "New Monthly Deposit: $";
				}
				UserInfo.SetMonthlyDeposit(tempMonthlyDeposit);
				cout << endl;
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '3': {
				cout << "New Annual Interest Rate (0-100): ";
				while (!(cin >> tempInterestRate) || (tempInterestRate < 0) || (tempInterestRate > 99)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "New Annual Interest Rate (0-100): ";
				}
				UserInfo.SetAnnualInterest(tempInterestRate);
				cout << endl;
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '4': {
				cout << "New Number of Years: ";
				while (!(cin >> tempNumYears) || tempNumYears < 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "New Number of Years: ";
				}
				UserInfo.SetNumYears(tempNumYears);
				cout << endl;
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '5': {
				
				double t_initialInvestAmount = UserInfo.GetInitialInvestAmount();
				double t_monthlyDeposit = UserInfo.GetMonthlyDeposit();
				double t_ANNUALINTEREST = UserInfo.GetAnnualInterest();
				int t_numYears = UserInfo.GetNumYears();

				AllCalc.calculateBalanceWithoutMonthlyDeposit(t_initialInvestAmount, t_ANNUALINTEREST, t_numYears);
				AllCalc.balanceWithMonthlyDeposit(t_initialInvestAmount, t_monthlyDeposit, t_ANNUALINTEREST, t_numYears);
				system("pause");
				break;
			}
			case 'q': {
				cout << endl << "Quiting the application." << endl;
				break;
			}
			default:
				cout << endl << "***************************************" << endl;
				cout << "*** Invalid choice please try again ***" << endl;
				cout << "***************************************" << endl;
				break;
			}
			
		}

	}

