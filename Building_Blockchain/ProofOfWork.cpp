#include "stdafx.h"
#include "ProofOfWork.h"


// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------

ProofOfWork::ProofOfWork()
{
}


ProofOfWork::~ProofOfWork()
{
}


// --------------------------------------------------
// ------------------------- Public Method
// --------------------------------------------------

void ProofOfWork::Prove(Block* blockToProve, unsigned int zeros)
{
	unsigned char criteria[HASH_BYTE_LENGTH];
	SetCriteria(criteria, 2 * HASH_BYTE_LENGTH - 1 - zeros);
	Prove(blockToProve, criteria);
}

void ProofOfWork::Prove(Block* blockToProve, unsigned char* criteria)
{
	vector<unsigned char> data;

	for (int i = 0; i < HASH_BYTE_LENGTH; i++)
		data.push_back(blockToProve->prevBlockHash[i]);

	for each(unsigned char c in *blockToProve->data)
		data.push_back(c);

	char intToHexArray[17];
	sprintf_s(intToHexArray, "%llx", blockToProve->timestamp);

	for (int i = 0; intToHexArray[i]; i++)
	{
		data.push_back(intToHexArray[i]);
		intToHexArray[i] = 0;
	}

	sprintf_s(intToHexArray, "%x", criteria);
	for (int i = 0; intToHexArray[i]; i++)
	{
		data.push_back(intToHexArray[i]);
		intToHexArray[i] = 0;
	}

	SHA256 hasher;
	int pushCount = 0;
	for (unsigned long long i = 0; i < _UI64_MAX; i++)
	{
		sprintf_s(intToHexArray, "%llx", i);
		for (pushCount = 0; intToHexArray[pushCount]; pushCount++)
		{
			data.push_back(intToHexArray[pushCount]);

			// Set it back to zero.
			intToHexArray[pushCount] = 0;
		}

		hasher.init();
		hasher.update(&data[0], data.size());
		unsigned char hash[HASH_BYTE_LENGTH];
		hasher.final(hash);

		bool isValidHash = IsHashLessThanCriteria(hash, criteria);
		if (isValidHash)
		{
			blockToProve->nonce = i;
			blockToProve->PrintHash();
			blockToProve->SetHash(hash);
			blockToProve->PrintHash();
			return;
		}

		for (; pushCount > 0; pushCount--)
		{
			data.pop_back();
		}
	}
}

// --------------------------------------------------
// ------------------------- Private Method
// --------------------------------------------------

bool ProofOfWork::IsHashLessThanCriteria(unsigned char* hash, unsigned char* criteria)
{
	unsigned char* hashBlock = hash;
	unsigned char* criteriaBlock = criteria;

	for (int i = 0; i < HASH_BYTE_LENGTH ; i++)
	{
		if (*hashBlock != 0 || *criteriaBlock != 0)
			if (*hashBlock < *criteriaBlock)
				return true;
			else
				return false;
		hashBlock++;
		criteriaBlock++;
	}
	return false; // should never get here??
}


/*
bool ProofOfWork::IsHashLessThanCriteria(unsigned char* hash, unsigned char* criteria)
{
	unsigned long long *hashBlock = (unsigned long long*) hash;
	unsigned long long *criteriaBlock = (unsigned long long*) criteria;

	for (int i = 0; i < HASH_BYTE_LENGTH / 8; i++)
	{
		if (*hashBlock != 0 || *criteriaBlock != 0)
			if (*hashBlock < *criteriaBlock)
				return true;
			else
				return false;
		hashBlock++;
		criteriaBlock++;
	}
	//return false; // should never get here??
}
*/

// ----- for debugging... can delete
void ProofOfWork::PrintHash(unsigned char* hash)
{
	//printf("Hash Value : ");
	for (int i = 0; i < HASH_BYTE_LENGTH; i++)
	{
		printf("%02X", hash[i]);
	}
	printf("\n");
}

void ProofOfWork::SetCriteria(unsigned char* criteria, int digit)
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