#include <iostream>

using namespace std;
const int maxn = 200000 + 10;

typedef long long LL;
int N, nums[maxn];
LL res;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int ind = 0, state = 0;
	bool flag = true;
	LL res = 0;

	if (nums[0] != 0) {
		cout << -1 << endl;
		return 0;
	}

	while (ind < N) {
		if(ind != 0 && nums[ind] > nums[ind - 1]) {
			flag = false;
			break;
		}
		else {
			int st = ind;
			while (ind + 1 < N && (nums[ind + 1] == nums[ind] || nums[ind + 1] == nums[ind] + 1))
				ind++;

			int ed = ind, nu = nums[ed];
			res += nums[ed];
			while (ed >= st) {
				if (nu == nums[ed]) {
					ed--;
					nu--;
				}
				else {
					res += nums[ed];
					ed--;
				}
			}//while
			ind += 1;
		}//else 

	}//while ind
	if (!flag)
		cout << -1 << endl;
	else
		cout << res << endl;
	return 0;
}