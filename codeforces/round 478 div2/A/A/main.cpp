#include <iostream>
#include <stdio.h>
#include <set>
#include <string>

using namespace std;
int N;
set<set<char> > ssc;
string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		set<char> sc;
		for (int i = 0; i < str.size(); i++) {
			sc.insert(str[i]);
		}
		ssc.insert(sc);
	}
	cout << ssc.size() << endl;
	return 0;
}