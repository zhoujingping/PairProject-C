#include<stdafx.h>
int state=0;
int Command::swiftNumber(char str[])
{
	int a = -1, b = -1, c = -1;
	if (str[0] >= '0'&&str[0] <= '9')
		a = str[0] - 48;
	if (str[1] >= '0'&&str[1] <= '9')
		b = str[1] - 48;
	if (str[2] >= '0'&&str[2] <= '9')
		c = str[1] - 48;
	if (b >= 0 && c >= 0)
		return a * 100 + b * 10 + c;
	else if (b >= 0 && c < 0)
		return a * 10 + b;
	else
		return a;
}
void Command::commandAnalyse(char commandStr[], Command &command) {
	/*����һ���ַ�����һ��ָ��ṹ������á�
	�ڸýṹ���ڴ洢���������*/
	for (int i = 0; true; i++)
	{
		char c = commandStr[i];
		if (c == 0) return;
		if (c == '-') 
		{	//����'-'֮��������ȡ��һ���ַ���Ȼ���ж��Ǻ���ָ��ж��Ƿ���Ҫ������ȡ�ַ��� 
			i++;
			c = commandStr[i];
			if (c == 'i') 
			{ 
				command._i = true; 
			}
			else if (c == 'o') 
			{ 
				command._o = true;  
			}
			else if (c == 'w') 
			{ 
				i += 2;
				if (commandStr[i] == '1')
					command. _w = true;
			}
			else if (c == 'm') 
			{
				command._m = true;  
			}
			else if (c == 'n') 
			{ 
				command._n = true; 
			}
			else continue;
			i += 2;	//����һ���ո��Ժ�ʼ��ȡ�ļ�·�� 
		}
		if (c == ' ') continue;
		char path[MAX_PATH_LENGTH] = "";
		for (int j = 0; true; j++) {
			char ch = commandStr[i];
			if (ch == 0) { i--; break; }
			/*���ڴ�ѭ��ÿ��i++�����ﵽ������ĩβ
			����Ҫ��i--�����ó����жϳ�����������ĩβ*/
			if (ch == ' ') break;
			path[j] = ch;
			i++;
		}
		char m_Str[3],n_Str[3];
		if (c == 'i')
			strcpy_s(command.inFile, path);
		else if (c == 'o')
			strcpy_s(command.outFile, path);
		else if (c == 'm')
		{
			strcpy_s(m_Str, path);
			command.m = command.swiftNumber(m_Str);
		}
		else if (c == 'n')
		{
			strcpy_s(n_Str, path);
			command.n = command.swiftNumber(n_Str);
		}
		else {}
	}
	return;
}

