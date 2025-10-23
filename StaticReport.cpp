/*
 *  StaticReport.cpp
 *
 *  Date: 10/6/2025
 *  Author: Eddie Menefee
 *
 *
 */
#include "StaticReport.h"
#include <print>
#include <string>

// create static report for investment with single (initial) deposit
void StaticReport::generateSingleDepositOutcome() const {
  int year{};
  double monthlyInterestRate{m_depositScenario.annualInterest / 100.0 / 12.0};
  double currentBalance{m_depositScenario.initialDeposit};
  int monthlyDuration{m_depositScenario.investmentDuration * 12};
  double annualOpeningBalance{m_depositScenario.initialDeposit};

  for (int i = 1; i <= monthlyDuration; ++i) {
    currentBalance += currentBalance * monthlyInterestRate;

    // only print 12 months worth of interest at a time (annual interest)
    if (i % 12 == 0) {
      year++;
      double annualInterestEarned{currentBalance - annualOpeningBalance};

      std::println("{:<30}${:<29.2f}${:<29.2f}\n", year, currentBalance,
                   annualInterestEarned);

      annualOpeningBalance = currentBalance;
    }
  }
};

// create static report for investment with monthly deposits
void StaticReport::generateMonthlyDepositOutcome() const {
  int year{};
  double monthlyInterestRate{m_depositScenario.annualInterest / 100.0 / 12.0};
  double currentBalance{m_depositScenario.initialDeposit};
  int monthlyDuration{m_depositScenario.investmentDuration * 12};
  double annualOpeningBalance{m_depositScenario.initialDeposit};

  for (int i = 1; i <= monthlyDuration; ++i) {
    currentBalance += m_depositScenario.monthlyDeposit;
    currentBalance += currentBalance * monthlyInterestRate;

    // only print 12 months worth of interest at a time (annual interest)
    if (i % 12 == 0) {
      year++;
      double annualInterestEarned{(currentBalance - annualOpeningBalance) -
                                  (12 * m_depositScenario.monthlyDeposit)};
      std::println("{:<30}${:<29.2f}${:<29.2f}\n", year, currentBalance,
                   annualInterestEarned);

      annualOpeningBalance = currentBalance;
    }
  }
};

// output one static report, depending on report type
void StaticReport::display(std::string t_title, ReportType t_reportType) const {
  std::print("\n\n{:^90}\n"
             "{:=<90}\n"
             "{:<30}{:<30}{:<30}\n"
             "{:-<90}\n\n",
             t_title, "", "Year", "Year End Balance",
             "Year End Earned Interest", "");

  // calculate on the fly given the report type
  t_reportType == ReportType::SingleDeposit ? generateSingleDepositOutcome()
                                            : generateMonthlyDepositOutcome();
};
