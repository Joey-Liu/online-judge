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

const int maxn = 100000 + 10;
int nums[maxn], kasenum = 0;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	map<int, int> tab;
	queue<int> que;

	cin >> kasenum;
	while (kasenum--) {
		int N, A, B, ind = 0, dis = 0, cur = 0;
		vector<int> vi;
		cin >> N >> A >> B;

		while (ind < A) {
			if (dis < B) {
				vi.emplace_back(cur++);
				dis++;
			}
			else {
				vi.emplace_back(cur - 1);
			}
			ind++;
		}//while ind
		
		while (ind < N) {
			vi.emplace_back(vi[ind - A]);
			ind++;
		}
		string str = "";
		for (int i = 0; i < vi.size(); i++) {
			str += ('a' + vi[i]);
		}
		cout << str << endl;
	} //while

	return 0;
}