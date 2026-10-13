/*
* Date Created: 2026-09-29
* Author: Earl Pfau
*
* Date of Last Update: 2026-10-04
* Updated by: Earl Pfau
*
* Description: This is the header file for UserDatabase.cpp, this is where the Json database methods live.
*
*/

#ifndef INVESTMENTCALCULATOR_USERDATABASE_H_
#define INVESTMENTCALCULATOR_USERDATABASE_H_

#include "json.h"
#include "InvestmentAccountInfo.h"
#include <fstream>

using json = nlohmann::json;

class UserDatabase {
public:
	UserDatabase();

	void SaveDatabase();
	void LoadDatabase();

	void SaveUserInfo(const std::string& t_username, double t_investAmount,
					  double t_monthlyDeposit, double t_interestRate, int t_numYears);

	bool LoadUser(const std::string& username, InvestmentAccountInfo& outInfo);


private: 
	json m_db;
	 
};


#endif //INVESTMENTCALCULATOR_USERDATABASE_H_