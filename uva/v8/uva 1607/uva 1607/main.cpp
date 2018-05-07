#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int maxn = 200000 + 50;

struct Gate {
	int a, b, o;
}gates[maxn];

int N, M;

int logic(int vn) 
{
	for (int i = 1; i <= M; i++) {
		int a = gates[i].a < 0 ? -gates[i].a <= vn : gates[gates[i].a].o;
		int b = gates[i].b < 0 ? -gates[i].b <= vn : gates[gates[i].b].o;
		gates[i].o = !(a && b);
	}
	return gates[M].o;
}



int work(int state)
{
	int lp = 1, rp = N;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		int v = logic(mid);
		if (v == state) {
			rp = mid;
		}
		else {
			lp = mid + 1;
		}
	}
	return lp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N >> M;
		for (int i = 1; i <= M; i++)
			cin >> gates[i].a >> gates[i].b;
		
		int vn = logic(N);
		int v0 = logic(0);
		if (v0 == vn) {
			for (int i = 0; i < N; i++)
				cout << "0";
			cout << endl;
		}
		else {
			int res = work(vn);
			for (int i = 1; i < res; i++)
				cout << "1";
			cout << "x";
			for (int i = res + 1; i <= N; i++)
				cout << "0";
			cout << endl;
		}
	}//while
	return 0;
}