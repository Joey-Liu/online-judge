#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, pair<int, int> > tab;
const int maxn = 200000 + 20;
int K, N, nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> N;
		int su = 0;
		for (int j = 1; j <= N; j++) {
			cin >> nums[j];
			su += nums[j];
		}
		for (int j = 1; j <= N; j++) {
			int t = su - nums[j];
			if (tab.count(t)) {
				pair<int, int> pii = tab[t];
				if (pii.first == i)
					continue;
				cout << "YES" << endl;
				cout << pii.first << " " << pii.second << endl;
				cout << i << " " << j << endl;
				return 0;
			}
			else {
				pair<int, int> pii(i, j);
				tab[t] = pii;
			}
		}//for int j
	}//for int i
	cout << "NO" << endl;
	return 0;
}