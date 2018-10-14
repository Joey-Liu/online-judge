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

void bubble_sort(vector<int> & vi) {
	int N = vi.size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (vi[j] > vi[j + 1])
				swap(vi[j], vi[j + 1]);
		}
	}//for int i

}

int CountZero(int N)
{
	int ret = 0;
	while (N)
	{
		ret += N / 5;
		N /= 5;
	}
	return ret;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int res = CountZero(10000);
	cout << res << endl;
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
		//quick_sort(0, N - 1);
		bubble_sort(vi);
		cout << vi[0];
		for (int i = 1; i < vi.size(); i++)
			cout << " " << vi[i];
		cout << endl;
	}//while

	return 0;
}