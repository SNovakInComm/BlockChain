// Building_Blockchain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Types.h"
#include <stdio.h>
#include "BlockChain.h"
#include "Sha256.h"
#include "ProofOfWork.h"
#include <time.h>

using namespace std;

void setCriteria(unsigned char* criteria);
void printHash(unsigned char* hash);
void setCriteria(unsigned char* criteria, int digit);
void testProofOfWork();
void testBlockChain(int digit);
void testSetCriteria();
void timeTrial();
void testSaveBlock();
void testLoadBlock();

int main()
{
	//testSetCriteria();
	//testProofOfWork();
	
	testSaveBlock();
	testLoadBlock();

    return 0;
}

// -------------------------------------------------- 
// ------------------------- Tests
// -------------------------------------------------- 

void testSaveBlock()
{
	BlockChain theChain(3);

	string message = "Hello";
	string fileName = "testChain.txt";

	theChain.AddBlock(&message);
	
	message = "I am the wallrus";
	theChain.AddBlock(&message);

	message = "I am the eggman";
	theChain.AddBlock(&message);

	theChain.SaveChain(&fileName);
}

void testLoadBlock()
{
	string fileName = "testChain.txt";
	BlockChain theChain(&fileName);

	for (unsigned int i = 0; i < theChain.blocks.size(); i++)
	{
		printf("Block %d Hash =  : Message = %s\n", i, theChain.blocks[i]->data->c_str());
		theChain.blocks[i]->PrintHash();
	}

}

void timeTrial()
{
	clock_t now, later;
	printf("Trial, Tries, Seconds, ticks\n");
	for (int trial = 1; trial < 50; trial++)
	{
		for (int i = 63; i > 58; i--)
		{
			printf("%d,", trial);
			now = clock();
			testBlockChain(i);
			later = clock();
			printf("%f, %ld\n", (double)(later - now) / (double)CLOCKS_PER_SEC, (later - now));
			//printf("It took %f seconds and %ld ticks",(double) (later - now) / (double)CLOCKS_PER_SEC, (later - now));
		}
	}
}

void testSetCriteria()
{
	unsigned char criteria[32];

	for (int i = 0; i < 64; i++)
	{
		setCriteria(criteria, i);
		printHash(criteria);
	}
}


void testProofOfWork()
{
	unsigned char criteria[32];

	setCriteria(criteria, 1);
	printHash(criteria);
}

void testBlockChain(int digit)
{
	unsigned char criteria[32];
	string BlockString = "Testing the first block";
	// ----- Init Objects
	ProofOfWork Prover;
	BlockChain theBlockChain;
	theBlockChain.AddBlock(&BlockString);
	Block* addedBlock = theBlockChain.blocks[1];

	// ----- Set Criteria
	setCriteria(criteria, digit);
	//printf("\n\nCriteria         : ");
	//printHash(criteria);
	// ----- Prove the genesisblock

	//printf("Hash before proof: ");
	//addedBlock->PrintHash();
	Prover.Prove(addedBlock, criteria);

	//printf("Hash after proof : ");
	//addedBlock->PrintHash();

	//printf("\nIt took %llu tries!", addedBlock->nonce);
	printf("%llu,", addedBlock->nonce);
}

// -------------------------------------------------- 
// ------------------------- Utility Functions
// -------------------------------------------------- 

void setCriteria(unsigned char* criteria)
{
	uint64_t* setter = (uint64_t*) criteria;
	*(setter)   = 0x0000001000000000;
	*(++setter) = 0x0000000000000000;
	*(++setter) = 0x0000000000000000;
	*(++setter) = 0x0000000000000000;
}

void setCriteria(unsigned char* criteria, int digit)
{
	for (int i = 0; i < HASH_BYTE_LENGTH; i++)
		criteria[i] = 0;

	int result = digit & 1;
	if (result == 0)	// even
	{
		//criteria[(digit / 2)] = 1;
		criteria[HASH_BYTE_LENGTH - 1 - (digit / 2)] = 1;
	}
	else
	{
		//criteria[((digit - 1) / 2)] = 16;
		criteria[HASH_BYTE_LENGTH - 1 - ((digit - 1) / 2)] = 16;
	}
}

void printHash(unsigned char* hash)
{
	//printf("Hash Value : ");
	for (int i = 0; i < HASH_BYTE_LENGTH; i++)
	{
		printf("%02X", hash[i]);
	}
	printf("\n");
}

