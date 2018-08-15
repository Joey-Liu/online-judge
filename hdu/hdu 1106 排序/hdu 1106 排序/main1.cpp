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
#include <sstream>

using namespace std;

string str;

vector<int> vi;


int partition(int lp, int rp) {
	int piv = vi[rp];
	int x = lp, y = rp;
	while (x < y) {
		while (x < y && vi[x] <= piv)
			x++;

		vi[y] = vi[x];
		while (x < y && vi[y] > piv)
			y--;
		vi[x] = vi[y];
	}//while
	vi[x] = piv;
	return x;
}

void quick_sort(int lp, int rp) {
	if (lp >= rp) {
		return;
	}

	int pos = partition(lp, rp);
	quick_sort(lp, pos - 1);
	quick_sort(pos + 1, rp);

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> str) {
		vi.clear();
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '5') {
				str[i] = ' ';
			}
		}

		stringstream ss(str);
		int tmp;
		while (ss >> tmp) {
			vi.push_back(tmp);
		}

		//sort(vi.begin(), vi.end());
		int N = vi.size();
		quick_sort(0, N - 1);
		cout << vi[0];
		for (int i = 1; i < vi.size(); i++)
			cout << " " << vi[i];
		cout << endl;
	}//while

	return 0;
}