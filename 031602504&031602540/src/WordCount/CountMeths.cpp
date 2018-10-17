#pragma once
#include "pch.h"
#include"CountMeths.h"
#include<map>
#include <assert.h>
#include<string>
#include<queue>
CountMeths::CountMeths(string s)
{
	content = s;
	characters = 0;
	papers = 0;
	lines = 0;
	maxlen = 0;
}
int CountMeths::CountCharacters()
{
	characters = 0;
	int cflag = 0;  //碰到\n加一，加到5清零，1和2有效
	int pflag = 0;  //cflag清零时加一，到papers的数值使循环停下
	int i;
	char onechar;
	for (i = 0; content[i] != '\0'; i++)
	{
		onechar = content[i];
		if (cflag == 1 || cflag == 2)
		{
			characters++;
		}
		if (onechar == '\n')
		{
			cflag++;
		}
		if (cflag >= 5)
		{
			cflag = 0;
			pflag++;
		}
		if (pflag >= papers)
		{
			break;
		}
	}
	characters -= papers * 17;
	return characters;
}
bool CountMeths::IsWord(string word)
{
	if (word.length() < 4)
	{
		return false;
	}
	if (word[0] >= 97 && word[0] <= 122 && word[1] >= 97 && word[1] <= 122
		&& word[2] >= 97 && word[2] <= 122 && word[3] >= 97 && word[3] <= 122)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int CountMeths::CountWords()
{
	int wordnum = 0;
	char onechar;
	int i;
	string aword="";
	for(i = 0; content[i] != '\0'; i++) 
	{
		onechar = content[i];
		if ((onechar >= 48 && onechar <= 57) ||  (onechar >= 97 && onechar <= 122))
		{
			aword += onechar;
		}
		else
		{
			if (IsWord(aword))
			{
				wordnum++;
			}
			aword = "";   //是不是单词都得清零
		}
	}
	//判断最后一个单词是否为单词；
	if (IsWord(aword))
	{
		wordnum++;
	}
	aword="";
	wordnum -= papers * 2;
	return wordnum;
}
int CountMeths::CountLines()
{
	int validnum = 0;
	bool vflag = false;
	int i;
	for(i=0;content[i]!='\0';i++)
	{
		if (content[i] >= 33)
		{
			vflag = true;
		}
		if (content[i] == '\n' && vflag)
		{
			validnum++;
			vflag = false;
		}
	}
	if (vflag)
	{
		validnum++;
		vflag = false;
	}
	validnum = (validnum / 3 ) * 2;
	papers = validnum / 2;
	lines = validnum;
	return lines;
}
void CountMeths::phrasetomap(map<string, int> &mymap, vector<string> &screen, int cflag, int m,int w)
{
	string p;
	int i;
	for (i = 0; i < (int)screen.size(); i++)
	{
		p += screen[i];
	}
	if (w == 1 && cflag == 1)
	{
		w = 10;
	}
	else
	{
		w = 1;
	}
	if (!mymap[p])
	{
		mymap[p] = w;
	}
	else
	{
		mymap[p] += w;
	}
	if (m == 1)
	{
		screen.erase(screen.begin(), screen.begin() + 1);
	}
	else
	{
		screen.erase(screen.begin(), screen.begin() + 2);
	}
}
vector<string> CountMeths::CountFrequency(int w, int m, int n)
{
	maxlen = n;
	char onechar;
	int i;
	string aword = "";     //词组
	string delimit = "";   //分隔符组
	map<string, int> mymap;
	vector<string> screen;
	int cflag = 0;  //碰到\n加一，加到5清零，1和2有效
	int pflag = 0;  //cflag清零时加一，到papers的数值使循环停下
	content += '\n';//解决最后一篇没有换行不好处理
	for (i = 0; content[i] != '\0'; i++)
	{
		onechar = content[i];
		if (cflag == 1 || cflag == 2)  //有效行
		{
			if ((onechar >= 48 && onechar <= 57) || (onechar >= 97 && onechar <= 122))
			{
				aword += onechar;
				if (delimit != "")
				{
					if (screen.size() != 0)
					{
						screen.push_back(delimit);
					}
				}
				delimit = "";
			}
			else
			{
				delimit += onechar;
				if (IsWord(aword))
				{
					screen.push_back(aword);
					if ((int)screen.size() >= 2 * m - 1)
					{
						phrasetomap(mymap, screen, cflag, m, w);
					}
				}
				else if(aword!="")
				{
					screen.clear();
				}
				aword = "";   //是不是单词都得清零
			}
		}
		if (onechar == '\n')
		{
			screen.clear();
			cflag++;
			if (cflag == 1)
			{
				i += 7;
			}
			if (cflag == 2)
			{
				i += 10;
			}
		}
		if (cflag >= 5)
		{
			cflag = 0;
			pflag++;
		}
		if (pflag >= papers)
		{
			break;
		}
	}


	map <string, int>::iterator mymap_Iter;
	map <string, int>::iterator mymap_Iter2;
	if (maxlen > (int)mymap.size())
	{
		maxlen = mymap.size();
	}
	for (i = 0; i < maxlen; i++)
	{
		mymap_Iter2 = mymap.begin();
		for (mymap_Iter = mymap.begin(); mymap_Iter != mymap.end(); mymap_Iter++)
		{
			if (mymap_Iter2->second < mymap_Iter->second)
			{
				mymap_Iter2 = mymap_Iter;
			}
		}
		phrase.push_back(mymap_Iter2->first);
		max[i] = mymap_Iter2->second;
		mymap[mymap_Iter2->first] = 0;
	}
	return phrase;
}
int* CountMeths::Getmax()
{
	return max;
}
int CountMeths::Maxlen()
{
	return maxlen;
}
