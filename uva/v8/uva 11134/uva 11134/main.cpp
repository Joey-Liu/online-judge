#include <iostream>
#include <memory.h>

using namespace std;

const int maxn = 5000 + 50;
int N;
int xl[maxn], yl[maxn], xr[maxn], yr[maxn];
int row[maxn], col[maxn];
bool used[maxn];

bool work(int pos[], int left[], int right[])
{	
	memset(used, false, sizeof(used));
	for (int i = 1; i <= N; i++) {
		int mini = 0x7fffffff, ind = -1;
		for (int j = 0; j < N; j++) {
			if (!used[j] && left[j] <= i && right[j] >= i && right[j] < mini) {
				mini = right[j];
				ind = j;
			}
		}//for int j
		if (ind < 0)
			return false;
		pos[ind] = i;
		used[ind] = true;
	}//for int i
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N && N) {
		for (int i = 0; i < N; i++) {
			cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
		}
		int pos_x[maxn], pos_y[maxn];
		if (work(pos_x, xl, xr) && work(pos_y, yl, yr)) {
			for (int i = 0; i < N; i++) {
				cout << pos_x[i] << " " << pos_y[i] << endl;
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}//while cin>>N

	return 0;
}