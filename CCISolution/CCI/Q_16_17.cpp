#include "stdafx.h"
#include "Q_16_17.h"
#include <climits>
#include <assert.h>
#include <iostream>
using namespace std;


int Q_16_17::Test()
{
	int A1[] = {2, -8, 3, -2, 4, -10};
	assert(5 == FindMaxSubArrayFast(A1, sizeof(A1) / sizeof(int)));

	int A2[] = { 1, 2, 3 };
	assert(6 == FindMaxSubArrayFast(A2, sizeof(A2) / sizeof(int)));

	int A3[] = { -1, -2, -3, -4 };
	assert(-1 == FindMaxSubArrayFast(A3, sizeof(A3) / sizeof(int)));

	return 0;
}

// Only 1 scan
// find all the subarray with non-decreasing sum
// then get the max from the subarray

int Q_16_17::FindMaxSubArrayFast(const int A[], int n)
{
	int start = 0;
	int end = 0;
	int max = INT_MIN;

	if (n == 0)
	{
		start = -1;
		end = -1;
		return max;
	}

	int curSum = A[0];
	int curStart = 0;
	int curEnd = 0;
	max = A[0];

	printf("%s %s %s %s %s %s %s \n", "i", "curSum", "max", "curStart", "curEnd", "start", "end");

	for (int i = 1; i<n; i++)
	{
		if ((curSum + A[i]) < A[i])
		{
			// if curSum < 0, that means we need to restart from the current position
			curSum = A[i];
			curStart = i;
			curEnd = i;
		}
		else
		{
			// continue to add current position
			curSum += A[i];
			curEnd = i;
		}

		if (curSum > max)
		{
			// update max
			max = curSum;
			start = curStart;
			end = curEnd;
		}

		printf("%5d %5d %5d %5d %5d %5d %5d \n", i, curSum, max, curStart, curEnd, start, end);
	}

	std::cout<< max << endl;

	return max;
}

int Q_16_17::FindMaxSubArraySlow(const int A[], int n)
{
	int start = 0;
	int end = 0;
	int max = INT_MIN;

	if (n == 0)
	{
		start = -1;
		end = -1;
		return max;
	}

	for (int i = 0; i<n; i++)
	{
		int sum = 0;

		for (int j = i; j<n; j++)
		{
			sum += A[j];

			if (sum > max)
			{
				max = sum;
				start = i;
				end = j;
			}
		}
	}

	return max;
}
