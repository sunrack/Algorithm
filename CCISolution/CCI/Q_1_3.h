#pragma once
#include "QBase.h"
#include <vector>

using namespace std;

class Q_1_3 : public QBase
{
public:
	static int Test();

	//Wrong
	static int URLify(const string& strIn, string& strOut);
	//Wrong
	static int URLify(string& strIn);

	static int URLify(string& strIn, int trueLength);
};

