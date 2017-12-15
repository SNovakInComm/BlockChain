#include "stdafx.h"
#include "TransactionInput.h"

// --------------------------------------------------
// ------------------------- Constructors
// --------------------------------------------------

TransactionInput::TransactionInput()
{
}

TransactionInput::TransactionInput(unsigned int outputIndex, const char* signature)
{
	Vout = outputIndex;
	ScriptSignatire = new string(signature);

}

TransactionInput::~TransactionInput()
{
}

// --------------------------------------------------
// ------------------------- Public Methods
// --------------------------------------------------

// --------------------------------------------------
// ------------------------- Private Methods
// --------------------------------------------------
