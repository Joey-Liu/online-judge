#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
int N, K;
map<int, int> tab;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		tab[a] = i;
	}

	if (tab.size() < K)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int ind = 0;
		bool first = true;

		for (auto it = tab.begin(); it != tab.end(); it++) {
			if (ind >= K)
				break;
			if (first) {
				cout << it->second;
				first = false;
			}
			else {
				cout << " " << it->second;
			}
			ind++;
		}
	}
	return 0;
}