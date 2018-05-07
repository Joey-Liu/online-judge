#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
 
using namespace std;
vector<int> vi;
vector<int> en;
int K;

int bi_search(int lp, int rp, int tar) {
	int mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (en[mid] > tar) {
			lp = mid + 1;
		}
		else {
			rp = mid;
		}
	}
	return lp;
}

void work()
{
	en.push_back(vi[0]);
	K = 1;
	
	for (int i = 1; i < vi.size(); i++) {
		int ind = bi_search(0, K, vi[i]);
		if (ind == K) {
			en.push_back(vi[i]);
			K++;
		}
		else {
			en[ind] = vi[i];
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a, kase = 0;
	while (cin >> a && -1 != a) {
		vi.clear();
		en.clear();
		vi.push_back(a);
		if (kase)
			cout << endl;
		

		while (cin >> a && -1 != a) {
			vi.push_back(a);
		}
		work();
		cout << "Test #" << ++kase << ":" << endl;
		cout << "  maximum possible interceptions: " << K << endl;
	}
	return 0;
}