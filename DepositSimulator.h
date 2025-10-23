/*
 *  DepositSimulator.h
 *
 *  Date: 10/3/2025
 *  Author: Eddie Menefee
 *
 * 
 */
#ifndef DEPOSITSIMULATION_H
#define DEPOSITSIMULATION_H

#include "DepositFeatureSet.h"


// one investment scenario
class DepositSimulator {

public:
	// show the user's inputs
	void display(DepositFeatureSet) const;

	// run one investment scenario
	DepositFeatureSet run();
};


#endif
