#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	string str;
	set<string> sst;
	while (cin >> str) {
		sst.insert(str);
	}

	cout << sst.size() << endl;
	return 0;
}