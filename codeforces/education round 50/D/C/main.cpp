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

typedef long long LL;

const int maxn = 300000 + 50;
LL A[maxn], B[maxn], N, M;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	
	LL s1 = A[0], s2 = B[0], res = 0;
	LL x = 0, y = 0;
	while (x < N || y < M) {
		if (s1 == s2) {
			x++;
			y++;
			res++;
			s1 = 0; s2 = 0;
			if (x < N)
				s1 = A[x];
			if (y < M)
				s2 = B[y];
		}
		else if (s1 < s2) {
			x++;
			if (x >= N) {
				cout << -1 << endl;
				return 0;
			}
			else {
				s1 += A[x];
			}
		}
		else {
			y++;
			if (y >= M) {
				cout << -1 << endl;
				return 0;
			}
			else {
				s2 += B[y];
			}
		}
	}
	cout << res << endl;
	return 0;
}