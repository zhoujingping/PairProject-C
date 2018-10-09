#pragma once
#include "stdafx.h"

void add(string &s, unordered_map<string, int> &Map);

bool checkword(char ch);

bool checknumber(char ch);

int CountChar(char *name);

pii CountWord(char *name);

vector<pair<string, int> > CountFrequentWord(char *name, int w, int m);