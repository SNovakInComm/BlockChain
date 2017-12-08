#include "stdafx.h"
#include "Transaction.h"


// --------------------------------------------------
// ------------------------- Construtors
// --------------------------------------------------
Transaction::Transaction()
{
	_TxIn.clear();
	_TxOut.clear();
}

Transaction::~Transaction()
{
}

// --------------------------------------------------
// ------------------------- Public Methods
// --------------------------------------------------

void Transaction::AddInput(TransactionInput * input)
{
	_TxIn.push_back(input);
}

void Transaction::AddInput(char* Txid, int Vout, string* ScriptSignatire)
{
	TransactionInput* txIn = new TransactionInput();
	txIn->Txid = Txid;
	txIn->Vout = Vout;
	txIn->ScriptSignatire = ScriptSignatire;
	_TxIn.push_back(txIn);
}

void Transaction::AddOutput(TransactionOutput * output)
{
	_TxOut.push_back(output);
}

void Transaction::AddOutput(int value, string* scriptPublicSignaure)
{
	TransactionOutput* txOut = new TransactionOutput();
	txOut->value = value;
	txOut->scriptPublicSignaure = scriptPublicSignaure;
	_TxOut.push_back(txOut);
}

TransactionInput* Transaction::GetInput(unsigned int index)
{
	if (index < _TxIn.size())
		return _TxIn[index];
}

TransactionOutput* Transaction::GetOutput(unsigned int index)
{
	if (index < _TxOut.size())
		return _TxOut[index];
}

// --------------------------------------------------
// ------------------------- Private Methods
// --------------------------------------------------


