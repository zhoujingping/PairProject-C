#pragma once
#include<iostream>
using namespace std;
class IOFile
{
	private:
		string content;
		string ex_content;
	public:
		IOFile() {}
		~IOFile() {}
		string GetString(string filename = "input.txt");
		void OutString(string filename = "result.txt");
};