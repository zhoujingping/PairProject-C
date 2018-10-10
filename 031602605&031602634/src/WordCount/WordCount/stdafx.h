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
#include <algorithm>  
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
	ifstream Fileread;
	string fileword;
	int initans;
public:
	Word();//初始化
	int init(ifstream& in);
	int Countcharacters(ifstream& in);//统计字符数
	int Countlines(ifstream& in);//统计空白行
	int Countwords(ifstream& in);//统计单词数
	vector<pair<string, int>> Counttop10(ifstream& in);//统计前十个词
	void display(ofstream& fout,int num, ifstream& in);//输出
};
class File
{
	//文本类：异常测试
public:
	File();
	int FileTest(char *argv[]);//异常测试
};

// TODO: 在此处引用程序需要的其他头文件
