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

const int maxn = 200 + 10;
int A[maxn], B[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int j = 0; j < M; j++) {
		cin >> B[j];
	}

	for (int k = 0; k < (1 << 9); k++) {
		bool flag = true;
		for (int i = 0; i < N; i++) {
			bool tmp_flag = false;

			for (int j = 0; j < M; j++) {
				int temp = A[i] & B[j];
				if ((temp | k) == k) {
					tmp_flag = true;
					break;
				}
			}

			if (tmp_flag == false) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << k << endl;
			break;
		}
	}

	return 0;
}