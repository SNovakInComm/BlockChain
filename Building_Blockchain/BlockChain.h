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

	// make private
	int _proofZeroLength;

private:
	// ------------------------- Private Members
	

	// ------------------------- Private Methods

};

