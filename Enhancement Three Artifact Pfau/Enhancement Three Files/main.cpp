/*
*  ***** *   * *       * ***** ***** ***** *       * ***** *   * *****
*    *   **  *  *     *  *     *       *   **     ** *     **  *   *
*    *   * * *   *   *   ****  *****   *   * *   * * ****  * * *   *
*    *   *  **    * *    *         *   *   *  * *  * *     *  **   *
*  ***** *   *     *     ***** *****   *   *   *   * ***** *   *   *
* 
*  *****     *     *     ***** *   * *         *     ***** ***** *****
*  *        * *    *     *     *   * *        * *      *   *   * *   *
*  *       *****   *     *     *   * *       *****     *   *   * *****
*  *      *     *  *     *     *   * *      *     *    *   *   * * *
*  ***** *       * ***** ***** ***** ***** *       *   *   ***** *  *
* 
 * Date Created: 2025-02-09
 * Author: Earl Pfau
 * 
 * Date Updated: 2026-10-04
 * Updated by: Earl Pfau
 * 
 * Description: The Investment Calculator App, Calculates the compounding interest by calculating
 *				the monthly deposits firt then calculating the interest.
				Takes user input for Initial Investment Amount, Monthly Deposit, Annual Interest,
 *				Number of years and outputs yearly balance with and without extra monthly deposits.
 *				Allows the user to save/load (unencrypted) saved user investment data from a Json file.
 *				The Json file doesn't hold any Persnal Identification Information (PII) at all. So I
 *				feel at this time encryption was not nessesary.
 * 
 */

#include <iostream> 

using namespace std;

#include "InputOutput.h" 
#include "InvestmentAccountInfo.h" 
#include "AllCalculations.h" 

// The one and only
int main() {

	InvestmentAccountInfo UserInfo; 
	InputOutput InOut; 
	AllCalculations AllCalc; 

	InOut.printWelcomeScreen();
	
	system("pause");

	InOut.loadUserData(UserInfo);
	
	InOut.menuSelection(UserInfo);
	
	return 0;
}