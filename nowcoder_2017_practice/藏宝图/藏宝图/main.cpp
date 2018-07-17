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

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string s, t;
	cin >> s >> t;
	int len_1 = s.size(), len_2 = t.size();
	int i = 0, j = 0;

	while (i < len_1 && j < len_2) {
		if (s[i] == t[j]) {
			i++; j++;
		}
		else {
			i++;
		}
	}
	if (j == len_2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}