#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 30 * 4;
struct Node
{
	int a, b, c;
	Node(int _a = -1, int _b = -1, int _c = -1) :a(_a), b(_b), c(_c) {}
};

int N;
vector<Node> vn;
int tab[maxn][maxn];
int dp[maxn];

bool check(Node n1, Node n2) 
{	
	if ((n1.a > n2.a && n1.b > n2.b) || (n1.b > n2.a && n1.a > n2.b))
		return true;
	return false;
}

void build_graph()
{
	memset(tab, 0, sizeof(tab));
	for (int i = 0; i < vn.size(); i++) {
		for (int j = 0; j < vn.size(); j++) {
			if (check(vn[i], vn[j]))
				tab[i][j] = 1;
		}
	}
}

int work(int ind) 
{
	if (dp[ind] > 0)
		return dp[ind];
	
	int ans = vn[ind].c;
	for (int i = 0; i < vn.size(); i++) {
		if (tab[ind][i]) {
			ans = max(ans, vn[ind].c + work(i));
		}
	}
	return dp[ind] = ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase = 0;
	while (cin >> N && N) {
		vn.clear();
		int a, b, c;
		for (int i = 0; i < N; i++) {
			cin >> a >> b >> c;
			Node n1(a, b, c);
			vn.push_back(n1);
			Node n2(a, c, b);
			vn.push_back(n2);
			Node n3(b, c, a);
			vn.push_back(n3);
		}

		build_graph();
		memset(dp, 0, sizeof(dp));
		int ans = -1;
		for (int i = 0; i < vn.size(); i++) {
			ans = max(ans, work(i));
		}
		cout << "Case " << ++kase << ": maximum height = ";
		cout << ans << endl;
	}//while
	return 0;
}