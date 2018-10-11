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
	void phrasetomap(map<string,int> &mymap,vector<string> &screen,int cflag,int m,int w);//���ϴ������map
	vector<string> CountFrequency(int w=0,int m=1,int n=10); //����ǰn��Ƶ�ʵĴ���,maxlen =n;
	int* Getmax();
	int Maxlen();
};//   Countlines������ִ�и���papers�������������������õ�papers;