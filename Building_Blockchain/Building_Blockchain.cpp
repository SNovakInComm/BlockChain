// Building_Blockchain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Types.h"
#include <stdio.h>
#include "Block.h"

#include "Sha256.h"

using namespace std;

int main()
{
	/*
	SHA256 hasher;
	unsigned char hash[hasher.DIGEST_SIZE];
	string myString =  "hello world";

	for (int i = 0; i < hasher.DIGEST_SIZE; i++)
	{
		hash[i] = 0;
	}

	hasher.update((unsigned char*)myString.c_str(), 11);
	hasher.final(hash);

	printf("Hash Value : ");
	for (int i = 0; i < hasher.DIGEST_SIZE; i++)
	{
		printf("%x", hash[i]);
	}
	*/

	string* someData = new string("Hello");

	Block newBlock(someData);
	//newBlock.timestamp = 


    return 0;
}

