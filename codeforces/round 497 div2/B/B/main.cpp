#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int N;
int w, h;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	int a, b, prev;
	cin >> a >> b;
	prev = max(a, b);

	bool ok = true;

	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		if (a < b) {
			swap(a, b);
		}

		if (b > prev) {
			ok = false;
		}
		if (a <= prev) {
			prev = a;
		}
		else {
			prev = b;
		}

	}

	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}