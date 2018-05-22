#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int de[] = { -1, 0, 1 };
const int maxn = 100000 + 10;
int N, a[maxn], t[maxn];
const int inf = 0x3f3f3f3f;
bool flag = false;

int work()
{
	int res = 0;
	int c = t[0] - t[1];
	for (int i = 1; i < N - 1; i++) {
		int tmp = t[i] - t[i + 1];
		if (tmp == c) {
			continue;
		}
		else if(tmp - 1 == c){
			t[i + 1] += 1;
			res += 1;
		}
		else if (tmp + 1 == c) {
			t[i + 1] -= 1;
			res += 1;
		}
		else {
			return -1;
		}
	}
	return res;
}

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	if (N == 1 || 2 == N) {
		cout << 0 << endl;
	}
	else {
		int res = inf;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				memcpy(t, a, sizeof(a));
				t[0] += de[i];
				t[1] += de[j];
				
				int r = work();
				if (r >= 0) {
					if (i != 1)
						r++;
					if (j != 1)
						r++;
					flag = true;
					res = min(res, r);
				}
			}
		}
		if (flag) {
			cout << res << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}