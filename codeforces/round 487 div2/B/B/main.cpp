#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N, p;
	string str;
	cin >> N >> p;
	cin >> str;
	bool flag = false;


	for (int i = 0; i + p < N; i++) {
		if (str[i] == '.' || str[i + p] == '.') {
			flag = true;
			if (str[i] == '.') {
				if (str[i + p] == '.') {
					str[i] = '0';
					str[i + p] = '1';
				}
				else {
					str[i] = '1' - str[i + p] + '0';
				}
			}
			else {
				str[i + p] = '1' - str[i] + '0';
			}
			break;
		}
		else if (str[i] != str[i + p]) {
			flag = true;
			break;
		}
	}

	if (flag) {
		for (int i = 0; i < N; i++) {
			if (str[i] == '.')
				cout << "1";
			else
				cout << str[i];
		}
	}
	else {
		cout << "No" << endl;
	}
}