#include "stdafx.h"
#include "core.h"

bool checkword(char ch) { return ch >= 'a' && ch <= 'z'; }

bool checknumber(char ch) { return ch >= '0' && ch <= '9'; }

unordered_map<string, int> M;

char a[101010];

int CountChar(char *name) {
	int ch;
	FILE *stream;
	freopen_s(&stream, name, "r", stdin);
	int characters = 0, len = 0, rnow = 0;
	while (ch = getchar()) {
		if (ch >= 128) continue;
		if (ch == '\n' || ch == -1) {
			if (rnow == 1) {
				characters += len - 7;
				if (ch != -1) characters++;
			}
			if (rnow == 2) {
				characters += len - 10;
				if (ch != -1) characters++;
			}
			rnow = (rnow + 1) % 5;
			len = 0;
			if (ch == -1) break;
		}
		else len++;
	}
	if (characters == 0) { 
		cout << "File not found!"; 
		exit(1);
	}
	return characters;
}

void ADD(int &n, string *a, string *b, int w, int m, int &cnt) {
	string s;
	rep(i, 1, n - m + 2) {
		s = a[i];
		rep(j, i, i + m - 1) s += b[j], s += a[j + 1];
		M[s] += w;
	}
	cnt += n; n = 0;
}

string word[10100], fg[10100];
int solve(int l, int r, int w, int m) {
	string s;  int ch, now = 0, n1 = 0, cnt = 0;
	string t;
	rep(i, l, r) {
		ch = a[i];
		if (ch >= 'A' && ch <= 'Z') ch -= 'A' - 'a';
		if (now == -2) { if (!checkword(ch) && !checknumber(ch)) now = 0; continue; }

		if (checkword(ch)) {
			now++; s += ch;
			if (now == 1) fg[n1] = t, t = "";
			continue; 
		}
		if (checknumber(ch)) {
			if (now >= 4) now++, s += ch;
			else now = -2, s = "", t = "", ADD(n1, word, fg, w, m, cnt);
			continue;
		}
		if (now >= 4) word[++n1] = s;
		else if (now != 0) ADD(n1, word, fg, w, m, cnt);
		t += ch;s = ""; now = 0;
	}
	if (now >= 4) {
		word[++n1] = s, s = "";
		ADD(n1, word, fg, w, m, cnt);
	}
	return cnt;
}

pii CountWord(char *name) {
	int ch;
	FILE *stream;
	M.clear();
	freopen_s(&stream, name, "r", stdin);
	int words = 0, line = 0, len = 0, rnow = 0;
	while (ch = getchar()) {
		if (ch >= 128) continue;
		if (ch == '\n' || ch == -1) {
			if (rnow == 1) words += solve(7, len, 1, 1), line++;
			if (rnow == 2) words += solve(10, len, 1, 1), line++;
			rnow = (rnow + 1) % 5;
			len = 0;
			if (ch == -1) break;
		}
		else a[len++] = ch;
	}
	return mp(words, line);
}

vector<pair<string, int> > CountFrequentWord(char *name, int w, int m) {
	FILE *stream;
	string s;
	M.clear();
	freopen_s(&stream, name, "r", stdin);
	int len = 0, ch, rnow = 0;
	while (ch = getchar()) {
		if (ch >= 128) continue;
		if (ch == '\n' || ch == -1) {
			if (rnow == 1) solve(7, len, w, m);
			if (rnow == 2) solve(10, len, 1, m);
			rnow = (rnow + 1) % 5;
			len = 0;
			if (ch == -1) break;
		}
		else a[len++] = ch;
	}
	vector<pair<string, int> > tmp;
	for (auto u : M) tmp.pb(u);
	int n = sz(tmp);
	if (sz(tmp) >= 100) {
		nth_element(tmp.begin(),tmp.begin() + 100, tmp.end(), [&](pair<string, int> a, pair<string, int> b) {if (a.se != b.se) return a.se > b.se; return a.fi < b.fi; });
		n = 100;
	}
	sort(tmp.begin(), tmp.begin() + n, [&](pair<string, int> a, pair<string, int> b) {if (a.se != b.se) return a.se > b.se; return a.fi < b.fi; });
	return tmp;
}
