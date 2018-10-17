#pragma once
#include<iostream>
#include<fstream>
#include<strstream>
#include<cstring>
#include<string>
using namespace std;
//指令解析类
#define MAX_PATH_LENGTH 50
struct Command {
	bool _i;		//是否按照指定路径读入文件
	bool _o;		//是否按照指定路径读出文件
	bool _w;		//是否加入词频权重统计
	bool _m;		//是否开启词组词频统计功能
	bool _n;		//是否开启自定义词频统计输出
	char inFile[MAX_PATH_LENGTH];		//读入文件路径 
	char outFile[MAX_PATH_LENGTH];      //读出结果路径
	int m;          //词组中单词数
	int n;          //数组数
	Command() {
		_i = false;
		_o = false;
		_w = false;
		_m = false;
		_n = false;
		strcpy_s(inFile, "input.txt");  //将初始读入文件设置为input.txt
		strcpy_s(outFile, "output.txt");	//将初始读出文件设置为result.txt
		m = 1;
		n = 10;
	}
	void commandAnalyse(char commandStr[], Command &command);
	int swiftNumber(char str[]);
};

//字符数统计类
struct CharCount
{
private:
	int charnum;//字符个数
public:
	CharCount()
	{
		charnum = 0;
	}
	void charCount(string fileName, CharCount &charcount);//统计字符数
	void countresult(string fileName);//输出字符数
};
//单词数统计类
struct WordCount
{
private:
	int wordnum;
public:
	WordCount()
	{
		wordnum = 0;
	}
	void wordCount(string fileName, WordCount &wordcount);
	void countresult(string fileName);
};
//行数统计类
struct LineCount
{
private:
	int linenum;//行数
public:
	LineCount()
	{
		linenum = 0;
	}
	void lineCount(string fileName, LineCount &linecount);//行数统计函数
	void countresult(string fileName);//输出行数
};
//单词词频统计类
#define	MAX_WORD_LENGTH 20000
struct Word {
	char word[MAX_WORD_LENGTH];
	int num;
	Word *next;
	Word *previous;
	Word() {
		word[0] = 0;
		num = 0;
		next = nullptr;
		previous = nullptr;
	}
	Word(char* theWord, int theNum) {
		strcpy_s(word, theWord);
		num = theNum;
		next = nullptr;
		previous = nullptr;
	}
	//如果使用了指针，在析构函数中释放 
	~Word() {
		delete next;
		next = nullptr;
	}
};

struct WordIndex {
	Word* pWord;
	WordIndex* next;
	WordIndex(Word* theWord, WordIndex* theNext)
	{
		pWord = theWord;
		next = theNext;
	}
	~WordIndex() {
		delete next;
		next = nullptr;
	}
};

struct WordList
{
private:
	int Hash(char *word);			//哈希函数
	void shiftWord(Word * pWord);	//使word前移一格
	Word* pWordHead;				//指向Word的指针
	Word* pWordTail;
	WordIndex* index[512];			//哈希索引
public:
	WordList();
	~WordList();
	void addWord(char word[],bool _w);
	void wordCount(string fileName, WordList &wordList,int m,bool _w);
	void outPut(string fileName,int n);
};