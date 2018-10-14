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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 2e5 + 50;

int nums[maxn], N, M, K;

bool work(int amount) {
	int ind = N - amount;
	int space = K, boxes = M - 1;

	while (ind < N) {
		if (space >= nums[ind]) {
			space -= nums[ind];
			ind++;
		}
		else {
			if (boxes <= 0)
				return false;
			boxes--;
			space = K;
		}
	}//while
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int lp = 0, rp = N + 1;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		if (work(mid)) {
			lp = mid + 1;
		}
		else {
			rp = mid;
		}
	}//while
	cout << lp - 1 << endl;
	return 0;
}