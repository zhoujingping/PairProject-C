// WordCount.cpp: 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include<iostream>
#include<fstream>	//实现文本输入输出流的头文件 
using namespace std;
int main(int argc, char *argv[])//argc是命令行参数，*argv[]
{
	File f;
	Word w;
	f.del(argv);
	if (f.Filein())
	{
		exit(1);//文件异常
	}
	if(f.flagcountphrase)
		w.displayphrase(f.fout, f.outtop, f.fin, f.countquz,f.countphrase);
	else
		w.display(f.fout,f.outtop,f.fin,f.countquz);
	f.Fileout();
	return 0;
}
