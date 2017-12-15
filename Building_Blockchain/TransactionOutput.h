#pragma once

#include <string>

using namespace std;

class TransactionOutput
{
public:
	// ------------------------- Constructors
	TransactionOutput();

	TransactionOutput(unsigned int Value, const char* scriptSig);

	~TransactionOutput();

	// ------------------------- Public Methods

	// ------------------------- Public Members

	unsigned int value;

	string* scriptPublicSignaure;

private:
	// ------------------------- Private Methods

	// ------------------------- Private Members

};

