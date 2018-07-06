#include <iostream>
#include <map>
#include <memory.h>
#include <string>
#include <math.h>

using namespace std;
string str;
map<char, int> crow;
map<char, int> ccol;

void init() {
	for (char c = 'A'; c <= 'C'; c++) {
		crow[c] = 0;
		ccol[c] = 1;
	}

	for (char c = 'D'; c <= 'F'; c++) {
		crow[c] = 0;
		ccol[c] = 2;
	}

	int ind = 0;
	for (char c = 'G'; c <= 'O'; c++) {
		crow[c] = 1;
		ccol[c] = ind / 3;
		ind++;
	}
	
	for (char c = 'P'; c <= 'S'; c++) {
		crow[c] = 2;
		ccol[c] = 0;
	}
	for (char c = 'T'; c <= 'V'; c++) {
		crow[c] = 2;
		ccol[c] = 1;
	}

	for (char c = 'W'; c <= 'Z'; c++) {
		crow[c] = 2;
		ccol[c] = 2;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	init();
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> str;
		int ans = 0;

		ans += (crow[str[0]] + ccol[str[0]]);
		int r = crow[str[0]], c = ccol[str[0]];
		for (int i = 1; i < int(str.size()); i++) {
			int a = abs(crow[str[i]] - r), b = abs(ccol[str[i]] - c);
			ans = ans + a + b;
			r = crow[str[i]]; c = ccol[str[i]];
		}
		cout << ans << endl;
	}

	return 0;
}