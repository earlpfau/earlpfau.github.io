
#include "InputOutput.h"
using namespace std;


AllCalculations AllCalc;

	// Prints a header for all data inputs
	void InputOutput::printHeader() {
		cout << "********************************" << endl;
		cout << "********** Data Input **********" << endl;
	}

	// Prints the report header only for report with out monthly deposits
	void InputOutput::printReportHeader() {
		cout << endl;
		cout << "==================================================================" << endl;
		cout << setw(61) << right << "Balance and Interest Without Additional Monthly Deposits" << endl;
		cout << "==================================================================" << endl;
		cout << setw(5) << right << "Year" << setw(26) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;
		cout << "------------------------------------------------------------------" << endl;
	}

	// Prints the report header only for the report with monthly deposits
	void InputOutput::printReportHeaderWithDeposit() {
		cout << endl;
		cout << "==================================================================" << endl;
		cout << setw(61) << right << "Balance and Interest With Additional Monthly Deposits" << endl;
		cout << "==================================================================" << endl;
		cout << setw(5) << right << "Year" << setw(26) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;
		cout << "------------------------------------------------------------------" << endl;
	}

	// Gets all the initial inputs from the user and stores in temp variables then stores them in the InvestmentAccountInfo class
	void InputOutput::getInitialInfo(InvestmentAccountInfo &UserInfo) {
		cout << "Initial Investment Amount: ";
		
		while (!(cin >> tempInvestmentAmount) || tempInvestmentAmount < 0) {
			cin.clear(); // Ensures that the input stream is clear
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
			cout << "Invalid input. Must be a non-negative number." << endl;
			cout << "Initial Investment Amount: ";
		}
		UserInfo.SetInitialInvestAmount(tempInvestmentAmount);

		cout << "Monthly Deposit: ";
		while (!(cin >> tempMonthlyDeposit) || tempMonthlyDeposit < 0) {
			cin.clear(); // Ensures that the input stream is clear
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
			cout << "Invalid input. Must be a non-negative number." << endl;
			cout << "Initial Investment Amount: ";
		}
		UserInfo.SetMonthlyDeposit(tempMonthlyDeposit);

		cout <<"Annual Interest: ";
		while (!(cin >> tempInterestRate) ||  (tempInterestRate < 0) || (tempInterestRate > 99)  ) {
			cin.clear(); // Ensures that the input stream is clear
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
			cout << "Invalid input. Must be a non-negative number and less than 100." << endl;
			cout << "Initial Investment Amount: ";
		}
		UserInfo.SetAnnualInterest(tempInterestRate);

		cout <<"Number of years: ";
		while (!(cin >> tempNumYears) || tempNumYears < 1) {
			cin.clear(); // Ensures that the input stream is clear
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
			cout << "Invalid input. Must be a non-negative number." << endl;
			cout << "Initial Investment Amount: ";
		}
		UserInfo.SetNumYears(tempNumYears);
		cout << endl;
	}

	// Prints the data for both reports
	void InputOutput::printDetails(int t_yearIndex, double t_balance, double t_interestEarnedThisYear) {
		// Creates and allows us to create a string with the '$' and the information in one
		ostringstream oss1; 
		ostringstream oss2;
		// Stores our data to a string so we can output it properly when the values change
		oss1 << fixed << setprecision(2) << "$" << t_balance;
		oss2 << fixed << setprecision(2) << "$" << t_interestEarnedThisYear;
		string outBalance = oss1.str();
		string outInterestEarnedThisYear = oss2.str();
		// Sets the width of the data in the reports and aligns them to the right
		// this is why we had to set it as a string so it aligned right correctly
		cout << setw(5) << right << t_yearIndex;
		cout << setw(26) << right << outBalance;
		cout << setw(30) << right << outInterestEarnedThisYear;
		cout << endl << endl;
	}

	// Prints the information that the user inputs so the user can see any and all changes
	void InputOutput::printInitialInfo(const InvestmentAccountInfo& UserInfo) {
		cout << endl;
		printHeader();
		cout << fixed << setprecision(2) << "Initial Investment Amount: $" << UserInfo.GetInitialInvestAmount() << endl;
		cout << "Monthly Deposit: $" << UserInfo.GetMonthlyDeposit() << endl;
		cout.unsetf(ios::fixed); // Removed the fixed precision so it prints the rest in correct form
		cout << "Annual Interest: %" << UserInfo.GetAnnualInterest() << endl;
		cout << "Number of years: " << UserInfo.GetNumYears() << endl;
		
	}

	
	// Displays the menu and also gets the user input
	void InputOutput::menuSelection(InvestmentAccountInfo& UserInfo) {
		char userChoice = '\0'; // Sets the userChoice to a null character just as a placeholder so it will go through the while statement
		
		// While statement that terminates when the user inputs 'q' or 'Q'
		while ( (userChoice != 'q') && (userChoice != 'Q') ) {
			cout << endl;
			cout << "================================" << endl;
			cout << "==== Please choose an option ====" << endl;
			cout << "--------------------------------" << endl;
			cout << "1. Enter a new Investment Amount" << endl;
			cout << "2. Enter a new Monthly Deposit" << endl;
			cout << "3. Enter a new Annual Interest" << endl;
			cout << "4. Enter a new Number of Years" << endl;
			cout << "5. Print the reports" << endl;
			cout << "Press 'q' to quit the application" << endl;

			cin >> userChoice;

			// Switch statment that also checks the values to make sure its what we want
			switch (userChoice) {
			case '1': {
				cout << "New Initial Investment Amount: ";
				while (!(cin >> tempInvestmentAmount) || tempInvestmentAmount < 0) {
					cin.clear(); // Ensures that the input stream is clear
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "Initial Investment Amount: ";
				}
				UserInfo.SetInitialInvestAmount(tempInvestmentAmount); // Sets the userinput to the private member of InvestementAccountInfo
				cout << endl;
				InputOutput::printInitialInfo(UserInfo); // Reprints the users data so they can see the changes
				break;
			}
			case '2': {
				cout << "New Monthly Deposit: ";
				while (!(cin >> tempMonthlyDeposit) || tempMonthlyDeposit < 0) {
					cin.clear(); // Ensures that the input stream is clear
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "Initial Investment Amount: ";
				}
				UserInfo.SetMonthlyDeposit(tempMonthlyDeposit); // Sets the userinput to the private member of InvestementAccountInfo
				cout << endl;
				InputOutput::printInitialInfo(UserInfo); // Reprints the users data so they can see the changes
				break;
			}
			case '3': {
				cout << "New Annual Interest: ";
				while (!(cin >> tempInterestRate) || (tempInterestRate < 0) || (tempInterestRate > 99)) {
					cin.clear(); // Ensures that the input stream is clear
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "Initial Investment Amount: ";
				}
				UserInfo.SetAnnualInterest(tempInterestRate); // Sets the userinput to the private member of InvestementAccountInfo
				cout << endl;
				InputOutput::printInitialInfo(UserInfo); // Reprints the users data so they can see the changes
				break;
			}
			case '4': {
				cout << "New Number of Years: ";
				while (!(cin >> tempNumYears) || tempNumYears < 1) {
					cin.clear(); // Ensures that the input stream is clear
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the entire line all the way to the newline character
					cout << "Invalid input. Must be a non-negative number." << endl;
					cout << "Initial Investment Amount: ";
				}
				UserInfo.SetNumYears(tempNumYears); // Sets the userinput to the private member of InvestementAccountInfo
				cout << endl;
				InputOutput::printInitialInfo(UserInfo); // Reprints the users data so they can see the changes
				break;
			}
			case '5': {
				
				double t_initialInvestAmount = UserInfo.GetInitialInvestAmount();
				double t_monthlyDeposit = UserInfo.GetMonthlyDeposit();
				double t_ANNUALINTEREST = UserInfo.GetAnnualInterest();
				int t_numYears = UserInfo.GetNumYears();

				AllCalc.calculateBalanceWithoutMonthlyDeposit(t_initialInvestAmount, t_ANNUALINTEREST, t_numYears);
				AllCalc.balanceWithMonthlyDeposit(t_initialInvestAmount, t_monthlyDeposit, t_ANNUALINTEREST, t_numYears);
				system("pause"); // Waits for the user to press any key and it also displays "Press any key to continue . . ."
				break;
			}
			case 'q': {
				cout << endl << "Quiting the application." << endl;
				break;
			}
			// Default case so it catches all inputs that are not part of the switch statement
			default:
				cout << endl << "***************************************" << endl;
				cout << "*** Invalid choice please try again ***" << endl;
				cout << "***************************************" << endl;
				break;
			}
			
		}

	}

