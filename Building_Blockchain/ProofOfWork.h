#pragma once

#include "Block.h"

class ProofOfWork
{
public:
	// ------------------------- Constructors
	ProofOfWork();
	~ProofOfWork();

	// ------------------------- Methods

	void Prove(Block* blockToProve, unsigned char* criteria);

	void Prove(Block* blockToProve, unsigned int zeros);

	// make this private
	bool IsHashLessThanCriteria(unsigned char* hash, unsigned char* criteria);

	// Delete this
	void PrintHash(unsigned char* hash);

private:
	void SetCriteria(unsigned char* criteria, int digit);

};

