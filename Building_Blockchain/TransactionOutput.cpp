#include "stdafx.h"
#include "TransactionOutput.h"

// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------

TransactionOutput::TransactionOutput()
{

}


TransactionOutput::TransactionOutput(unsigned int Value, const char* scriptSig)
{
	value = Value;
	scriptPublicSignaure = new string(scriptSig);
}

TransactionOutput::~TransactionOutput()
{

}

// --------------------------------------------------
// ------------------------- Public Methods
// --------------------------------------------------


// --------------------------------------------------
// ------------------------- Private Methods
// --------------------------------------------------