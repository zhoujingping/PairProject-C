// stdafx.cpp : 只包括标准包含文件的源文件
// WordCount.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

int ifchar(char c)
{
	if ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9'))
	{
		if (c >= 'A'&&c <= 'Z')//大写改小写
		{
			c = c + 32;
		}
		return 1;
	}
	else return 0;
}

int ifword(string s)
{
	char c;
	string t;
	int k = 0;
	c = s[k];
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))//可能是单词 
	{
		while ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9'&&k >= 4))//继续后几位的验证 
		{
			t = t + c;
			k++;//下一位

			c = s[k];
		}
		t[k] = '\0';//结束标识 
	}
	if (t.length() >= 4)
		return 1;
	else return 0;
}

int findword(string s)
{
	int size;
	char c;
	string t;
	int k = 0, st, ed, i = 0;
	while (k < s.length())
	{
		c = s[k];
		if (!ifchar(c))
		{
			k++;
			continue;
		}
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))//可能是单词 
		{
			st = k;
			while (ifchar(c))//继续后几位的验证 
			{
				if (c >= 'A'&&c <= 'Z')//大写改小写
				{
					c = c + 32;
				}
				t = t + c;
				ed = k;
				k++;//下一位
				c = s[k];
			}
			//t[k++] = '\0';
			a[i] = st;
			a[i + 1] = ed;
			i += 2;
		}
	}
	size = i;
	return size;
}

void start(string s, int m)
{
	int siz = findword(s);
	int i = 0, j = n, p;
	for (i = 0; i <= siz - 2 * m; i += 2)
	{
		ts.s = s.substr(a[i], a[i + 2 * m - 1] - a[i] + 1);
		ts.frq = 1;
		for (p = 0; p < n; p++)
		{
			if (ts.s == word[p].s)//归于之前的 
			{

				word[p].frq = word[p].frq + 1;
				break;
			}
		}

		if (n == 0 || p == j)//新的另外处理
		{
			word[n] = ts;
			n++;
		}
	}
}


int charcount(char *tx, string txo)
{
	FILE *fp;
	fopen_s(&fp, tx, "r");
	ofstream outf(txo);

	int charcnt = 0;

	if (fp == NULL)
	{
		cout << "Open Error!" << endl;
		return 0;
	}

	while (!feof(fp))
	{
		char c = getc(fp);
		charcnt++;
	}
	cout<< "characters: " << charcnt - 1 << endl;
	outf << "characters: " << charcnt - 1 << endl;
	return charcnt;
}

int linecount(char *tx, string txo)
{
	FILE *fp;
	fopen_s(&fp, tx, "r");
	ofstream outf(txo, ios::app);

	int flag = 1;
	int linecnt = 0;
	char c;

	while (!feof(fp))
	{
		c = getc(fp);

		if ((c != 10) && (c != ' ') && (c != EOF) && (flag == 1) && (c != 9))
		{
			linecnt++;
			flag = 0;
		}

		if (c == 10)
		{
			flag = 1;
		}

	}
	cout<< "lines: " << linecnt << endl;
	outf << "lines: " << linecnt << endl;
	return linecnt;
}

void  sor(wd *f, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (f[j].s > f[j + 1].s)
				swap(f[j], f[j + 1]);
		}
}

int wordcount(char *tx, string txo, int bo)
{
	FILE *fp;
	fopen_s(&fp, tx, "r");
	ofstream outf(txo, ios::app);

	int wordcnt = 0;
	int k, i, j, x = 1, y = 1;
	if (bo == 1)
		y = 10;
	char p, m;
	while (!feof(fp))
	{
		char c = getc(fp);
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))//可能是单词 
		{
			k = 0;//从第0位开始判断
			while ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9'&&k >= 4))//继续后几位的验证 
			{
				if (c >= 'A'&&c <= 'Z')//大写改小写
				{
					c = c + 32;
				}
				temp.s = temp.s + c;
				m = temp.s[temp.s.size() - 1];
				k++;//下一位

				c = getc(fp);
				p = c;
				if (c == ':'&&m == 'e')
					temp.bl = y;
				if (c == ':'&&m == 't')
					temp.bl = x;

			}
			temp.s = temp.s + '\0';//结束标识 
			k++;//此词位数+1

			j = n;

			if (temp.s.length() >= 4)//确保大于4位英文字母 
			{
				wordcnt++;//词频置1
				if (temp.bl == y)
					temp.frq = y;
				if (temp.bl == x)
					temp.frq = x;

				for (i = 0; i < j; i++)
				{
					if (word[i].s == temp.s)//归于之前的 
					{

						word[i].frq = word[i].frq + temp.bl;
						if (p == ':' && (m == 'e' || m == 't'))
							word[i].frq = word[i].frq - temp.bl;
						break;
					}
				}

				if (n == 0 || i == j)//新的另外处理
				{
					word[n] = temp;
					if (p == ':' && (m == 'e' || m == 't'))
						word[i].frq = word[i].frq - temp.bl;
					n++;
				}
			}
		}
	}
	cout<< "words: " << wordcnt << endl;
	outf << "words: " << wordcnt << endl;
	return wordcnt;
}

