#include<stdafx.h>
const int Arsize = 60;//文本文件长度
#define	MAX_COM_LENGTH			150
int main() {

	char commandStr[MAX_COM_LENGTH] = "";
	gets_s(commandStr);
/*	for (int i = 1; i<argc; i++) {		//将用户输入的指令拼接成一个完整的字符串传给程序 
		strcat_s(commandStr, argv[i]);
		strcat_s(commandStr, " ");
	}*/

	Command command;
	command.commandAnalyse(commandStr,command);;
	CharCount charcount;
	WordCount wordcount;
	LineCount linecount;
	WordList wordlist;
	try
	{
		charcount.charCount(command.inFile, charcount);//调用字符数统计函数
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		linecount.lineCount(command.inFile, linecount);//调用行数统计函数
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
    try
	{
		wordcount.wordCount(command.inFile, wordcount);//调用单词数统计函数
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	
	wordlist.wordCount(command.inFile, wordlist, command.m, command._w);//单用词频统计函数
	charcount.countresult(command.outFile);
	wordcount.countresult(command.outFile);
	linecount.countresult(command.outFile);
	wordlist.outPut(command.outFile, command.n);
	return 0;
}
