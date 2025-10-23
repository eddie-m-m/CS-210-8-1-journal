/*
 *  main.cpp
 *
 *  Date: 10/6/2025
 *  Author: Eddie Menefee
 *
 *  NOTE: contains C++23 features
 * 
 * 
 */
#include <iostream>
#include <limits>

#include "DepositSimulator.h"
#include "DepositFeatureSet.h"
#include "StaticReport.h"


int main() {


	// run investment scenarios for as long as user wants
	for (;;) {

		// greet user
		std::cout << "\nWelcome to Airgead Banking's Investment Simulator!\n\n";

		// create an investment scenario
		DepositSimulator depositSimulator{};

		// collect user's inputs for the investment scenario
		DepositFeatureSet depositScenario = depositSimulator.run();

		// show user the basis of the forthcoming static reports
		depositSimulator.display(depositScenario);

		// pause for user's decision to continue
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();

		// show outcomes of the given investment scenario
		StaticReport staticReport{ depositScenario };
		staticReport.display("Balance and Interest Without Additional Monthly Deposits", ReportType::SingleDeposit);
		staticReport.display("Balance and Interest With Additional Monthly Deposits", ReportType::MonthlyDeposit);

		// give user option to run another investment scenario
		int answer{};
		for (;;) {
			std::cout << "\nWould you like to try another investment scenario?\n";
			std::cout << " 1: Yes\n";
			std::cout << " 2: No\n";
			std::cin >> answer;

			// validate user's choice
			if (std::cin.fail() || (answer != 1 && answer != 2)) {
				std::cout << "\nInvalid input. Please enter one of the two options.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}

		if (answer == 2) {
			break; 
		}


	}
}
