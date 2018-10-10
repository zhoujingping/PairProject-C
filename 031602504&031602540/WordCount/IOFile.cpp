#pragma once
#include"pch.h"
#include"IOFile.h"
string IOFile::GetString(string filename)
{
	content = "";
	FILE *filein;
	int err = fopen_s(&filein, filename.c_str(), "r");
	if (err)
	{
		printf("open erro!\n");
	}
	char onechar;
	err = fread(&onechar, sizeof(char), 1, filein);
	while (err)
	{
		if (onechar >= 65 && onechar <= 90)
		{
			onechar += 32;
		}
		content += onechar;
		err = fread(&onechar, sizeof(char), 1, filein);
	}
	fclose(filein);
	return content;
}
void IOFile::OutString(string filename)
{
	FILE *fileout;
	int err = fopen_s(&fileout,filename.c_str(),"w");
	if (err)
	{
		printf("open erro!\n");
	}
	fwrite(ex_content.c_str(),ex_content.length(),1,fileout);
	fclose(fileout);
}