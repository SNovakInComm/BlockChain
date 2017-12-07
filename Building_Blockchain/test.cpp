// Building_Blockchain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Types.h"
#include <stdio.h>
#include "BlockChain.h"
#include "Sha256.h"
#include "ProofOfWork.h"

using namespace std;

void setCriteria(unsigned char* criteria);
void printHash(unsigned char* hash);

int main()
{
	unsigned char criteria[32];
	string BlockString = "Testing the first block";
	// ----- Init Objects
	ProofOfWork Prover;
	BlockChain theBlockChain;
	theBlockChain.AddBlock(&BlockString);
	Block* addedBlock = theBlockChain.blocks[1];
	
	// ----- Set Criteria
	setCriteria(criteria);
	
	// ----- Prove the genesisblock

	printf("\n\nHash before proof: ");
	addedBlock->PrintHash();
	Prover.Prove(addedBlock, criteria);
	
	printf("\n\nHash after proof: ");
	addedBlock->PrintHash();
	
	
    return 0;
}

// -------------------------------------------------- 
// ------------------------- Utility Functions
// -------------------------------------------------- 

void setCriteria(unsigned char* criteria)
{
	unsigned long long* setter = (unsigned long long*) criteria;
	*(setter++) = 0x0000100000000000;
	*(setter++) = 0x0000000000000000;
	*(setter++) = 0x0000000000000000;
	*(setter++) = 0x0000000000000000;

}

void printHash(unsigned char* hash)
{
	printf("Hash Value : ");
	for (int i = 0; i < HASH_BYTE_LENGTH; i++)
	{
		printf("%x", hash[i]);
	}
}

