// CCI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Q_1_6.h"
#include "Q_1_5.h"
#include "Q_1_3.h"
#include "Q_2_2.h"
#include "Q_16_17.h"

#include <set>
#include <iostream>

unsigned short GetHashCode(string str)
{
	int result = 0;
	for (int pos = 0; pos < str.length(); pos++)
	{
		result |= 1 << ((str[pos] - 'a') + (str.length() - pos -1) * 8);
	}

	return result;
}


int main()
{
	/*
	int code = GetHashCode("ab");

	code = GetHashCode("aba");

	string subStr = "abaa";

	int count = 0;	

	for (int pos = 0; pos<subStr.length(); pos++)
	{
		for (int len = 1; len <= subStr.length()-pos; len++)
		{
			set<unsigned short> subStrList;

			unsigned short code = GetHashCode(subStr.substr(pos, len));

			if (subStrList.count(code) == 0)
			{
				subStrList.insert(code);
				count++;
			}
		}
	}

	cout << count << endl;

	*/






	string strSource = "aabcccccaaa";
	string strCompressed;
	int result = 0;

	result = Q_1_6::Compress(strSource, strCompressed);
	result = Q_1_6::Compress("abcde", strCompressed);

	strCompressed = Q_1_6::Compress("aabcccccaaa");
	strCompressed = Q_1_6::Compress("abcde");


	Q_16_17::Test();

	Q_1_5::Test();

	Q_1_3::Test();

	Q_2_2::Test();

	Q_2_2::Test2();

	
	
    return 0;
}

