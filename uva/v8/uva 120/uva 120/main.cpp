#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
string str;
int pan;
vector<int> vi, res;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (getline(cin, str)) {
		stringstream ss(str);
		vi.clear();
		res.clear();
		while (ss >> pan)
			vi.push_back(pan);

		cout << vi[0];
		for (int i = 1; i < vi.size(); i++)
			cout << " " << vi[i];
		cout << endl;

		for (int i = 0; i < vi.size() - 1; i++) {
			int maxi = -1, ind = -1;
			int up = vi.size() - 1 - i;
			for (int j = up; j >= 0; j--) {
				if (vi[j] > maxi) {
					maxi = vi[j];
					ind = j;
				}
			}

			res.push_back(ind);
			for (int k = ind; k > ind / 2; k--)
				swap(vi[k], vi[ind - k]);

			res.push_back(up);
			for (int j = up; j > up / 2; j--) {
				swap(vi[j], vi[up - j]);
			}
		}

		if (res.size()) {
			for (int i = 0; i < res.size(); i++)
				cout << vi.size() - res[i] << " ";
		}
		cout << 0 << endl;
	}//while getline
	return 0;
}