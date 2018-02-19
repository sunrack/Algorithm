#include "stdafx.h"
#include "Q_1_6.h"


int Q_1_6::Compress(const string& strSource, string& strCompressed)
{
	strCompressed.clear();
	int result = 0;

	if (strSource.empty())
	{
		// not compressed
		result = -1;
		return result;
	}

	char curChar = strSource[0];
	int curCharCount = 1;

	for (int i = 1; i < strSource.length(); i++)
	{
		if (curChar == strSource[i])
		{
			curCharCount++;
		}
		else
		{
			strCompressed.append(&curChar, 1);

			char charCount = curCharCount + '0';
			strCompressed.append(&charCount, 1);

			curChar = strSource[i];
			curCharCount = 1;
		}
	}

	strCompressed.append(&curChar, 1);

	char charCount = curCharCount + '0';
	strCompressed.append(&charCount, 1);

	if (strCompressed.length()>= strSource.length())
	{
		//not smaller
		strCompressed = strSource;
		result = 0;
	}
	else
	{
		// good
		result = 1;
	}

	return result;
}

string Q_1_6::Compress(const string& strSource)
{
	string strCompressed = "";

	int curCharCount = 0;

	for (int i = 0; i < strSource.length(); i++)
	{
		curCharCount++;

		// next char is different or last postion
		if ((i+1) >= strSource.length() || strSource[i+1] != strSource[i])
		{
			strCompressed.append(&strSource[i], 1);
			char charCount = curCharCount + '0';
			strCompressed.append(&charCount, 1);


			curCharCount = 0;
		}
	}

	return strCompressed.length() >= strSource.length() ? strSource : strCompressed;
}