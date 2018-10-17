// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#pragma once
const int MAXS = 60 * 1024 * 1024;
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <string>
#include<cstring>
#include <stdio.h>
#include <tchar.h>
#include<map>
#include<unordered_map>
#include<iostream>
#include<fstream>	//实现文本输入输出流的头文件 
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>  
#include<deque>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Word
{
	//单词类：统计单词的词频
private:
	int linesnum;
	int words;
	int characters;
	unordered_map<string, int> mapword;
	string fileword;
	int initans;												//初始标志位
	int countphrase;											//词组长度
	int countquz;												//权重统计
	int outtop;													//前多少个词
public:
	Word();//初始化
	void set(int n1, int n2, int n3);
	int initdisplayphrase(ifstream& in);
	int init(ifstream& in);
	int Countcharacters(ifstream& in);//统计字符数
	int Countlines(ifstream& in);//统计空白行
	int Countwords(ifstream& in);//统计单词数
	vector<pair<string, int>> Counttop10(ifstream& in,int num);//统计前百个词
	void displayphrase(ofstream& fout, ifstream& in);//输出词组
};
class File
{
	//文本类：异常测试
private:
	
public:
	string input;									//输入文档路径
	string output;									//输出文档路径
	ifstream fin;
	ofstream fout;
	int fcountphrase;											//词组长度
	int fcountquz;												//权重统计
	int fouttop;												//前多少个词
	File();
	int Filein();
	void Fileout();
	int FileTest(char *argv[]);//异常测试
	void del(char *argv[]);	//判断参数
};

// TODO: 在此处引用程序需要的其他头文件
