// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include<iostream>
#include<fstream>	//实现文本输入输出流的头文件 
using namespace std;
int main(int argc, char *argv[])//argc是命令行参数，*argv[]
{
	for (int i = 0; i < 5; i++)
	{
		cout << argv[i] << endl;
	}
	File f;
	if (!f.FileTest(argv))
	{
		exit(1);//文件异常
	}
	Word w;
	ifstream fin;
	ofstream fout;
	fin.open(argv[1], ios::in);
	fout.open("./result.txt", ios::out);
	w.display(fout,10,fin);
	fin.close();
	fout.close();
	return 0;
}
