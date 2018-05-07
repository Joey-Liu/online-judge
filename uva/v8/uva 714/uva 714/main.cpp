#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;

const int maxn = 500 + 20;

int nu[maxn], M, K;

int work(int st)
{
	long long t = 0;
	int ans = 1;
	for (int i = 0; i < M; i++) {
		if (t + nu[i] <= st) {
			t += nu[i];
		}
		else {
			t = nu[i];
			ans += 1;
		}
	}
	return ans;
}

void print(int st) 
{
	bool slash[maxn];
	memset(slash, false, sizeof(slash));
	LL t = 0;
	int remain = K;
	for (int i = M - 1; i >= 0; i--) {
		if (nu[i] + t > st || i + 1 < remain) {
			slash[i] = true;
			t = nu[i];
			remain--;
		}
		else
			t += nu[i];
	}

	for (int i = 0; i < M; i++) {
		if (i)
			cout << " ";
		cout << nu[i];
		if (slash[i]) {
			cout << " /";
		}
	}
	cout << endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--)
	{
		cin >> M >> K;
		LL tot= 0;
		int maxp = -1;

		for (int i = 0; i < M; i++) {
			cin >> nu[i];
			maxp = max(nu[i], maxp);
			tot += nu[i];
		}
		
		LL lp = maxp, rp = tot, mid;
		while (lp < rp) {
			mid = lp + (rp - lp) / 2;
			if (work(mid) <= K)
				rp = mid;
			else
				lp = mid + 1;
		}
		print(lp);
	}//while kasenum
	return 0;
}