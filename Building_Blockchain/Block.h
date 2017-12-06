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
	Block(string* dataToHash);
	~Block();

	void CommonInit();

	// ------------------------- Public Members
	bTimeStamp timestamp;
	shared_ptr<string> data;
	unsigned char prevBlockHash[HASH_BYTE_LENGTH];
	unsigned char hash[HASH_BYTE_LENGTH];

	// ------------------------- Public Methods
	void SetHash();

protected:


private:
	

};

