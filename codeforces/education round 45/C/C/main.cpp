#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

typedef long long LL;
int N;
string str;
map<pair<int, int>, LL> tab;

void work() {
	stack<char> sc;
	bool flag = false;
	int clef = 0, crig = 0;

	for (int i = 0; i < int(str.size()); i++) {
		if ('(' == str[i]) {
			sc.push('(');
		}
		else {
			if (!sc.empty()) {
				sc.pop();
			}
			else {
				crig++;
			}
		}
	}
	clef = sc.size();
	pair<int, int> pii(clef, crig);
	tab[pii]++;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		work();
	}

	LL ans = 0;
	for (auto it = tab.begin(); it != tab.end(); it++) {
		pair<int, int> x = it->first;
		LL cnt_1 = it->second;

		if (x.first != 0 && x.second != 0)
			continue;
		if (x.first == 0 && x.second == 0)
			continue;

		LL cnt_2;
		if (x.first) {
			pair<int, int> y = make_pair(0, x.first);
			cnt_2 = tab[y];
		}
		else {
			pair<int, int> y = make_pair(x.second, 0);
			cnt_2 = tab[y];
		}
		ans += cnt_1 * cnt_2;
	}
	ans /= 2;
	
	pair<int, int> pii = make_pair(0, 0);
	ans += tab[pii] * tab[pii];
	cout << ans << endl;
	return 0;
}