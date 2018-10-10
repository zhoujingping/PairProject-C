#pragma once
#include "pch.h"
#include "CountMeths.h"
#include"IOFile.h"
#include <iostream>
#include<sstream>
#include<string>

using namespace std;
int main(int argc,char* argv[])
{
	int i, o, w, m, n;
	int len = argc;
	string input;
	string output;
	int j;
	for (j = 1; j < len; j+=2)
	{
		if (argv[j][0] == '-'&&argv[j][1]=='i')
		{
			input = argv[j+1];
		}
		if (argv[j][0] == '-'&&argv[j][1]=='o')
		{
			output = argv[j + 1];
		}
		if (argv[j][0] == '-'&&argv[j][1]=='w')
		{
			w = atoi(argv[j + 1]);
		}
		if (argv[j][0] == '-'&&argv[j][1]=='m')
		{
			m = atoi(argv[j + 1]);
		}
		if (argv[j][0] == '-'&&argv[j][1]=='n')
		{
			n = atoi(argv[j + 1]);
		}
	}
	IOFile file;
	CountMeths count(file.GetString(input));
	int lines = count.CountLines();
	int characters = count.CountCharacters();
	int words = count.CountWords();
	vector<string> phrase = count.CountFrequency(w,m,n);
	int * frequency = count.Getmax();
	string outcontent;
	outcontent = "characters: " + to_string(characters) + "\n" + "words: " + to_string(words) + "\n" + "lines: " + to_string(lines) + "\n";
	for (j = 0; j < count.Maxlen(); j++)
	{
		outcontent += "<" + phrase[j] + ">" + ": " + to_string(frequency[j]) + "\n";
	}
	file.Ex_content(outcontent);
	file.OutString(output);
	return 0;
}

