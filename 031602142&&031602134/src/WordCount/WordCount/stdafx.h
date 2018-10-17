#pragma once
#include<iostream>
#include<fstream>
#include<strstream>
#include<cstring>
#include<string>
using namespace std;
//ָ�������
#define MAX_PATH_LENGTH 50
struct Command {
	bool _i;		//�Ƿ���ָ��·�������ļ�
	bool _o;		//�Ƿ���ָ��·�������ļ�
	bool _w;		//�Ƿ�����ƵȨ��ͳ��
	bool _m;		//�Ƿ��������Ƶͳ�ƹ���
	bool _n;		//�Ƿ����Զ����Ƶͳ�����
	char inFile[MAX_PATH_LENGTH];		//�����ļ�·�� 
	char outFile[MAX_PATH_LENGTH];      //�������·��
	int m;          //�����е�����
	int n;          //������
	Command() {
		_i = false;
		_o = false;
		_w = false;
		_m = false;
		_n = false;
		strcpy_s(inFile, "input.txt");  //����ʼ�����ļ�����Ϊinput.txt
		strcpy_s(outFile, "output.txt");	//����ʼ�����ļ�����Ϊresult.txt
		m = 1;
		n = 10;
	}
	void commandAnalyse(char commandStr[], Command &command);
	int swiftNumber(char str[]);
};

//�ַ���ͳ����
struct CharCount
{
private:
	int charnum;//�ַ�����
public:
	CharCount()
	{
		charnum = 0;
	}
	void charCount(string fileName, CharCount &charcount);//ͳ���ַ���
	void countresult(string fileName);//����ַ���
};
//������ͳ����
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
//����ͳ����
struct LineCount
{
private:
	int linenum;//����
public:
	LineCount()
	{
		linenum = 0;
	}
	void lineCount(string fileName, LineCount &linecount);//����ͳ�ƺ���
	void countresult(string fileName);//�������
};
//���ʴ�Ƶͳ����
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
	//���ʹ����ָ�룬�������������ͷ� 
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
	int Hash(char *word);			//��ϣ����
	void shiftWord(Word * pWord);	//ʹwordǰ��һ��
	Word* pWordHead;				//ָ��Word��ָ��
	Word* pWordTail;
	WordIndex* index[512];			//��ϣ����
public:
	WordList();
	~WordList();
	void addWord(char word[],bool _w);
	void wordCount(string fileName, WordList &wordList,int m,bool _w);
	void outPut(string fileName,int n);
};