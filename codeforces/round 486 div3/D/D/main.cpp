#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
set<LL> si;
int N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		LL a;
		cin >> a;
		si.insert(a);
	}

	for (auto it = si.begin(); it != si.end(); it++) {
		LL t = *it;
		for (LL j = 1; j <= (*si.rbegin() - *si.begin()) / 2; j = j << 1) {
			if (si.count(t + j) && si.count(t - j)) {
				cout << "3" << endl;
				cout << t - j << " " << t << " " << t + j << endl;
				return 0;
			}
		}
	}

	for (auto it = si.begin(); it != si.end(); it++) {
		LL t = *it;
		for (LL j = 1; j <= *si.rbegin() - t; j = j << 1) {
			if (si.count(t + j)) {
				cout << "2" << endl;
				cout << t << " " << t + j << endl;
				return 0;
			}
		}
	}
	cout << "1" << endl;
	cout << *si.begin() << endl;
	return 0;
}