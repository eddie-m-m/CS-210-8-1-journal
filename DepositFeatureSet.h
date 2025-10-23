/*
 *  DepositFeatureSet.h
 *
 *  Date: 10/3/2025
 *  Author: Eddie Menefee
 *
 * 
 */
#ifndef DEPOSITFEATURESET_H
#define DEPOSITFEATURESET_H

// one investment scenario's plain old data
struct DepositFeatureSet {
	double initialDeposit{};
	double monthlyDeposit{};
	double annualInterest{};
	int	   investmentDuration{};
};

#endif