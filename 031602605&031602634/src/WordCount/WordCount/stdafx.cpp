// stdafx.cpp : 只包括标准包含文件的源文件
// WordCount.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息
#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

bool cmp(const pair<string, int> &n1, const pair<string, int> &n2) 
{
	if (n1.second == n2.second)
		return n1.first < n2.first;
	else
		return n1.second > n2.second;
}
Word::Word()
{
	mapword.clear();
	//初始化
	linesnum = 0;
	characters = 0;
	words = 0;
	initans = 0;//代表是否进行过初始化
}
int Word::init(ifstream& in)
{
	map<string, int>::iterator iter;
	__int64 wordpos ,answord;
	string name,str;
	int num,i,j;
	bool anslint = 0, trueword = 1;
	while (getline(in, name))
	{
		characters += (int)(name.size()+1);
		wordpos = 0;
		answord = 0;
		num = (int)name.size();
		for (i = 0; i < num; i++)
		{
			if (!anslint&&name[i] != 0x9 && name[i] != 0xd && name[i] != 0xa && name[i] != 0x20)
			{
				anslint = 1;//标记； 
			}//统计空白行 
			if (('a' <= name[i] && name[i] <= 'z') || ('A' <= name[i] && name[i] <= 'Z'))
			{
				if (65 <= name[i] && name[i] <= 90)name[i] += 32;//大小写转化
				answord++;
				continue;
			}
			if ('0' <= name[i] && name[i] <= '9')
			{
				if (answord >= 4)
					continue;
				else
				{
					for (j = i+1; j < num; j++)
					{
						if ('0' <= name[j] && name[j] <= '9')
							continue;
						else if (('a' <= name[j] && name[j] <= 'z') || ('A' <= name[j] && name[j] <= 'Z'))
							continue;
						else
						{
							while (j < num)
							{
								if (('a' <= name[j + 1] && name[j + 1] <= 'z') || ('A' <= name[j + 1] && name[j + 1] <= 'Z'))
								{
									wordpos = j + 1;
									break;
								}
								else
									j++;
							} //寻找下一个单词的开头 
							i = j;
							break;
						}
					}	//寻找下一个分隔符 
					if (j == num)
					{
						break;
					}	//寻找不到下一个分隔符 
					answord = 0;
				}
			}
			else
			{
				if (answord >= 4)
				{
					str = name.substr(wordpos, i - wordpos);
					mapword[str]++;
					//	cout<<"word:"<<word<<endl;
					words++;
				}//获取单词
				while (i < num)
				{
					if (('a' <= name[i + 1] && name[i + 1] <= 'z')|| ('A' <= name[i + 1] && name[i + 1] <= 'Z'))
					{
						wordpos = i + 1;
						break;
					}
					else
						i++;
				} //寻找下一个单词的开头 
				answord = 0;
			}
		}
		if (answord >= 4)
		{
			str = name.substr(wordpos, i - wordpos);
			mapword[str]++;
			words++;
		}
		if (anslint)
		{
			linesnum++;
			anslint = 0;
		}
		//	cout<<name<<endl;;	
	}
	characters--;
	//初始化完成；
	initans = 1;
	return 0;
}
int Word::Countlines(ifstream& in)
{
	//统计非空白行
	if (!initans)
		init(in);
	return linesnum;
}
int Word::Countwords(ifstream& in)
{
	if (!initans)
		init(in);
	return words;
}
int Word::Countcharacters(ifstream& in)
{
	//统计ascll码的数量
	/*
	char ch;
	while (in.peek() != EOF) {
		in.get(ch);
		characters++;
	}
	in.seekg(0, ios::beg);
	*/
	if (!initans)
		init(in);
	return characters;
}
vector<pair<string, int>> Word::Counttop10(ifstream& in)
{
	__int64 num;
	vector<pair<string, int>>top(mapword.begin(), mapword.end()),top10;
	sort(top.begin(), top.end(), cmp);
	num = 0;
	for(int i=0;i < top.size() ; i++ )
	{
		num++;
		top10.insert(top10.end(),top[i]);
		if (num == 10)
			break;
	}
	return top10;
}
void Word::display(ofstream& fout,int num,ifstream& in)
{
	fout << "characters: " << Countcharacters(in) << endl;
	fout << "words: " << Countwords(in) << endl;
	fout << "lines: " << Countlines(in) << endl;
	vector<pair<string, int>> v = Counttop10(in);
	vector<pair<string, int>>::iterator iter = v.begin();
	for (; iter != v.end(); iter++)
	{
		fout << "<" << iter->first << ">: " << iter->second << endl;
	}
	return ;
}
File::File() {}
int File::FileTest(char *argv[])
{
	int ans = 1;
	if (argv[1] == NULL)
	{
		printf("no file\n");
		ans = 0;
	}
	else if (argv[2] != NULL)
	{
		printf("too much\n");
		ans = 0;
	}
	fstream Fileread;
	Fileread.open(argv[1], std::ios::in);
	if (Fileread.fail())
	{
		printf("file isn't exist\n");
		ans = 0;
	}
	Fileread.close();
	return ans;
}