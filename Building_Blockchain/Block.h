#pragma once

#include "Types.h"
#include <memory>
#include <ctime>
#include "Sha256.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Transaction.h"

using namespace std;

class Block
{
public:
	// ------------------------- Constructors
	Block();
	Block(ifstream* fileStream);
	Block(string* dataToHash, unsigned char *prevBlockHash);
	~Block();

	void CommonInit();

	// ------------------------- Public Members
	bTimeStamp timestamp;
	shared_ptr<string> data;
	vector<Transaction*> transactions;
	unsigned char * prevBlockHash;
	unsigned char hash[HASH_BYTE_LENGTH];
	unsigned long long nonce;

	// ------------------------- Public Methods
	void SetHash();

	void SetHash(unsigned char* hash);

	void PrintHash();

	void PrintPrevHash();

	void WriteToStream(ofstream* stream);

	void ReadFromStream(ifstream* stream);

	void Mine(const char* Id);

protected:
	

private:
	

};

