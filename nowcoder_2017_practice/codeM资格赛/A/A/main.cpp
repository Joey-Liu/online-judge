#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <map>
#include <algorithm>

using namespace std;
const int maxn = 20;
double price[maxn];
int sale[maxn];
map<int, int> tab;
int N, M;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(sale, 0, sizeof(sale));
	cin >> N >> M;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> price[i];
		cin >> sale[i];
		sum += price[i];
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		tab[x] = y;
	}

	double ans_1 = sum;
	for (auto it = tab.begin(); it != tab.end(); it++) {
		if (sum >= it->first) {
			double t = sum - it->second;
			ans_1 = min(t, ans_1);
		}
	}
	
	double ans_2 = 0;
	for (int i = 0; i < N; i++) {
		if (sale[i])
			ans_2 += price[i] * 0.8;
		else
			ans_2 += price[i];
	}

	double ans = min(ans_1, ans_2);
	printf("%.2lf\n", ans);
	return 0;
}