// newhilbert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "hilbert.h"

#include <limits.h>
#include <stdint.h>
#include <iostream>
using namespace std;

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 7; j >= 0; j--)
		{
			byte = b[i] & (1 << j);
			byte >>= j;
			printf("%u", byte);
			//cout << byte;
		}
	}
	puts("");
	//cout << "";
}

int _tmain(int argc, _TCHAR* argv[])
{
	bitmask_t coord[2];
	bitmask_t code = 0;	

	for (unsigned int i = 0; i < 16; i++)
	{
		for (unsigned int j = 0; j < 16; j++)
		{
			coord[0] = i;
			coord[1] = j;
			//coord[2] = 3;

			code = hilbert_c2i(2, 4, coord);

			bitmask_t coord4[2];
			hilbert_i2c(2, 4, code, coord4);

			cout << i << "," << j << "----->" << code << "----->" << coord4[0] << "," << coord4[1] << endl;
		}
	}

	bitmask_t coord2[5];
	
	coord2[0] =  5;//0101
	coord2[1] = 13;//1101
	coord2[2] =  3;//0011
	coord2[3] = 11;//1011
	coord2[4] = 10;//1010

	code = hilbert_c2i(5, 40, coord2);
	cout << "index : " << code << endl;

	for(unsigned int i = 0; i < 5; i++)
		coord2[i] = 0;//0101

	bitmask_t coord3[5];

	hilbert_i2c(5, 40, code, coord3);
	//code = 624824;
	//printBits(sizeof(bitmask_t), &code);
	cout << endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		//printBits(sizeof(bitmask_t), &coord2[i]);
		cout << ", " << coord3[i]  << endl;
	}
		

	return 0;
}

