#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

const int maxn = 20 + 10;
int N, state[5];

int cadi[maxn], cadi_nu, res;
string str;

bool judge(int t0, int t1, int t2, int t3, int t4)
{
	if (!(state[0] & t0) && !(state[1] & t1) && !(state[2] & t2)
		&& !(state[3] & t3) && !(state[4] & t4))
		return true;
	return false;
}

void init()
{
	memset(state, 0, sizeof(state));
	memset(cadi, 0, sizeof(cadi));
	res = 10 * N;
	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int j = N - 1; j >=0; j--) {
			state[i] = (state[i] << 1) + (str[j] == 'X');
		}//for int j
	}//for int i
	
	cadi_nu = 0;
	for (int i = 1; i <= N; i++) {
		if (judge(state[0] >> i, state[1] >> i, state[2] >> i, state[3] >> i, state[4] >> i))
			cadi[cadi_nu++] = i;
	}
}

void dfs(int layer, int ans, int t0, int t1, int t2, int t3, int t4) 
{
	if (ans + cadi[0] * (9 - layer) > res)
		return;
	if (layer == 9) {
		res = min(res, ans);
		return;
	}
	

	for (int i = 0; i < cadi_nu; i++) {
		int s0 = t0 >> cadi[i], s1 = t1 >> cadi[i], s2 = t2 >> cadi[i], s3 = t3 >> cadi[i], s4 = t4 >> cadi[i];
		if (judge(s0, s1, s2, s3, s4))
			dfs(layer + 1, ans + cadi[i], s0 ^ state[0], s1 ^ state[1], s2 ^ state[2], s3 ^ state[3], s4 ^ state[4]);
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> N && N) { 
		init();
		dfs(0, N, state[0], state[1], state[2], state[3], state[4]);
		cout << res << endl;
	}
	return 0;
}