#pragma once

#include <string>
#include <ctime>
#include "Types.h"
#include "Sha256.h"

using namespace std;

class TransactionInput
{
public:
	// ------------------------- Constructors
	TransactionInput();

	TransactionInput(unsigned int outputIndex, const char* signature);

	~TransactionInput();

	// ------------------------- Public Methods

	string* Txid;

	unsigned int Vout;

	string* ScriptSignatire;

private:
	// ------------------------- Private Methods

	// ------------------------- Private Members


};

