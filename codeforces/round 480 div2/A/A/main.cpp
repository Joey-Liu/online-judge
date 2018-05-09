#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>

using namespace std;
string str;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> str;
	int a = 0, b = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			a++;
		}
		else {
			b++;
		}
	}
	if (a == 0 || b == 0) {
		cout << "YES" << endl;
	}
	else {
		if (0 == a % b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}