void wordmax(char *tx, string txo, int num, int m)
{
	FILE *fp;
	fopen_s(&fp, tx, "r");
	ofstream outf(txo, ios::app);

	char ch = getc(fp);
	int i = 0, j, ct;
	wd max[100];

	while (!feof(fp))
	{
		ct = 0;
		temps = "";
		while (ch != ':')
			ch = getc(fp);
		while (!ifchar(ch))
			ch = getc(fp);
		while (1)
		{
			if (ch == 10 || ch == EOF)//读到回车,文末
			{
				if (ifword(temps))
				{
					str[ct] = temps;
					temps = "";
					for (int j = 0; j <= ct; j++)//temps置为前面的累加
						temps = temps + str[j];
					start(temps, m);
				}
				else
				{
					temps = "";
					if (ct >= m)//前面的长度大于指定数m
					{
						for (int j = 0; j <= ct; j++)//temps置为前面的累加*********<=ct
							temps = temps + str[j];
						start(temps, m);
					}
				}
				break;
			}
			if (temps.size() == 0)
			{
				temps = temps + ch;
				ch = getc(fp);
			}
			else if ((ifchar(temps[temps.size() - 1]) == 0) && ifchar(ch))//遇到当前是字母数字，上一个是分隔符，结束读取
			{
				if (ifword(temps))
				{
					str[ct] = temps;
					ct++;
					temps = "";
				}
				else
				{
					temps = "";
					if (ct >= m)//前面的长度大于指定数m
					{
						for (int j = 0; j <= ct; j++)//temps置为前面的累加*********<=ct
							temps = temps + str[j];
						start(temps, m);

					}
					ct = 0;
					temps = "";
				}
			}
			temps = temps + ch;
			ch = getc(fp);
		}
	}
	sor(word, n);

	for (i = 0; i < num; i++)//初始化前num名
	{
		max[i] = word[i];
	}

	for (j = 0; j < num; j++)//前num名排序 
	{
		for (i = 0; i < num - j - 1; i++)
		{
			if (max[i].frq < max[i + 1].frq)
			{
				swap(max[i], max[i + 1]);
			}
		}
	}

	for (i = 10; i < n; i++) 
	{
		if (max[9].frq < word[i].frq) 
		{
			int a = 8;
			while (max[a].frq < word[i].frq&&a >= 0)
			{
				a--;
			}

			for (j = 9; j > a + 1; j--)
			{
				max[j] = max[j - 1]; 
			}
			if (a < 0)
				max[0] = word[i];
			else
				max[j] = word[i];
		}
	}

	for (int i = 0; i < num; i++)
	{
		if (max[i].s.length() == 0)
			continue;
		cout<< "<" << max[i].s << ">" << ":" << max[i].frq << endl;
		outf << "<" << max[i].s << ">" << ":" << max[i].frq << endl;
	}
	outf.close();
}
void wordmax1(char *tx, string txo, int num)
{
	FILE *fp;
	fopen_s(&fp, tx, "r");
	ofstream outf(txo, ios::app);

	int  i, j;

	sor(word, n);
	wd max[100];

	for (i = 0; i < num; i++)//初始化前num名
	{
		max[i] = word[i];
	}

	for (j = 0; j < num; j++)//前num名排序 
	{
		for (i = 0; i < num - j - 1; i++)
		{
			if (max[i].frq < max[i + 1].frq)
			{
				swap(max[i], max[i + 1]);
			}
		}
	}

	for (i = 10; i < n; i++)//找后面的数 
	{
		if (max[9].frq < word[i].frq)//比最小的还大 
		{
			int a = 8;
			while (max[a].frq < word[i].frq&&a >= 0)
			{
				a--;//定位到第一个比自己大的word
			}

			for (j = 9; j > a + 1; j--)
			{
				max[j] = max[j - 1];//前面的数后移一位 
			}
			if (a < 0)//说明word[i]比max[0]大
				max[0] = word[i];
			else
				max[j] = word[i];
		}
	}

	for (int i = 0; i < num; i++)
	{
		if (max[i].s.size() == 0)
			continue;
		outf << "<" << max[i].s << ">" << ":" << max[i].frq << endl;
	}
	outf.close();
}