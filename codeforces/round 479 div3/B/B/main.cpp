#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> msi;

int N;
string str;

int main()
{
	cin >> N >> str;
	for (int i = 0; i < N - 1; i++) {
		string s(str.begin() + i, str.begin() + i + 2);
		msi[s]++;
	}

	int maxi = -1;
	string ans;
	for (map<string, int>::iterator it = msi.begin(); it != msi.end(); it++) {
		if (it->second > maxi) {
			maxi = it->second;
			ans = it->first;
		}
	}
	cout << ans << endl;
	cin >> N;
}