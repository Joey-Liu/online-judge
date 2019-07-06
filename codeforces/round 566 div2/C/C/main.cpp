#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;

const int maxn = 100000 + 100;
string words[maxn];

struct Node {
	string str;
	char vow;
	int vow_times; 
	
	Node() {
		vow_times = 0;
	}
};

int cmp(Node & n1, Node & n2) {
	return n1.vow_times < n2.vow_times;
}

Node nodes[maxn];
int N;

set<char> vowels;
map<char, vector<Node>> vow_node;



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vowels.insert('a'); vowels.insert('e');
	vowels.insert('i'); vowels.insert('o');
	vowels.insert('u');

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].str;
		for (int j = 0; j < nodes[i].str.size(); j++) {
			if (vowels.count(nodes[i].str[j])) {
				nodes[i].vow = nodes[i].str[j];
				nodes[i].vow_times++;
			}
		}

		vow_node[nodes[i].vow].push_back(nodes[i]);
	}

	vector<PSS> vp, first_vp;
	vector<Node> candi;
	for (auto it = vow_node.begin(); it != vow_node.end(); it++) {
		sort((it->second).begin(), it->second.end(), cmp);
		vector<Node> vn = it->second;

		int lp = 0, rp = 0;
		vector<bool> visited(vn.size(), false);
		while (lp < vn.size()) {
			rp = lp + 1;
			if (rp < vn.size() && vn[lp].vow_times == vn[rp].vow_times) {
				vp.push_back(PSS(vn[lp].str, vn[rp].str));
				visited[lp] = true; visited[rp] = true;
				lp = rp + 1;
				rp = lp;
			}
			else {
				lp = rp;
			}
		}
		for (int i = 0; i < visited.size(); i++) {
			if (!visited[i]) {
				candi.push_back(vn[i]);
			}
		}

	}

	sort(candi.begin(), candi.end(), cmp);
	int lp = 0;
	while (lp < candi.size()) {
		int rp = lp + 1;
		if (rp < candi.size() && candi[lp].vow_times == candi[rp].vow_times) {
			first_vp.push_back(PSS(candi[lp].str, candi[rp].str));
			lp = rp + 1;
		}
		else {
			lp = rp;
		}
	}

	vector<PSS> res;
	int ind = 0;
	while (ind < first_vp.size() && ind < vp.size()) {
		string s1 = first_vp[ind].first + " " + vp[ind].first;
		string s2= first_vp[ind].second + " " + vp[ind].second;
		ind++;
		res.push_back(PSS(s1, s2));
	}

	if (ind < vp.size()) {
		for (int i = ind, j = vp.size() - 1; i < j; i++, j--) {
			string s1 = vp[i].first + " " + vp[j].first;
			string s2 = vp[i].second + " " + vp[j].second;
			res.push_back(PSS(s1, s2));
		}
	}

	cout << res.size() << endl;
	for (PSS pss : res) {
		cout << pss.first << endl;
		cout << pss.second << endl;
	}

	return 0;
}