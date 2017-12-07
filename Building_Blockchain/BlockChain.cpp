#include "stdafx.h"
#include "BlockChain.h"

// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------
BlockChain::BlockChain()
{
	Block* genesisBlock = new Block(new string("Genesis Block"), nullptr);
	blocks.push_back(genesisBlock);
}


BlockChain::~BlockChain()
{

}


// --------------------------------------------------
// ------------------------- Public Mehtods
// --------------------------------------------------

void BlockChain::AddBlock(string * data)
{
	Block* prevBlock = blocks[blocks.size() - 1];
	Block* newBlock = new Block(data, prevBlock->hash);
	blocks.push_back(newBlock);
}


// --------------------------------------------------
// ------------------------- Private Mehtods
// --------------------------------------------------