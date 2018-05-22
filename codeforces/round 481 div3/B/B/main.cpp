#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> str;
	int ind = 0, res = 0;
	while (ind < N) {
		if (str[ind] == 'x') {
			int st = ind;
			while (ind < N && str[ind] == 'x') {
				ind++;
			}
			if (ind - st >= 3) {
				res += (ind - st - 2);
			}
		}
		ind++;
	}//while ind < N
	cout << res << endl;
	return 0;
}