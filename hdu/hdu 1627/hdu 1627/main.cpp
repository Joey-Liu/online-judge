#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int N, L, cnt;
bool flag;

bool judge(string s) {
	int len = s.size() - 1;
	for (int i = 1; i * 2 <= s.size(); i++) {
		bool dc = true;
		for (int j = 0; j < i; j++) {
			if (s[len - j] != s[len - i - j]) {
				dc = false;
				break;
			}
		}
		if (dc)
			return true;
	}
	return false;
}

void print(string s) {
	int ind = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i && 0 == i % 4) {
			ind++;
			if (0 == ind % 16)
				cout << endl;
			else
				cout << " ";
		}
		cout << s[i];
	}
	cout << endl << s.size() << endl;
}

void dfs(string str) {
	if (cnt == N) {
		print(str);
		flag = true;
		return;
	}
	for (int i = 0; i < L; i++) {
		string tmp = str + char('A' + i);
		if (!judge(tmp)) {
			cnt++;
			dfs(tmp);
			if (flag)
				return;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> L) {
		if (!N && !L)
			break;
		cnt = 0;
		flag = false;
		string s = "";
		dfs(s);
	}
	return 0;
}