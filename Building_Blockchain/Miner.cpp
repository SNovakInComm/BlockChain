#include "stdafx.h"
#include "Miner.h"

// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------
Miner::Miner()
{
}


Miner::~Miner()
{
}


// --------------------------------------------------
// ------------------------- Public Methods
// --------------------------------------------------

Block* Miner::MineBlock(Block* blockToMine, const char* minerId) 
{
	ProofOfWork Prover;

	Transaction* coinBase = new Transaction();

	coinBase->CoinBase(50000, minerId);

	blockToMine->transactions.push_back(coinBase);

	Prover.Prove(blockToMine, _zeroCriteria);

	return blockToMine;
}

void Miner::setZeroCriteria(int digitsNeeded)
{
	_zeroCriteria = digitsNeeded;
}

// --------------------------------------------------
// ------------------------- Private Methods
// --------------------------------------------------