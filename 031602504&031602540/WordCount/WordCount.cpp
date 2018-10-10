#pragma once
#include "pch.h"
#include "CountMeths.h"
#include"IOFile.h"
#include <iostream>
using namespace std;
int main()
{
	IOFile aa;
	CountMeths cc(aa.GetString());
	int lines = cc.CountLines();
	int cs = cc.CountCharacters();
	int b = cc.CountWords();
	vector<string> dd = cc.CountFrequency();
	int* ee;
	ee = cc.Getmax();
	printf("characters: %d\nwords: %d\nlines: %d\n",cs,b,lines);
	int i;
	for (i = 0; i < cc.Maxlen(); i++)
	{
		printf("%s: %d\n",dd[i].c_str(),ee[i]);
	}
	return 0;
}

