// CCI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Q_1_6.h"
#include "Q_1_5.h"
#include "Q_1_3.h"


int main()
{
	string strSource = "aabcccccaaa";
	string strCompressed;
	int result = 0;

	result = Q_1_6::Compress(strSource, strCompressed);
	result = Q_1_6::Compress("abcde", strCompressed);

	strCompressed = Q_1_6::Compress("aabcccccaaa");
	strCompressed = Q_1_6::Compress("abcde");

	Q_1_5::Test();

	Q_1_3::Test();
	
    return 0;
}

