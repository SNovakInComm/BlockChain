#include "stdafx.h"
#include "BlockChain.h"

// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------

BlockChain::BlockChain(unsigned int leadingZerosForProof)
{
	_proofZeroLength = leadingZerosForProof;
	Block* genesisBlock = new Block(new string("Genesis"), nullptr);
	blocks.push_back(genesisBlock);
}

BlockChain::BlockChain()
{
	Block* genesisBlock = new Block(new string("Genesis Block"), nullptr);
	blocks.push_back(genesisBlock);
}

BlockChain::BlockChain(string* fileName)
{
	ifstream fileIn;
	fileIn.open(fileName->c_str(), ios::in);
	unsigned long long numberOfBlocks;
	
	fileIn.read((char*)&numberOfBlocks, sizeof(unsigned long long));

	for(int i=0; i<numberOfBlocks; i++)
	{
		blocks.push_back(new Block(&fileIn));
	}

	fileIn.close();
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

	ProofOfWork prover;
	prover.Prove(newBlock, _proofZeroLength);

	blocks.push_back(newBlock);
}

void BlockChain::SaveChain(string* fileName)
{
	ofstream fileStream;
	fileStream.open(fileName->c_str() , ios::out);
	unsigned long long numberOfBlocks = blocks.size();
	fileStream.write((char*)&numberOfBlocks, sizeof(unsigned long long));
	for (unsigned int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->WriteToStream(&fileStream);
	}
	fileStream.close();
}

void BlockChain::LoadChain(string* fileName)
{

}

// --------------------------------------------------
// ------------------------- Private Mehtods
// --------------------------------------------------