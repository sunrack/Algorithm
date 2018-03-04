#pragma once
#include "QBase.h"

// Kadane's Algorithm
// Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.

// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

// https://ide.geeksforgeeks.org/EtrjQF

class Q_16_17 :
	public QBase
{
public:
	static int Test();
	static int FindMaxSubArrayFast(const int A[], int n);
	static int FindMaxSubArraySlow(const int A[], int n);
};