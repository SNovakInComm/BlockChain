#pragma once

#include "Block.h"
#include "ProofOfWork.h"

class Miner
{
public:
	// ------------------------- Construtors
	Miner();

	~Miner();

	// ------------------------- Public Methods

	Block* MineBlock(Block* blockToMine, const char* minerId);

	void setZeroCriteria(int digitsNeeded);

private:
	// ------------------------- Private Methods

	// ------------------------- Private Members
	int _zeroCriteria;

};

