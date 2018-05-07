#include <iostream>
#include <string>
using namespace std;

int N;
string s;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	cin >> s;
	if ("0" == s) {
		cout << s;
	}
	else {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if ('0' == s[i])
				cnt++;
		}
		cout << 1;
		for (int i = 0; i < cnt; i++)
			cout << 0;
		cout << endl;
	}
	return 0;
}