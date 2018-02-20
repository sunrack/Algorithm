#pragma once
#include <string>
#include "QBase.h"
using namespace std;

class Q_1_5 : public QBase
{
public:
	static bool isOneEdit(const string& s1, const string& s2);
	static bool isOneEditReplace(const string& s1, const string& s2);
	static bool isOneEditInsertOrRemove(const string& small, const string& big);


	static bool isOneEditMerge(const string& s1, const string& s2);

	static int Test();
};

