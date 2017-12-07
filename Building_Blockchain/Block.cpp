#include "stdafx.h"
#include "Block.h"


// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------
Block::Block()
{
	CommonInit();
}

Block::Block(ifstream* fileStream)
{
	ReadFromStream(fileStream);
}

Block::Block(string* dataToHash, unsigned char *PrevBlockHash)
{
	CommonInit();
	data = make_shared<string>(*dataToHash);

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
		printf("%02X", hash[i]);
	}
	printf("\n");
}

void Block::PrintPrevHash()
{
	if (prevBlockHash)
	{
		for (int i = 0; i < HASH_BYTE_LENGTH; i++)
		{
			printf("%02X", prevBlockHash[i]);
		}
		printf("\n");
	}
	else
	{
		printf("nullptr");
	}
}

void Block::WriteToStream(ofstream* stream)
{
	size_t dataLength = data->size();
	stream->write((char*)&timestamp, sizeof(bTimeStamp));
	stream->write((char*)&dataLength, sizeof(size_t));
	stream->write(data->c_str(), data->size());
	if (prevBlockHash == nullptr)
		*stream << '0';
	else
	{
		*stream << '1';
		stream->write((char*)prevBlockHash, HASH_BYTE_LENGTH);
	}
	stream->write((char*)hash, HASH_BYTE_LENGTH);
	stream->write((char*)&nonce, sizeof(nonce));
}

void Block::ReadFromStream(ifstream* stream)
{
	size_t dataLength;
	
	string tempData;
	char isGenesis;

	stream->read((char*)&timestamp, sizeof(bTimeStamp));
	stream->read((char*)&dataLength, sizeof(size_t));
	tempData.resize(dataLength);
	stream->read((char*)tempData.c_str(), dataLength);
	data = make_shared<string>(tempData);
	stream->read(&isGenesis, 1);
	if (isGenesis == '0')
		prevBlockHash = nullptr;
	else
	{
		prevBlockHash = (unsigned char *)malloc(sizeof(unsigned char) * (HASH_BYTE_LENGTH + 1));
		stream->read((char*)prevBlockHash, HASH_BYTE_LENGTH);
		prevBlockHash[HASH_BYTE_LENGTH] = '\0';
	}
	stream->read((char*)hash, HASH_BYTE_LENGTH);
	stream->read((char*)&nonce, sizeof(nonce));
}