#pragma once

#include <vector>
#include "Block.h"

class BlockChain
{
public:

	// ------------------------- Constructors
	BlockChain();
	~BlockChain();

	// ------------------------- Public Methods

	void addBlock(Block* blockToAdd);

private:
	// ------------------------- Private Members
	vector<Block> theChain;

	// ------------------------- Private Methods

};

