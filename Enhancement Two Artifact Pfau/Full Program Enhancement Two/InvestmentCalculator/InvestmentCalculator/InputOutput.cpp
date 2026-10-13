/*
* Date Created: 2025-02-09
* Author: Earl Pfau
* 
* Date of Last Update: 2026-09-22
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
		cout << "================================================================" << '\n';
		cout << "|               Welcome to Investment Calculator               |" << '\n';
		cout << "================================================================" << '\n';
		cout << "| Calculates compounding interest with monthly deposits at the |" << '\n';
		cout << "| begining of the month and without monthly deposits.          |" << '\n';
		cout << "| You get to choose the investment amount, monthly deposits,   |" << '\n';
		cout << "| interest rate, and number of years.                          |" << '\n';
		cout << "| Prints both reports at the same time.                        |" << '\n';
		cout << "================================================================" << '\n' << '\n';
	}

	/*
	* Used only during data input from the user.
	*/
	void InputOutput::printHeader() {
		cout << "********************************" << '\n';
		cout << "********** Data Input **********" << '\n';
	}

	/*
	* Prints the header for the report without monthly deposits.
	* Has no input from user.
	*/
	void InputOutput::printReportHeader() {
		cout << "\n==================================================================\n";
		cout << setw(61) << right << "Balance and Interest Without Additional Monthly Deposits\n";
		cout << "==================================================================\n";
		cout << setw(5) << right << "Year" << setw(26) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest\n";
		cout << "------------------------------------------------------------------\n";
	}

	/*
	* Prints the header for the report with monthly deposits.
	* Has no input from the user.
	*/
	void InputOutput::printReportHeaderWithDeposit() {
		cout << "\n==================================================================\n";
		cout << setw(61) << right << "Balance and Interest With Additional Monthly Deposits\n";
		cout << "==================================================================\n";
		cout << setw(5) << right << "Year" << setw(26) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest\n";
		cout << "------------------------------------------------------------------\n";
	}

	/*
	* Gets the users investment information for tempInvestmentAmount, tempMonthlyDeposit, 
	* tempInterestRate, and tempNumYears. This is so it can be reused in other methods.
	* 
	* Used in the getInitialInfo() and menuSelection()
	*/
	double InputOutput::getUserInvestmentAmount() {
		cout << "Investment Amount: $";
		while (!(cin >> tempInvestmentAmount) || tempInvestmentAmount <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number and not zero.\n";
			cout << "Investment Amount: $";
		}
		
		return tempInvestmentAmount;
	}

	double InputOutput::getUserMonthlyDeposit() {
		cout << "Monthly Deposit (0 or 0.00): $";
		while (!(cin >> tempMonthlyDeposit) || tempMonthlyDeposit < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number.\n";
			cout << "Monthly Deposit (0 or 0.00): $";
		}
		return tempMonthlyDeposit;
	}

	double InputOutput::getUserInterestRate() {
		cout << "Annual Interest (0-100): ";
		while (!(cin >> tempInterestRate) || (tempInterestRate < 0) || (tempInterestRate > 100)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number and less than 100.\n";
			cout << "Annual Interest (0-100): ";
		}
		return tempInterestRate;
	}

	int InputOutput::getUserNumberYears() {
		cout << "Number of years: ";
		while (!(cin >> tempNumYears) || tempNumYears < 1 || tempNumYears > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be a non-negative number between 1-100.\n";
			cout << "Number of years (1-100): ";
		}
		return tempNumYears;
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

		tempInvestmentAmount = getUserInvestmentAmount();
		UserInfo.SetInitialInvestAmount(tempInvestmentAmount);

		tempMonthlyDeposit = getUserMonthlyDeposit();
		UserInfo.SetMonthlyDeposit(tempMonthlyDeposit);

		tempInterestRate = getUserInterestRate();
		UserInfo.SetAnnualInterest(tempInterestRate);

		tempNumYears = getUserNumberYears();
		UserInfo.SetNumYears(tempNumYears);
		cout << '\n';
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
		cout << setw(30) << right << outInterestEarnedThisYear << '\n' << '\n';
	}

	/* 
	* Prints the user inputted investment information
	* Has no input from user.
	*/
	void InputOutput::printUserInvestmentInfo(const InvestmentAccountInfo& UserInfo) {
		//cout << '\n';
		printHeader();
		cout << fixed << setprecision(2) << "Initial Investment Amount: $" << UserInfo.GetInitialInvestAmount() << '\n';
		cout << "Monthly Deposit: $" << UserInfo.GetMonthlyDeposit() << '\n';
		cout.unsetf(ios::fixed);
		cout << "Annual Interest: " << UserInfo.GetAnnualInterest() << "%" << '\n';
		cout << "Number of years: " << UserInfo.GetNumYears() << '\n';
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
			cout << "\n===================================\n";
			cout << "===== Please choose an option =====\n";
			cout << "-----------------------------------\n";
			cout << "1. Enter a new Investment Amount\n";
			cout << "2. Enter a new Monthly Deposit\n";
			cout << "3. Enter a new Annual Interest Rate\n";
			cout << "4. Enter a new Number of Years\n";
			cout << "5. Enter ALL new information\n";
			cout << "6. Print the reports" << '\n' << '\n';
			cout << "Press 'q' to quit the application\n";
			cout << "----------------------------------\n" << endl;
			cout << "Please enter your selection: ";

			cin >> userChoice;

			switch (userChoice) {
			case '1': {
				tempInvestmentAmount = getUserInvestmentAmount();
				UserInfo.SetInitialInvestAmount(tempInvestmentAmount); 
				cout << '\n';
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '2': {
				tempMonthlyDeposit = getUserMonthlyDeposit();
				UserInfo.SetMonthlyDeposit(tempMonthlyDeposit);
				cout << '\n';
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '3': {
				tempInterestRate = getUserInterestRate();
				UserInfo.SetAnnualInterest(tempInterestRate);
				cout << '\n';
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '4': {
				tempNumYears = getUserNumberYears();
				UserInfo.SetNumYears(tempNumYears);
				cout << '\n';
				InputOutput::printUserInvestmentInfo(UserInfo);
				break;
			}
			case '5': {
				InputOutput::getInitialInfo(UserInfo);
				break;
			}
			case '6': {
				
				double t_initialInvestAmount = UserInfo.GetInitialInvestAmount();
				double t_monthlyDeposit = UserInfo.GetMonthlyDeposit();
				double t_ANNUALINTEREST = UserInfo.GetAnnualInterest();
				int t_numYears = UserInfo.GetNumYears();

				AllCalc.calculateBalanceWithoutMonthlyDeposit(t_initialInvestAmount, t_ANNUALINTEREST, t_numYears);
				AllCalc.calculateBalanceWithMonthlyDeposit(t_initialInvestAmount, t_monthlyDeposit, t_ANNUALINTEREST, t_numYears);
				system("pause");
				break;
			}
			case 'q': {
				cout << "\nQuiting the application.\n";
				break;
			}
			default:
				cout << "\n***************************************\n";
				cout << "*** Invalid choice please try again ***\n";
				cout << "***************************************\n";
				break;
			}
			
		}

	}

