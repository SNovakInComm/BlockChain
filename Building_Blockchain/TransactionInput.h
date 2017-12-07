#pragma once

#include <string>

using namespace std;

class TransactionInput
{
public:
	// ------------------------- Constructors
	TransactionInput();
	~TransactionInput();

	// ------------------------- Public Methods

	char* Txid;

	int Vout;

	string* ScriptSignatire;

private:
	// ------------------------- Private Methods

	// ------------------------- Private Members


};

