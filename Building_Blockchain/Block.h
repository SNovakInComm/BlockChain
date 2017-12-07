#pragma once

#include "Types.h"
#include <memory>
#include <ctime>
#include "Sha256.h"
#include <string>
#include <vector>

#define HASH_BYTE_LENGTH 32
using namespace std;

class Block
{
public:
	// ------------------------- Constructors
	Block();
	Block(string* dataToHash, unsigned char *prevBlockHash);
	~Block();

	void CommonInit();

	// ------------------------- Public Members
	bTimeStamp timestamp;
	shared_ptr<string> data;
	unsigned char * prevBlockHash;
	unsigned char hash[HASH_BYTE_LENGTH];
	unsigned long long nonce;

	// ------------------------- Public Methods
	void SetHash();

	void SetHash(unsigned char* hash);

	void PrintHash();

	void PrintPrevHash();

protected:


private:
	

};

