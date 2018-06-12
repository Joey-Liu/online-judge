#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str;
	cin >> str;
	bool flag = false;
	int N = str.size();

	for (int i = 1; i < N - 1; i++) {
		if ('.' == str[i])
			continue;
		if (str[i] != str[i - 1] && str[i] != str[i + 1] && str[i - 1] != str[i + 1]) {
			if (str[i - 1] == '.' || str[i + 1] == '.')		
				continue;
			flag = true;
			break;
		}
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}