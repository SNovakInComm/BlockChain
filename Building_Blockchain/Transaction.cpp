#include "stdafx.h"
#include "Transaction.h"


// --------------------------------------------------
// ------------------------- Construtors
// --------------------------------------------------
Transaction::Transaction()
{
	_TxIn.clear();
	_TxOut.clear();
	CreateIdFromTime();
}

Transaction::Transaction(ifstream* stream)
{
	ReadTransaction(stream);
}

Transaction::~Transaction()
{
}

// --------------------------------------------------
// ------------------------- Public Methods
// --------------------------------------------------

void Transaction::CoinBase(unsigned int value, const char* ID)
{
	AddOutput(value, ID);
}

void Transaction::AddInput(TransactionInput * input)
{
	_TxIn.push_back(input);
}

void Transaction::AddInput(string* Txid, int Vout, string* ScriptSignatire)
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

void Transaction::AddOutput(int value, const char* scriptPublicSignaure)
{
	TransactionOutput* txOut = new TransactionOutput();
	txOut->value = value;
	txOut->scriptPublicSignaure = new string(scriptPublicSignaure);
	_TxOut.push_back(txOut);
}

TransactionInput* Transaction::GetInput(unsigned int index)
{
	if (index < _TxIn.size())
		return _TxIn[index];
	return nullptr;
}

TransactionOutput* Transaction::GetOutput(unsigned int index)
{
	if (index < _TxOut.size())
		return _TxOut[index];
	return nullptr;
}

string* Transaction::ToString()
{
	return _Id;
}

void Transaction::WriteTransaction(ofstream* stream)
{
	size_t numOfInputs = _TxIn.size();
	size_t numOfOutputs = _TxOut.size();
	size_t sizeOfID = _Id->length();

	stream->write((char*)&numOfInputs, sizeof(size_t));
	stream->write((char*)&numOfOutputs, sizeof(size_t));
	stream->write((char*)&sizeOfID, sizeof(size_t));

	stream->write((char*)_Id->c_str(), sizeof(sizeOfID));

	for (unsigned int i = 0; i < numOfInputs; i++)
	{
		size_t txLen = _TxIn[i]->Txid->length();
		stream->write((char*)&txLen, sizeof(size_t));
		stream->write((char*)_TxIn[i]->Txid->c_str(), txLen);

		stream->write((char*)&_TxIn[i]->Vout, sizeof(int));

		size_t scripSigLen = _TxIn[i]->ScriptSignatire->length();
		stream->write((char*)&scripSigLen, sizeof(size_t));
		stream->write((char*)_TxIn[i]->ScriptSignatire->c_str(), scripSigLen);
	}

	for (unsigned int i = 0; i < numOfOutputs; i++)
	{
		stream->write((char*)&_TxOut[i]->value, sizeof(int));

		size_t scriptPublicSignaureLen = _TxOut[i]->scriptPublicSignaure->length();
		stream->write((char*)&scriptPublicSignaureLen, sizeof(size_t));
		stream->write((char*)_TxOut[i]->scriptPublicSignaure->c_str(), scriptPublicSignaureLen);
	}
}

void Transaction::ReadTransaction(ifstream* stream)
{
	size_t numOfInputs;
	size_t numOfOutputs;
	size_t sizeOfID;

	stream->read((char*)&numOfInputs, sizeof(size_t));
	stream->read((char*)&numOfOutputs, sizeof(size_t));
	stream->read((char*)&sizeOfID, sizeof(size_t));

	_Id = new string();
	_Id->resize(sizeOfID);
	stream->read((char*)_Id->c_str(), sizeof(sizeOfID));

	for (unsigned int i = 0; i < numOfInputs; i++)
	{
		TransactionInput* newInput = new TransactionInput();
		size_t txLen;
		stream->read((char*)&txLen, sizeof(size_t));
		newInput->Txid = new string();
		newInput->Txid->resize(txLen);
		stream->read((char*)newInput->Txid->c_str(), txLen);

		stream->read((char*)&newInput->Vout, sizeof(int));

		size_t scripSigLen;
		stream->read((char*)&scripSigLen, sizeof(size_t));
		newInput->ScriptSignatire = new string();
		newInput->ScriptSignatire->resize(scripSigLen);
		stream->read((char*)newInput->ScriptSignatire->c_str(), scripSigLen);

		_TxIn.push_back(newInput);
	}


	for (unsigned int i = 0; i < numOfOutputs; i++)
	{
		TransactionOutput* newOutput = new TransactionOutput();
		stream->read((char*)&newOutput->value, sizeof(int));
		
		size_t scriptPublicSignaureLen;
		stream->read((char*)&scriptPublicSignaureLen, sizeof(size_t));
		newOutput->scriptPublicSignaure = new string();
		newOutput->scriptPublicSignaure->resize(scriptPublicSignaureLen);
		
		stream->read((char*)newOutput->scriptPublicSignaure->c_str(), scriptPublicSignaureLen);
		_TxOut.push_back(newOutput);
	}
}

int Transaction::NumberOfInputs()
{
	return _TxIn.size();
}

int Transaction::NumberOfOutputs()
{
	return _TxOut.size();
}

// --------------------------------------------------
// ------------------------- Private Methods
// --------------------------------------------------

void Transaction::CreateIdFromTime()
{
	_Id = new string();
	_Id->resize(HASH_BYTE_LENGTH);

	SHA256 hasher;
	string timestamp = to_string(time(0));
	hasher.init();
	hasher.update((const unsigned char*)timestamp.c_str(), timestamp.length());
	hasher.final((unsigned char*)_Id->c_str());
}
