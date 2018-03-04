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
	int start = -1;
	int end = -1;
	int max = INT_MIN;

	int curSum = 0;
	int curStart = 0;
	int curEnd = 0;

	printf("%10s %10s %10s %10s %10s %10s %10s \n", "i", "curSum", "max", "curStart", "curEnd", "start", "end");

	for (int i = 0; i<n; i++)
	{
		// add current
		curSum += A[i];
		curEnd = i;

		//update max
		if (curSum > max)
		{
			// update max
			max = curSum;
			start = curStart;
			end = curEnd;
		}

		printf("%10d %10d %10d %10d %10d %10d %10d \n", i, curSum, max, curStart, curEnd, start, end);

		if (curSum < 0)
		{
			// if curSum < 0, that means we need to restart from the current position
			curSum = 0;
			curStart = i+1;
			curEnd = i+1;
		}
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
