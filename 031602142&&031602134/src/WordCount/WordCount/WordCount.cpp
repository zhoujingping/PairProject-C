#include<stdafx.h>
const int Arsize = 60;//�ı��ļ�����
#define	MAX_COM_LENGTH			150
int main() {

	char commandStr[MAX_COM_LENGTH] = "";
	gets_s(commandStr);
/*	for (int i = 1; i<argc; i++) {		//���û������ָ��ƴ�ӳ�һ���������ַ����������� 
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
		charcount.charCount(command.inFile, charcount);//�����ַ���ͳ�ƺ���
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		linecount.lineCount(command.inFile, linecount);//��������ͳ�ƺ���
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
    try
	{
		wordcount.wordCount(command.inFile, wordcount);//���õ�����ͳ�ƺ���
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	
	wordlist.wordCount(command.inFile, wordlist, command.m, command._w);//���ô�Ƶͳ�ƺ���
	charcount.countresult(command.outFile);
	wordcount.countresult(command.outFile);
	linecount.countresult(command.outFile);
	wordlist.outPut(command.outFile, command.n);
	return 0;
}
