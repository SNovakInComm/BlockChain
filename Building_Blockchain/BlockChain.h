#pragma once

#include <vector>
#include <string>
#include "Block.h"

class BlockChain
{
public:

	// ------------------------- Constructors
	BlockChain();
	~BlockChain();

	// ------------------------- Public Methods

	void AddBlock(string* blockToAdd);

	vector<Block*> blocks;

private:
	// ------------------------- Private Members


	// ------------------------- Private Methods

};

