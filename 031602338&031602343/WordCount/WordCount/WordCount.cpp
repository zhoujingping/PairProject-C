#include <fstream>     
#include <iostream>    
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include"CountChar.h"
#include"CountLines.h"
#include"CountWordnumber.h"
#include"TenFrequency.h"
vector<pair<string, int>> word;
map<string, int> mCountMap;
using namespace std;

int main(int argc, const char* argv[])
{
	
	for (int i = 1; i < argc; i++)
	{
		ifstream file;
		if (argv[i] == "-i")
		{
			file.open(argv[i], ios::in);
			if (!file) {
				cout << "无法打开文件\n";
				return -1;
			}
			file.close();
			string mInputFileName = argv[i];
			int sum = CountChar(mInputFileName);
			int wordnum = CountWordnumber();
			int lines = CountLines(mInputFileName);
			TenFrequency();
		}
		if (argv[i] == "-o")
		{
            ofstream out(argv[i+1]);
            out << "characters: " << sum << endl;
		    out << "words: " << wordnum << endl;
		    out << "lines: " << lines << endl;
		    int size = 10;
		     if (word.size() < 10) 
			 {
		    	size = word.size();
	         }
		     vector<pair<string, int>>::iterator vit;
	    	for (vit = word.begin(); vit != word.begin() + size; vit++) 
			{
		    	out << "<"<<vit->first <<">:"<< " " << vit->second << endl;
	    	}
	    	out.close();
		}
		
		
		
		
		
	}
	system("pause");
	return 0;
}

