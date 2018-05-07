#include <iostream>
#include <map>
#include <memory.h>

using namespace std;

const int maxn = 200000 + 10;

map<int, int> left_tab, right_tab;
int N, A[maxn], left_p[maxn], right_p[maxn];

bool work(int lp, int rp)
{
	if (lp >= rp)
		return true;

	bool flag = false;
	int ind = -1;
	for (int i = 0; lp + i <= rp - i; i++) {
		if (left_p[i + lp] < lp && right_p[i + lp] > rp) {
			flag = true;
			ind = lp + i;
			break;
		}
		if (left_p[rp - i] < lp && right_p[rp - i] > rp) {
			flag = true;
			ind = rp - i;
			break;
		}
	}
	if (!flag)
		return false;

	return work(lp, ind - 1) && work(ind + 1, rp);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];

		left_tab.clear();
		for (int i = 0; i < N; i++) {
			if (!left_tab.count(A[i]))
				left_p[i] = -1;
			else
				left_p[i] = left_tab[A[i]];
			left_tab[A[i]] = i;
		}

		right_tab.clear();
		for (int i = N - 1; i >= 0; i--) {
			if (!right_tab.count(A[i]))
				right_p[i] = maxn;
			else
				right_p[i] = right_tab[A[i]];
			right_tab[A[i]] = i;
		}
		bool ans = work(0, N - 1);
		if (ans)
			cout << "non-boring" << endl;
		else
			cout << "boring" << endl;
	}//while
	return 0;
}