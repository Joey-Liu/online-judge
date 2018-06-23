#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
bool vis[400000 + 10];

string str;
int N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> str;
	
	for (int i = 2; i <= N; i++) {
		if (N % i)
			continue;
		string sub = str.substr(0, i);
		reverse(sub.begin(), sub.end());
		str = sub + str.substr(i);
	}
	cout << str << endl;
	return 0;
}