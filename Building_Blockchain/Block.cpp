#include "stdafx.h"
#include "Block.h"


// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------
Block::Block()
{
	CommonInit();
}


Block::Block(string* dataToHash)
{
	CommonInit();
	data = make_shared<string>(*dataToHash);
	SetHash();
}


Block::~Block()
{
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

	for each(unsigned char c in prevBlockHash)
	{
		dataToHash.push_back(c);
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