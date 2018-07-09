#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

string str;
int N;

bool check() {
	int ind = 0;
	for (; ind < N; ind++) {
		if (str[ind] >= 'A' && str[ind] <= 'Z')
			break;
	}

	for (int i = ind + 1; i < N; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			return false;
	}

	return true;
}

bool xia(char c) {
	return c >= 'a' && c <= 'z';
}

bool dax(char c) {
	return c >= 'A' && c <= 'Z';
}

int main()
{
	while (cin >> str) {
		N = str.size();
		while (!check()) {
			
			int i = 0, j = 0;
			while (i < N - 1) {
				if (dax(str[i]) && xia(str[i + 1]))
					swap(str[i], str[i + 1]);
				i++;
			}
		}//while check
		cout << str << endl;
	}
	return 0;
}