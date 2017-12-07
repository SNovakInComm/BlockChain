#include "stdafx.h"
#include "Block.h"


// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------
Block::Block()
{
	CommonInit();
}


Block::Block(string* dataToHash, unsigned char *PrevBlockHash)
{
	CommonInit();
	data = make_shared<string>(*dataToHash);
	//copy(prevBlockHash, this->prevBlockHash);
	if (PrevBlockHash)
	{
		prevBlockHash = (unsigned char *)malloc(sizeof(unsigned char) * HASH_BYTE_LENGTH);
		for (int i = 0; i < HASH_BYTE_LENGTH; i++)
			prevBlockHash[i] = PrevBlockHash[i];
	}
	else
	{
		prevBlockHash = nullptr;
	}
	SetHash();
}


Block::~Block()
{
	if (prevBlockHash)
		delete prevBlockHash;
}

void Block::CommonInit()
{
	timestamp = time(0);
}

// --------------------------------------------------
// ------------------------- Public Mehtods
// --------------------------------------------------

void Block::SetHash()
{
	string timeStampString = to_string(timestamp);
	vector<unsigned char> dataToHash;

	if (prevBlockHash)
	{
		for (int i = 0; i < HASH_BYTE_LENGTH; i++)
		{
			dataToHash.push_back(prevBlockHash[i]);
		}
	}
	for each(unsigned char c in *data)
	{
		dataToHash.push_back(c);
	}
	for each(unsigned char c in timeStampString)
	{
		dataToHash.push_back(c);
	}

	SHA256 hasher;

	hasher.update(&dataToHash[0], dataToHash.size());

	hasher.final(hash);
}

void Block::SetHash(unsigned char* hash)
{
	for (int i = 0; i < HASH_BYTE_LENGTH; i++)
	{
		this->hash[i] = hash[i];
	}
}

void Block::PrintHash()
{
	for (int i = 0; i < HASH_BYTE_LENGTH; i++)
	{
		printf("%x", hash[i]);
	}
}

void Block::PrintPrevHash()
{
	if (prevBlockHash)
	{
		for (int i = 0; i < HASH_BYTE_LENGTH; i++)
		{
			printf("%x", prevBlockHash[i]);
		}
	}
	else
	{
		printf("nullptr");
	}
}