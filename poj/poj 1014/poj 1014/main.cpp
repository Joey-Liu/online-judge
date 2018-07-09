#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 20000 * 6 + 10;

bool dp[maxn];
int A[7], tar;

void zeroone_pack(int v) {
	for (int i = tar; i >= v; i--) {
		dp[i] = (dp[i] || dp[i - v]);
	}
}

void comp_pack(int v) {
	for (int i = v; i <= tar; i++) {
		dp[i] = (dp[i] || dp[i - v]);
	}
}


void multi_pack(int v, int cnt) {
	if (cnt * v >= tar) {
		comp_pack(v);
	}

	for (int i = 1; i <= cnt; i *= 2) {
		zeroone_pack(i * v);
		cnt -= i;
	}
	zeroone_pack(cnt * v);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int ind = 0;
	while (true) {
		bool flag = false;
		for (int i = 1; i < 7; i++) {
			cin >> A[i];
			if (A[i])
				flag = true;
		}

		if (!flag)
			break;
		if (ind)
			cout << endl;
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		int tot_val = 0;
		for (int i = 1; i < 7; i++) {
			tot_val += i * A[i];
		}

		cout << "Collection #" << ++ind <<":"<< endl;
		if (tot_val & 1)
			cout << "Can't be divided." << endl;
		else {
			tar = tot_val >> 1;
			for (int i = 1; i < 7; i++) {
				if (!A[i])
					continue;
				multi_pack(i, A[i]);
			}//for int i

			if (dp[tar])
				cout << "Can be divided." << endl;
			else
				cout<<"Can't be divided." << endl;
		}
	}//while true
	return 0;
}