#pragma once

#include <string>

using namespace std;

class TransactionOutput
{
public:
	// ------------------------- Constructors
	TransactionOutput();
	~TransactionOutput();

	// ------------------------- Public Methods

	// ------------------------- Public Members

	int value;

	string* scriptPublicSignaure;

private:
	// ------------------------- Private Methods

	// ------------------------- Private Members

};

