#include "stdafx.h"
#include "Q_1_3.h"


int Q_1_3::URLify(const string& strIn, string& strOut)
{
	// wrong
	return -1;

	strOut = "";

	size_t indexIn = 0;
	while (indexIn < strIn.size())
	{
		if (strIn[indexIn] != ' ')
		{
			strOut.append(&strIn[indexIn], 1);
		}
		else
		{
			strOut.append("%20");
		}

		indexIn++;
	}

	return strIn.length();
}

int Q_1_3::URLify(string& strIn)
{
	// wrong
	return -1;

	if (strIn.length() == 0)
	{
		return 0;
	}

	int indexIn = strIn.length() - 1;
	int indexOut = strIn.length() - 1;
	int size = 0;

	while (indexIn >= 0 && strIn[indexIn] == ' ')
	{
		indexIn--;
	}

	if (indexIn >= 0)
	{
		size = indexIn + 1;

		while (indexIn > 0 && indexOut >= indexIn)
		{
			if (strIn[indexIn] == ' ')
			{
				strIn[indexOut--] = '0';
				strIn[indexOut--] = '2';
				strIn[indexOut--] = '%';
			}
			else
			{
				strIn[indexOut] = strIn[indexIn];
				indexOut--;
			}

			indexIn--;
		}
	}
	else
	{
		return 0;
	}

	return size;
}


int Q_1_3::URLify(string& strIn, int trueLength)
{
	if (trueLength == 0)
	{
		return 0;
	}

	int spaceCount = 0;
	for (size_t i = 0; i < trueLength; i++)
	{
		if (strIn[i] == ' ')
		{
			spaceCount++;
		}
	}

	int indexIn = trueLength - 1;
	int indexOut = trueLength + 2* spaceCount - 1;

	if (indexOut > indexIn)
	{
		strIn[indexOut+1] = '\0';
	}

	while (indexIn >= 0 && indexOut >= indexIn)
	{
		if (strIn[indexIn] == ' ')
		{
			strIn[indexOut--] = '0';
			strIn[indexOut--] = '2';
			strIn[indexOut--] = '%';
		}
		else
		{
			strIn[indexOut--] = strIn[indexIn];
		}

		indexIn--;
	}

	return 1;
}


int Q_1_3::Test()
{
	string strIn = "Mr John Smith      ";
	string strOut = "";
	int length = 0;

	//length = URLify(strIn, strOut);

	//length = URLify(strIn);

	length = URLify(strIn, 13);

	return 0;
}