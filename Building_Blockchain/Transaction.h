#pragma once

#include <vector>
#include "TransactionInput.h"
#include "TransactionOutput.h"


class Transaction
{
public:
	// ------------------------- Construtors
	Transaction();
	~Transaction();

	// ------------------------- Public Methods

	// ------------------------- Public Members
	unsigned char* Id;

	vector<TransactionInput*> Vin;

	vector<TransactionOutput*> Vout;

private:
	// ------------------------- Private Methods

	// ------------------------- Private Members
};

