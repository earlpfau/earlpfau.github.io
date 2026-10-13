/*
* Date Created: 2025-02-09
* Author: Earl Pfau
* 
* Date of Last Update: 2026-10-04
* Updated by: Earl Pfau
*
* Description: This is all the input and output methods for the Investement Calculator app.
*				Prints headers and report details. Gets the users input.					
*
*/
#include "InputOutput.h"
#include "UserDatabase.h"
#include "InvestmentAccountInfo.h"
using namespace std;


AllCalculations AllCalc;
static UserDatabase UserDB;
static InvestmentAccountInfo UserInfo;

double initialInvestAmount;
double annualInterest;
double monthlyDeposit;
int numYears;

	
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
		cout << "***********************************" << '\n';
		cout << "********** Data Input *************" << '\n';
		cout << "***********************************" << '\n';
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

	// this needs to be in the switch case as number 7 I also need to see
	// about asking for a password for it as well.

	string InputOutput::getUsername() {
		cout << "Enter Username or Full Name: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, tempUsername);

		while (tempUsername.empty() || tempUsername.length() < 4) {
			cout << "Username must be at least 4 characters in length.\n";
			cout << "Enter Username or Full Name: ";
			getline(cin, tempUsername);

		}

		return tempUsername;
	}

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

	string InputOutput::toLowerCase(string userInput) {
		transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {
			return tolower(c); });

		return userInput;
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
		cout << fixed << setprecision(2) << "Investment Amount: $" << UserInfo.GetInitialInvestAmount() << '\n';
		cout << "Monthly Deposit: $" << UserInfo.GetMonthlyDeposit() << '\n';
		cout.unsetf(ios::fixed);
		cout << "Annual Interest: " << UserInfo.GetAnnualInterest() << "%" << '\n';
		cout << "Number of years: " << UserInfo.GetNumYears() << '\n'; 
		cout << "***********************************\n\n";
	}


	void InputOutput::loadUserData(InvestmentAccountInfo& UserInfo) {

		string t_Choice;
		string t_RetryChoice;

		while (true) {
			cout << "Would you like to load a saved user? (yes/no): ";
			cin >> t_Choice;

			if (InputOutput::toLowerCase(t_Choice) == "yes") {

				while (true) {
					cout << "Please enter the username: ";
					cin >> savedUser;

					if (UserDB.LoadUser(savedUser, UserInfo)) {
						cout << "Loaded User Data Successfully.\n\n";
						InputOutput::printUserInvestmentInfo(UserInfo);
						cout << "\n";
						return;
					}
					else {
						cout << "**User not found.**\n\n";
						cout << "Would you like to try again (yes) or start fresh (no): ";
						cin >> t_RetryChoice;

						if (InputOutput::toLowerCase(t_RetryChoice) == "no") {
							cout << '\n';
							break;
						}
					}
				}
				break;
			}
			else if (InputOutput::toLowerCase(t_Choice) == "no") {
				cout << '\n';
				break;
			}
			else {
				cout << "Invlaid choice. Please type yes or no. \n\n";
			}
		}
		InputOutput::printHeader();
		InputOutput::getInitialInfo(UserInfo);

		double t_initialInvestAmount = UserInfo.GetInitialInvestAmount();
		double t_monthlyDeposit = UserInfo.GetMonthlyDeposit();
		double t_ANNUALINTEREST = UserInfo.GetAnnualInterest();
		int t_numYears = UserInfo.GetNumYears();
		AllCalc.calculateBalanceWithoutMonthlyDeposit(t_initialInvestAmount, t_ANNUALINTEREST, t_numYears);
		AllCalc.calculateBalanceWithMonthlyDeposit(t_initialInvestAmount, t_monthlyDeposit, t_ANNUALINTEREST, t_numYears);
	}

	/*
	* Prints the main menu and uses a switch statment for the uesrs choice.
	*  
	* The variable that is inputted by the user are:
	*			char userChoice - which is set to a null character.
	* 
	*/
	void InputOutput::menuSelection(InvestmentAccountInfo& UserInfo) {
		char t_UserChoice = '\0';
		string t_SaveInfo;

		InputOutput InOut;
		
		while ( (t_UserChoice != 'q') && (t_UserChoice != 'Q') ) {
			cout << "\n===================================\n";
			cout << "===== Please choose an option =====\n";
			cout << "-----------------------------------\n";
			cout << "1. Enter a new Investment Amount\n";
			cout << "2. Enter a new Monthly Deposit\n";
			cout << "3. Enter a new Annual Interest Rate\n";
			cout << "4. Enter a new Number of Years\n";
			cout << "5. Enter ALL new information\n";
			cout << "6. Print the reports\n";
			cout << "7. Print investment information\n";
			cout << "8. Load Saved User Information\n";
			cout << "Press 'q' to quit the application\n";
			cout << "----------------------------------\n" << endl;
			cout << "Please enter your selection: ";

			cin >> t_UserChoice;

			switch (t_UserChoice) {
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
			case '7': {
				InputOutput::printUserInvestmentInfo(UserInfo);
				//cout << "\n";
				break;
			}
			case '8': {
				InOut.loadUserData(UserInfo);
				break;
			}
			case 'q': {
				cout << "Do you want to save your investment information for next time(yes or no)? ";
				cin >> t_SaveInfo;
				
				if (InputOutput::toLowerCase(t_SaveInfo) == "yes") {
					InputOutput::getUsername();
					UserInfo.SetUsername(tempUsername);
					cout << "Saving your investment information...\n";
					// take in a password to encrypt the data and to load the user information
					UserDatabase db;

					db.SaveUserInfo(UserInfo.GetUsername(), UserInfo.GetInitialInvestAmount(), UserInfo.GetMonthlyDeposit(),
									UserInfo.GetAnnualInterest(), UserInfo.GetNumYears());
				}
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

