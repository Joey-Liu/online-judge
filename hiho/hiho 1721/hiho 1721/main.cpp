#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

bool check(string str, int lp, int rp) {
	while (lp < rp) {
		if (str[lp] != str[rp])
			return false;
		lp++;
		rp--;
	}
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string str;
	cin >> str;
	int i = 0, j = str.size() - 1;
	while (i <= j) {
		if (str[i] != str[j])
			break;
		i++; j--;
	}

	int ind = -1;
	if (i != j) {
		if (check(str, i + 1, j)) {
			ind = i;
		}
		else {
			ind = j;
		}
	}
	else {
		ind = i;
	}
	while (ind > 0 && str[ind - 1] == str[ind])
		ind--;
	cout << ind + 1 << endl;

	return 0;
}