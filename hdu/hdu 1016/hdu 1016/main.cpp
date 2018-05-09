#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;
const int maxn = 50;

int N;
bool visited[maxn];
bool is_prime[maxn];
vector<int> vi;

bool judge(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (0 == n % i)
			return false;

	}
	return true;
}

void init()
{
	memset(is_prime, false, sizeof(is_prime));
	for (int i = 2; i < maxn; i++) {
		is_prime[i] = judge(i);
	}
}

void dfs(int cur) {
	if (cur == N) {
		if (!is_prime[vi[0] + vi[N - 1]])
			return;
		cout << vi[0];
		for (int i = 1; i < vi.size(); i++) {
			cout << " " << vi[i];
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && is_prime[i + vi[cur - 1]]) {
			visited[i] = true;
			vi.push_back(i);
			dfs(cur + 1);
			visited[i] = false;
			vi.pop_back();
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int kasenum = 0;
	while (cin >> N && N) {
		memset(visited, false, sizeof(visited));
		vi.clear(); vi.push_back(1);
		visited[1] = true;
		cout << "Case " << ++kasenum << ":" << endl;
		dfs(1);
		cout << endl;
	}
}