void CharCount::countresult(string fileName)//����ַ���
{
	fstream outFile(fileName, ios::out);
	outFile << "characters: " << charnum;
	outFile << endl;
	outFile.close();
}
void CharCount::charCount(string fileName, CharCount &charcount)//�����ַ���ͳ�ƺ���
{
	char c;
	fstream inFile;
	inFile.open(fileName);//��ȡ�ļ�
	if (inFile.fail()) //��ȡ�ļ�ʧ��
	{
		throw "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
	inFile >> noskipws;
	inFile >> c;
	string str;
	while (getline(inFile, str))
	{
		if (str[0] >= '0'&&str[0] <= '9')
			continue;
		else if (str[0] == 'T')
			charcount.charnum += str.length() - 6;
		
		else if(str[0]=='A')
			charcount.charnum += str.length() - 9;
	}
	charcount.charnum -= 1;
	/*while (!inFile.eof())
	{
		if (inFile.good())
		{
			if ((c >= 'a' && c <='z')||(c>='A'&&c<='Z'))
			{
				charcount.charnum++;
			}
			inFile >> c;
		}
	}*/
	if (charnum == 0)
	{
		throw "���ı��������ı��������ַ�\n";
	}
}

void WordCount::countresult(string fileName)
{
	fstream outFile(fileName, ios::app);
	outFile << "words: " << wordnum;
	outFile << endl;
}
void WordCount::wordCount(string fileName, WordCount &wordcount)//���嵥����ͳ�ƺ���
{
	char c;
	int i = 0;
	char wordStr[2000] = { 0 };
	int delta = 'a' - 'A';
	int wordposition = 0;//��¼��ǰ��ĸ�ڵ��ʵ�λ��
	int wordPosition = 0;
	fstream inFile(fileName);
	inFile >> noskipws;
	string str;
	while (getline(inFile,str))
	{
		c = str[0];
		while (c != '\0')
		{
			c = str[i];
			if (c <= 'Z'&&c >= 'A') c += delta;
			bool separator1 = (c >= 'a'&&c <= 'z');
			bool separator2 = (c >= '0'&&c <= '9');
			if (separator1)
			{
				wordposition++;
				wordStr[wordPosition] = c;
				wordPosition++;
			}
			if (separator2)
			{
				if (wordposition < 4)
				{
					memset(wordStr, '\0', sizeof(wordStr));
					wordposition = 0;
					wordPosition = 0;
				}
				else
				{
					wordStr[wordPosition] = c;
					wordPosition++;
				}
			}
			if (!separator1 && !separator2 && wordposition < 4)
			{
				wordPosition = 0;
				wordposition = 0;
			}
			if (c == ':' && wordposition >= 4 && strcmp(wordStr, "title") == 0)
			{
				memset(wordStr, '\0', sizeof(wordStr));
				wordPosition = 0;
				wordposition = 0;
			}
			if (c == ':' && wordposition >= 4 && strcmp(wordStr, "abstract") == 0)
			{
				memset(wordStr, '\0', sizeof(wordStr));
				wordPosition = 0;
				wordposition = 0;
			}
			if (!separator1 && !separator2&&wordposition >= 4)
			{
				memset(wordStr, '\0', sizeof(wordStr));
				wordcount.wordnum++;
				wordPosition = 0;
				wordposition = 0;
			}
			i++;
		}
		i = 0;
	}
	/*if (wordnum == 0)
	{
		throw "�޵��ʣ�����������һ����Ч���ʣ�\n";
	}*/
	inFile.close();
}

void LineCount::countresult(string fileName)//�������
{
	fstream outFile(fileName, ios::app);
	outFile << "lines: " << linenum;
	outFile << endl;
}
void LineCount::lineCount(string fileName, LineCount &linecount)//��������ͳ�ƺ���
{
	fstream inFile;
	string str;
	inFile.open(fileName, ios::in);//��ȡ�ļ�
	if (inFile.fail())//�ļ���ʧ��
	{
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
	while (getline(inFile,str))
	{
		if (str[0] == 'T'||str[0] == 'A')
			linecount.linenum++;
	}
	if (linenum == 0)
	{
		throw "���ı��������ı��������ַ�\n";
	}
	inFile.close();
}

WordList::WordList()
{
	pWordHead = new Word();
	pWordTail = new Word();
	pWordHead->next = pWordTail;
	pWordTail->previous = pWordHead;
	for (int i = 0; i<512; i++) index[i] = nullptr;
}
WordList::~WordList()
{
	delete pWordHead;

	for (int i = 0; i<512; i++) {
		delete index[i];
		index[i] = nullptr;
	}
}
void WordList::addWord(char word[],bool _w)
{
	//��word���������ӵ���Ƶͳ�Ʊ��У����ߴ�Ƶ+1��
	int  p_index = Hash(word);
	WordIndex* pIndex = index[p_index];
	while (pIndex != nullptr)
	{
		Word *pWord = pIndex->pWord;
		if (!strcmp(word, pWord->word))
		{
			if (_w == true && state == 1)
				pWord->num += 10;
			else
				pWord->num++;
			Word *qWord = pWord->previous;
			while (qWord->num < pWord->num) 
			{
				if (qWord == pWordHead) return;
				shiftWord(pWord);

				qWord = pWord->previous;
			}
			while (strcmp(qWord->word, pWord->word) > 0) 
			{
				if (qWord->num > pWord->num) return;
				shiftWord(pWord);
				qWord = pWord->previous;
			}
			return;
		}
		pIndex = pIndex->next;
	}
	Word *pWord;
	if (_w == true && state == 1)
		pWord = new Word(word, 10);
	else
		pWord = new Word(word, 1);
	pWord->previous = pWordTail->previous;
	pWord->next = pWordTail;

	pWordTail->previous->next = pWord;
	pWordTail->previous = pWord;

	pIndex = new WordIndex(pWord, index[p_index]);
	index[p_index] = pIndex;

	Word *qWord = pWord->previous;
	while (strcmp(qWord->word, pWord->word) > 0) {
		if (qWord->num > pWord->num) return;
		shiftWord(pWord);
		qWord = pWord->previous;
	}
}
void WordList::outPut(string fileName,int n)
{
	fstream outFile(fileName, ios::app);
	//��n������ȫ��ͨ��outFileд���ı��ļ�
	Word *p = pWordHead->next;
	if (p != pWordTail) outFile << "<" << p->word << ">" <<':'<< ' ' << p->num;
	else return;
	p = p->next;

	for (int i = 0; i < n-1; i++) {
		if (p != pWordTail) outFile << endl << "<" << p->word << ">" <<':'<< ' ' << p->num;
		else return;

		p = p->next;
	}
}
int WordList::Hash(char* word) {
	int HashVal = 0;

	while (*word != '\0')
		HashVal += *word++;

	return HashVal & 511;

}
void WordList::shiftWord(Word *pWord)
{
	if (pWord == pWordHead) return;
	Word *qWord = pWord->previous;
	if (qWord == pWordHead) return;

	pWord->next->previous = qWord;
	qWord->previous->next = pWord;

	qWord->next = pWord->next;
	pWord->previous = qWord->previous;

	pWord->next = qWord;
	qWord->previous = pWord;
}
void WordList::wordCount(string fileName, WordList &wordList, int m, bool _w)
{
	char word[MAX_WORD_LENGTH] = { 0 };
	char wordStr[2000] = { 0 };
	string str;
	ifstream inFile;
	inFile >> noskipws;
	inFile.open(fileName);
	int wordposition = 0;
	int wordPosition = 0;
	char c;
	int delta = 'a' - 'A';
	int i = 0, j = 0; //��¼�ַ���ǰλ��
	int n = m;     
	while (getline(inFile, str))
	{
		if (str[0] != 'T'&&str[0] != 'A')
			continue;
		c = str[0];
		while (c != '\0')
		{
			c = str[i];
			if (c <= 'Z'&&c >= 'A') c += delta;
			bool separator1 = (c >= 'a'&&c <= 'z');
			bool separator2 = (c >= '0'&&c <= '9');
			if (separator1)
			{
				wordposition++;
				wordStr[wordPosition] = c;
				wordPosition++;
			}
			if (separator2)
			{
				if (wordposition < 4)
				{
                    memset(wordStr, '\0', sizeof(wordStr));
					wordposition = 0;
					wordPosition = 0;
				}
				else
				{
					wordStr[wordPosition] = c;
					wordPosition++;
				}
			}
			if (!separator1 && !separator2 && wordposition < 4)
			{
				
				memset(wordStr, '\0', sizeof(wordStr));
				memset(word, '\0', sizeof(word));
				n = m;
				wordPosition = 0;
				wordposition = 0;
				j = i;
			}
			if (c==':' && wordposition >= 4 && strcmp(wordStr, "title") == 0)
			{
				state = 1;
				wordPosition = 0;
				wordposition = 0;
				memset(wordStr, '\0', sizeof(wordStr));
			}
			if (c == ':' && wordposition >= 4 && strcmp(wordStr, "abstract") == 0)
			{
				state = 2;
				wordPosition = 0;
				wordposition = 0;
				memset(wordStr, '\0', sizeof(wordStr));
			}
			if (!separator1 && !separator2 && wordposition >= 4 && n >= 1)
			{
				if (n > 1)
				{
					wordStr[wordPosition] = c;
				}
				strcat_s(word, wordStr);
				memset(wordStr, '\0', sizeof(wordStr));
				if (n == m)
					j = i;
				if (n == 1)
				{
					wordList.addWord(word, _w);
					memset(word, '\0', sizeof(word));
					n = m+1;
					i = j;
				}
				wordPosition = 0;
				wordposition = 0;
				n--;
			}
			i++;
		} 
	     memset(word, '\0', sizeof(word));
	     memset(wordStr, '\0', sizeof(wordStr));
	   i = 0;
	}
	inFile.close();
}
