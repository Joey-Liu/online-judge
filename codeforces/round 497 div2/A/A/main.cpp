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
	string str;
	cin >> str;

	set<char> sc;
	sc.insert('a');
	sc.insert('o'); sc.insert('u'); sc.insert('i'); sc.insert('e');
	int N = str.size(); 

	for (int i = 0; i < N - 1; i++) {
		if (str[i] == 'n' || sc.count(str[i]))
			continue;
		if (!sc.count(str[i + 1])) {
			cout << "NO" << endl;
			return 0;
		}
	}

	if (sc.count(str[N - 1]) || str[N - 1] == 'n')
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}