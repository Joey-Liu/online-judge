#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 150;

vector<vector<string> > pre(50);
vector<vector<string> > cur(50);
int N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		pre[str.size()].push_back(str);
	}

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		cur[str.size()].push_back(str);
	}

	int ans = 0;
	for (int i = 2; i < 50; i++) {
		if (cur[i].size() == 0)
			continue;

		int a = 0, b = 0;
		int p = 0, q = 0;
		for (int j = 0; j < cur[i].size(); j++) {
			string str = cur[i][j];
			if (str[i - 1] == 'S')
				p++;
			else
				q++;
		}

		for (int j = 0; j < pre[i].size(); j++) {
			string str = pre[i][j];
			if (str[i - 1] == 'S')
				a++;
			else
				b++;
		}
		ans += abs(a - p);
	}

	int a = 0, b = 0, c = 0;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < cur[1].size(); i++) {
		string str = cur[1][i];
		if (str[0] == 'M')
			a++;
		else if (str[0] == 'S')
			b++;
		else
			c++;
	}
	for (int i = 0; i < pre[1].size(); i++) {
		string str = pre[1][i];
		if (str[0] == 'M')
			x++;
		else if (str[0] == 'S')
			y++;
		else
			z++;

	}

	ans += max(a - x, 0);
	ans += max(b - y, 0);
	ans += max(c - z, 0);
	cout << ans << endl;

	return 0;
}