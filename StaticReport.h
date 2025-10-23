/*
*  StaticReport.h
*
*  Date: 10/6/2025
*  Author: Eddie Menefee
*
* 
*/
#ifndef STATICREPORT_H
#define STATICREPORT_H

#include "DepositFeatureSet.h"
#include <string>

// static reports for single (initial) deposit and monthly deposits
enum class ReportType {
	SingleDeposit,
    MonthlyDeposit,
};

// investment scenario outcome
class StaticReport {
private:
	DepositFeatureSet m_depositScenario{};

public:
	StaticReport(DepositFeatureSet t_depositScenario) : m_depositScenario{ t_depositScenario } {};

	// create static report for investment with single (initial) deposit
	void generateSingleDepositOutcome() const;

	// create static report for investment with monthly deposits
	void generateMonthlyDepositOutcome() const;

	// show a static report 
	void display(std::string, ReportType) const;

};

#endif