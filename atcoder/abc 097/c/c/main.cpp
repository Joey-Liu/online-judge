#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;
string str, tmp;
int K;
unordered_set<string> vs;
priority_queue<string> pq;

bool flag = false;

void work() {
	int ind = 0;
	for (int i = 0; i < str.size(); i++) {
		for (int j = i; j < str.size(); j++) {
			int len = j - i + 1;
			if (len > K) {
				continue;
			}
			tmp = str.substr(i, len);
			if (vs.count(tmp))
				continue;
			vs.insert(tmp);
			if (ind < K)
				pq.push(tmp);
			else {
				if (pq.top() > tmp) {
					pq.pop();
					pq.push(tmp);
				}
			}
			ind++;
		}
		if (flag)
			break;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> str >> K;
	work();

	cout<<pq.top()<<endl;
	return 0;
}