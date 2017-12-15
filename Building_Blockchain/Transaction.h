#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "TransactionInput.h"
#include "TransactionOutput.h"


class Transaction
{
public:
	// ------------------------- Construtors
	Transaction();
	Transaction(ifstream* stream);
	~Transaction();

	// ------------------------- Public Methods

	void CoinBase(unsigned int value, const char*);

	void AddInput(TransactionInput * in);

	void AddInput(string* Txid, int Vout, string* ScriptSignatire);

	void AddOutput(TransactionOutput * output);

	void AddOutput(int value, string* scriptPublicSignaure);
	
	void AddOutput(int value, const char* scriptPublicSignaure);

	TransactionInput* GetInput(unsigned int index);

	TransactionOutput* GetOutput(unsigned int index);

	string* ToString();

	void WriteTransaction(ofstream* stream);
	
	void ReadTransaction(ifstream* stream);

	int NumberOfInputs();

	int NumberOfOutputs();

	// ------------------------- Public Members
	

private:
	// ------------------------- Private Members
	string* _Id;

	vector<TransactionInput*> _TxIn;

	vector<TransactionOutput*> _TxOut;

	// ------------------------- Private Methods
	void CreateIdFromTime();
};

