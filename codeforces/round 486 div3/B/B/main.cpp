#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 100 + 5;
string str[maxn];
int N;

bool cmp(string s1, string s2) {
	return s1.size() < s2.size();
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	sort(str, str + N, cmp);

	for (int i = 1; i < N; i++) {
		if (string::npos == str[i].find(str[i - 1])) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < N; i++) {
		cout << str[i] << endl;
	}

	return 0;

}