#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int maxn = 16 + 20;

struct Node {
	string name;
	int rate;
	int win_b;
	int lose_b;
};

map<string, int> tab;
vector<Node> vn;

int get_id(string name) 
{
	if (tab.count(name))
		return tab[name];

	Node n;
	n.name = name;
	n.rate = 0;
	n.lose_b = 0;
	n.win_b = 0;
	vn.push_back(n);
	return tab[name] = vn.size() - 1;
}

bool cmp(Node n1, Node n2) 
{
	if (n1.rate != n2.rate)
		return n1.rate > n2.rate;
	
	int a = n1.win_b - n1.lose_b;
	int b = n2.win_b - n2.lose_b;
	if (a != b)
		return a > b;

	if (n1.win_b != n2.win_b)
		return n1.win_b > n2.win_b;
	return n1.name < n2.name;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int ind = 0;
	string s1, s2;
	char sc;
	int n1, n2;
	bool first = true;
	while (cin >> s1) {
		if (!first)
			cout << endl;
		first = false;
		ind = 0;
		while(ind < 4) {
			vn.clear();
			tab.clear();
			for (int i = 0; i < 6; i++) {
				if (!ind && !i)
					cin >> n1 >> sc >> n2 >> s2;
				else
					cin >> s1 >> n1 >> sc >> n2 >> s2;
				int id_1 = get_id(s1), id_2 = get_id(s2);

				if (n1 == n2) {
					vn[id_1].rate += 1;
					vn[id_2].rate += 1;
				}
				else if (n1 > n2) {
					vn[id_1].rate += 3;
				}
				else {
					vn[id_2].rate += 3;
				}

				vn[id_1].win_b += n1;
				vn[id_2].win_b += n2;
				vn[id_1].lose_b += n2;
				vn[id_2].lose_b += n1;
			}//for int i
			sort(vn.begin(), vn.end(), cmp);
			cout << vn[0].name;
			for (int i = 1; i < vn.size(); i++)
				cout << " " << vn[i].name;
			cout << endl;
			ind++;
		}//while ind < 4
	}//while cin>>s1
	return 0;
}