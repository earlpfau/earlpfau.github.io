/*
* Date Created: 2026-09-29
* Author: Earl Pfau
*
* Date of Last Update: 2026-10-04
* Updated by: Earl Pfau
*
* Description: This is all for the Json database that the application uses.
*
*/

#include "UserDatabase.h"

using namespace std;

/*
* Loads the databaswe into the application for use,
* Also loads the user data as well.
*/

UserDatabase::UserDatabase() {
	LoadDatabase();
}


void UserDatabase::LoadDatabase() {
	ifstream in("database.json");

	if (in.good()) {
		m_db = json::parse(in);
	}
	else {
		m_db["Users"] = json::array();
	}
}


/*
* Saves the actual database.
*/

void UserDatabase::SaveDatabase() {
	ofstream out("database.json");
	out << m_db.dump(4);
}

/*
* Saves the user data to the json file
*/
void UserDatabase::SaveUserInfo(const string& t_username, double t_investAmount,
								double t_monthlyDeposit, double t_interestRate, int t_numYears) {
	json userJson = {
		{"username", t_username},
		{"investment_Amount", t_investAmount},
		{"monthly_Deposit", t_monthlyDeposit},
		{"interest_Rate", t_interestRate},
		{"number_Of_Years", t_numYears}
	};
	m_db["Users"].push_back(userJson);
	SaveDatabase();
}

/*
* Loads the saved user data from the Json file.
*/
bool UserDatabase::LoadUser(const std::string& username, InvestmentAccountInfo& outInfo) {
	for (auto& user : m_db["Users"]) {
		if (user["username"] == username) {
			outInfo.SetUsername(user["username"]);
			outInfo.SetInitialInvestAmount(user["investment_Amount"]);
			outInfo.SetMonthlyDeposit(user["monthly_Deposit"]);
			outInfo.SetAnnualInterest(user["interest_Rate"]);
			outInfo.SetNumYears(user["number_Of_Years"]);

			return true;
		}
	}
	return false;
}



