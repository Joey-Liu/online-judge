#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1000 + 10;

int M, N, r1, c1, r2, c2;
int tab[maxn][maxn];
int buff[maxn][maxn];

struct Node {
	int r, c;
	int stat;
};
vector<Node> vn;

bool cmp(Node n1, Node n2) 
{
	return n1.r < n2.r;
}

void work()
{
	//int sr = lower_bound(vn.begin(), vn.end(), r1, cmp) - vn.begin();
	int sr = 0;
	int flag_0 = false, flag_1 = false;
	for (int i = sr; i < vn.size(); i++) {
		if (vn[i].r > r2)
			break;

		if (vn[i].r >= r1 && vn[i].r <= r2 && vn[i].c >= c1 && vn[i].c <= c2) {
			if (vn[i].stat == 1)
				flag_1 = true;
			else
				flag_0 = true;
		}
	}

	if (flag_0 && flag_1)
		cout << "NaN" << endl;
	else if (flag_0)
		cout << "-inf" << endl;
	else if(flag_1)
		cout << "+inf" << endl;
	else {
		int ans = buff[r2][c2] - buff[r2][c1 - 1] - buff[r1 - 1][c2] + buff[r1 - 1][c1 - 1];
		cout << ans << endl;
	}

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str;
	while (cin >> M >> N) 
	{
		memset(tab, 0, sizeof(tab));
		vn.clear();
		for (int i = 1; i <= M; i++) {
			int rs = 0;
			for (int j = 1; j <= N; j++) {
				cin >> str;
				if (isdigit(str[str.size() - 1])) {
					tab[i][j] = atoi(str.c_str());
				}
				else {
					Node n;
					n.r = i; n.c = j;
					if (str[0] == '+')
						n.stat = 1;
					else
						n.stat = 0;
					vn.push_back(n);
				}

				rs += tab[i][j];
				buff[i][j] = buff[i - 1][j] + rs;
			}
		}//for int i

		sort(vn.begin(), vn.end(), cmp);
		int K;
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> r1 >> c1 >> r2 >> c2;
			work();
		}
	}
	return 0;

}