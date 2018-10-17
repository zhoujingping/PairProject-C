#pragma once
#include"pch.h"
#include<vector>
#include<iostream>
#include<map>
using namespace std;

class CountMeths
{
private:
	string content;
	int characters;
	int papers;
	int lines;
	int max[101] = {0};
	int maxlen;
	vector<string> phrase;

public:
	bool IsWord(string word);
	CountMeths(string s);
	~CountMeths() {}
	int CountCharacters();//return characters
	int CountLines();    //return lines
	int CountWords();   //return words
	void phrasetomap(map<string,int> &mymap,vector<string> &screen,int cflag,int m,int w);//符合词组加入map
	vector<string> CountFrequency(int w=0,int m=1,int n=10); //返回前n个频率的词组,maxlen =n;
	int* Getmax();
	int Maxlen();
};//   Countlines必须先执行给出papers，其他几个函数都有用到papers;