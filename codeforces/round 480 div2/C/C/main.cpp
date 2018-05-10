#include <iostream>
#include <map>
#include <memory.h>
#include <vector>

using namespace std;

const int maxn = 100000 + 10;
int N, K, nums[maxn];
map<int, int> tab;
vector<int> vi;

int find_aci(int k) {
	if (tab[k] != k) {
		return find_aci(tab[k]);
	}
	return k;
}

void work()
{
	for (int i = 0; i < N; i++) {
		if (tab.count(nums[i])) {
			vi.push_back(tab[nums[i]]);
		}
		else {
			int st = nums[i] - K + 1;
			while (st < 0)
				st++;

			bool flag = false;
			while (tab.count(st)) {
				int x = find_aci(st);
				if (nums[i] - x + 1 <= K) {
					for (int j = x; j <= nums[i]; j++) {
						tab[j] = x;
					}
					flag = true;
					break;
				}
				else {
					st++;
				}
			}

			if (!flag) {
				for (int j = st; j <= nums[i]; j++) {
					tab[j] = st;
				}
			}
			vi.push_back(tab[nums[i]]);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	work();
	cout << vi[0];
	for (int i = 1; i < vi.size(); i++)
		cout << " " << vi[i];
	cout << endl;

}//Kj+ewIT8wnTs