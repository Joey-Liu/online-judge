#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 2000 + 10;
pii data[MAXN]; // {scores, numbers} of room i
vector<int> groups[MAXN]; // the groups of room i
int ret[MAXN], start[MAXN];

int main() {
	//    freopen("test.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(ret, -1, sizeof(ret));
	int n, r1, r2, r3, k, val, scores;
	cin >> n >> r1 >> r2 >> r3;
	set<pii> rooms, ready, black;
	int id = 0;
	for (int i = 0; i < n; i++) {
		scores = 0;
		cin >> start[i] >> k;
		for (int j = 0; j < k; j++) {
			cin >> val;
			scores += val;
		}
		if (k == 6) {
			bool done = false;
			for (auto it3 = black.begin(); it3 != black.end(); it3++) {
				int tmp_id = it3->second;
				if (abs(data[tmp_id].first / data[tmp_id].second - scores / k) <= r3) {
					ret[groups[tmp_id][0]] = start[i] - it3->first;
					ret[i] = 0;
					black.erase(it3);
					done = true;
					break;
				}
			}
			if (!done) {
				data[id].first = scores;
				data[id].second = k;
				groups[id].push_back(i);
				black.insert({ start[i], id++ });
			}
			continue;
		}
		auto it = rooms.begin();
		auto it2 = rooms.end();
		for (; it != rooms.end(); it++) {
			int tmp_id = it->second;
			if (data[tmp_id].second + k > 6) continue;
			if (abs(data[tmp_id].first / data[tmp_id].second - scores / k) <= r1) break;
			if (it2 == rooms.end() && start[i] - it->first >= r2) it2 = it;
		}
		if (it == rooms.end() && it2 != rooms.end()) it = it2;
		if (it == rooms.end()) {
			rooms.insert({ start[i], id });
			data[id].first = scores;
			data[id].second = k;
			groups[id].push_back(i);
			it = rooms.lower_bound({ start[i], id });
			id++;
		}
		else {
			int tmp_id = it->second;
			data[tmp_id].first += scores;
			data[tmp_id].second += k;
			groups[tmp_id].push_back(i);
		}
		pii cur = { -1, -1 };
		if (data[it->second].second == 6) {
			cur = { it->first, it->second };
			rooms.erase(it);
		}
		if (cur.second != -1) {
			int my_id = cur.second;
			bool done = false;
			for (auto it4 = ready.begin(); it4 != ready.end(); it4++) {
				int tmp_id = it4->second;
				if (abs(data[tmp_id].first / data[tmp_id].second - data[my_id].first / data[my_id].second) <= r3) {
					for (int g : groups[tmp_id]) {
						ret[g] = start[i] - start[g];
					}
					for (int g : groups[my_id]) {
						ret[g] = start[i] - start[g];
					}
					ready.erase(it4);
					done = true;
					break;
				}
			}
			if (!done) ready.insert(cur);
		}

	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << '\n';
	}
	return 0;
}