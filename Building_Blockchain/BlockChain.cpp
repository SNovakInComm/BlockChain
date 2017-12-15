#include "stdafx.h"
#include "BlockChain.h"

// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------


BlockChain::BlockChain(unsigned int leadingZerosForProof)
{
	_proofZeroLength = leadingZerosForProof;
	Block* genesisBlock = new Block(new string("Genesis Block"), nullptr);
	blocks.push_back(genesisBlock);
	_head = 0;
}

BlockChain::BlockChain()
{
	Block* genesisBlock = new Block(new string("Genesis Block"), nullptr);

	Transaction* GenesisTransaction = new Transaction();
	GenesisTransaction->AddOutput(50000, "Coinbase");

	genesisBlock->transactions.push_back(GenesisTransaction);

	blocks.push_back(genesisBlock);
	_head = 0;
}

BlockChain::BlockChain(string* fileName)
{
	LoadChain(fileName);
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

void BlockChain::SaveChain(const char* fileName)
{
	ofstream fileStream;
	fileStream.open(fileName, ios::out);
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
	ifstream fileIn;
	fileIn.open(fileName->c_str(), ios::in);
	unsigned long long numberOfBlocks;

	fileIn.read((char*)&numberOfBlocks, sizeof(unsigned long long));

	for (int i = 0; i<numberOfBlocks; i++)
	{
		blocks.push_back(new Block(&fileIn));
	}

	fileIn.close();
}

void BlockChain::LoadChain(const char* fileName)
{
	ifstream fileIn;
	fileIn.open(fileName, ios::in);
	unsigned long long numberOfBlocks;

	fileIn.read((char*)&numberOfBlocks, sizeof(unsigned long long));

	blocks.clear();

	for (int i = 0; i<numberOfBlocks; i++)
	{
		blocks.push_back(new Block(&fileIn));
	}

	fileIn.close();
}

bool BlockChain::CreateTransaction(string* fromID, string* toID, unsigned int amount)
{
	Transaction* newTransaction = new Transaction();

	SearchForAmount(fromID, amount);

	// --- route them to transaction

	// --- Pickup the change

	return false;
}

bool BlockChain::CreateTransaction(TransactionOutput* CoinBase, string* toID)
{
	Transaction* newTransaction = new Transaction();

	newTransaction->AddInput(new TransactionInput(0, toID->c_str()));

	// ----- add it to a queue

	return false;
}

// --------------------------------------------------
// ------------------------- Private Mehtods
// --------------------------------------------------

vector<TransactionOutput*>* BlockChain::SearchForAmount(string* user, unsigned int amount)
{

	for (unsigned int blockIndex = _head; blockIndex < blocks.size(); blockIndex++)
	{
		Block* currentBlock = blocks[blockIndex];
		for (int transactionIndex = 0; transactionIndex < currentBlock->transactions.size(); transactionIndex++)
		{
			Transaction* currentTransaction = currentBlock->transactions[transactionIndex];
			for (int outputIndex = 0; outputIndex < currentTransaction->NumberOfOutputs(); outputIndex++)
			{
				TransactionOutput* output = currentTransaction->GetOutput(outputIndex);
				if(*output->scriptPublicSignaure == *user)
					printf("Owner: %s has %d in this output", output->scriptPublicSignaure->c_str(), output->value);
			}

		}	// end for transactions
	} // end for 

	return nullptr;
}