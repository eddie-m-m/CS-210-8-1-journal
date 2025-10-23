/*
 *  DepositSimulator.cpp
 *
 *  Date: 10/3/2025
 *  Author: Eddie Menefee
 *
 * 
 */
#include "DepositSimulator.h"
#include "DepositFeatureSet.h"
#include "StaticReport.h"
#include <print>
#include <iostream>
#include <vector>
#include <string>


// show deposit menu for input
void DepositSimulator::display(DepositFeatureSet t_depositFS) const
{
	std::cout << "\n\n";
	std::print(
		"{0}\n"
		"*********** {1:<10} ***********\n"
		"{2:<21} ${7:.2f}\n"
		"{3:<26} ${8:.2f}\n"
		"{4:<26} %{9}\n"
		"{5:<26} {10}\n"
		"{6:<21}\n",
		std::string(34, '*'),
		"Data Input", "Initial Investment Amount:", "Monthly Deposit:",
		"Annual Interest:", "Number of years:", "Press any key to continue...",
		t_depositFS.initialDeposit, t_depositFS.monthlyDeposit,
		t_depositFS.annualInterest, t_depositFS.investmentDuration
	);
};

// run one investment scenario
DepositFeatureSet DepositSimulator::run() {

	double initialDeposit{};
	double monthlyDeposit{};
	double annualInterest{};
	int investmentDuration{};

	std::cout << "\n";
	std::string title{ "Data Input" };

	std::println("{:*<30}", "");
	std::println("******** {:^12} ********", title);

	
	std::string dummy_string{};

	// collect inputs from user for investment scenario
	std::cout << "Initial Investment Amount: ";
	while (!(std::cin >> initialDeposit)) {
		std::cout << "\nInvalid input. Please enter a number:\n";
		std::cin.clear();
		std::getline(std::cin, dummy_string);
	}

	std::cout << "Monthly Deposit: ";
	while (!(std::cin >> monthlyDeposit)) {
		std::cout << "\nInvalid input. Please enter a number:\n";
		std::cin.clear();
		std::getline(std::cin, dummy_string);
	}

	std::cout << "Annual Interest: ";
	while (!(std::cin >> annualInterest)) {
		std::cout << "\nInvalid input. Please enter a number:\n";
		std::cin.clear();
		std::getline(std::cin, dummy_string);
	}

	std::cout << "Number of years: ";
	while (!(std::cin >> investmentDuration)) {
		std::cout << "\nInvalid input. Please enter a number:\n";
		std::cin.clear();
		std::getline(std::cin, dummy_string);
	}

	
	DepositFeatureSet deposit{ initialDeposit,monthlyDeposit,
							annualInterest,investmentDuration };

	return deposit;
}


