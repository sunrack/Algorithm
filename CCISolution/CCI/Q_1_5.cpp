#include "stdafx.h"
#include "Q_1_5.h"



bool Q_1_5::isOneEdit(const string& s1, const string& s2)
{
	if (s1.length() == s2.length())
	{
		return isOneEditReplace(s1, s2);
	}
	else if (s1.length() + 1 == s2.length())
	{
		return isOneEditInsertOrRemove(s1, s2);
	}
	else if (s1.length() - 1 == s2.length())
	{
		return isOneEditInsertOrRemove(s2, s1);
	}
	else
	{
		return false;
	}
}

bool Q_1_5::isOneEditReplace(const string& s1, const string& s2)
{
	bool findDiff = false;

	for (size_t i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
		{
			if (findDiff)
			{
				return false;
			}
		}
		else
		{
			findDiff = true;
		}
	}

	return true;
}

bool Q_1_5::isOneEditInsertOrRemove(const string& small, const string& big)
{
	size_t indexSmall = 0;
	size_t indexBig = 0;
	bool findDiff = false;

	while (indexSmall < small.length() && indexBig < big.length())
	{
		if (small[indexSmall] != big[indexBig])
		{
			if (findDiff)
			{
				return false;
			}

			findDiff = true;
			indexBig++;
		}
		else
		{
			indexSmall++;
			indexBig++;
		}
	}

	return true;
}


bool Q_1_5::isOneEditMerge(const string& s1, const string& s2)
{
	if (fabs(s1.length() - s2.length()) > 1)
	{
		return false;
	}

	size_t indexS1 = 0; 
	size_t indexS2 = 0;
	bool findDiff = false;

	while (indexS1 < s1.length() && indexS2 < s2.length())
	{
		if (s1[indexS1] != s2[indexS2])
		{
			if (findDiff)
			{
				return false;
			}

			findDiff = true;

			if (s1.length() == s2.length())
			{
				indexS1++;
				indexS2++;
			}
			if (s1.length() < s2.length())
			{
				indexS2++;
			}
			else if (s1.length() > s2.length())
			{
				indexS1++;
			}
			
		}
		else
		{
			indexS1++;
			indexS2++;
		}
	}

	return true;
}


int Q_1_5::Test()
{
	int result = 0;

	result = isOneEdit("pale", "ple");

	result = isOneEdit("pales", "pale");

	result = isOneEdit("pale", "bale");

	result = isOneEdit("pale", "bake");


	result = isOneEditMerge("pale", "ple");

	result = isOneEditMerge("pales", "pale");

	result = isOneEditMerge("pale", "bale");

	result = isOneEditMerge("pale", "bake");

	return result;
}

