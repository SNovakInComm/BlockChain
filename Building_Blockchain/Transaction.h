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

	void AddInput(TransactionInput * in);

	void AddInput(char* Txid, int Vout, string* ScriptSignatire);

	void AddOutput(TransactionOutput * output);

	void AddOutput(int value, string* scriptPublicSignaure);

	TransactionInput* GetInput(unsigned int index);

	TransactionOutput* GetOutput(unsigned int index);

	// ------------------------- Public Members
	

private:
	// ------------------------- Private Members
	unsigned char* _Id;

	vector<TransactionInput*> _TxIn;

	vector<TransactionOutput*> _TxOut;

	// ------------------------- Private Methods
};

