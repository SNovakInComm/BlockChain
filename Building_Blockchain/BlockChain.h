#pragma once

#include <vector>
#include <string>
#include "Block.h"
#include <fstream>
#include "ProofOfWork.h"

class BlockChain
{
public:

	// ------------------------- Constructors
	BlockChain(unsigned int leadingZerosForProof);
	BlockChain(string* fileName);
	BlockChain();
	~BlockChain();

	vector<Block*> blocks;
	// ------------------------- Public Methods

	void AddBlock(string* blockToAdd);

	void SaveChain(string* fileName);

	void LoadChain(string* fileName);

	void SaveChain(const char* fileName);

	void LoadChain(const char* fileName);


	bool CreateTransaction(string* fromID, string* toID, unsigned int amount);

	bool CreateTransaction(TransactionOutput* CoinBase, string* toID);

	// make private
	int _proofZeroLength;

	vector<Transaction> transactionsWaiting;

private:
	// ------------------------- Private Members
	unsigned int _head;
	

	// ------------------------- Private Methods
	vector<TransactionOutput*>* SearchForAmount(string* user, unsigned int amount);

};

