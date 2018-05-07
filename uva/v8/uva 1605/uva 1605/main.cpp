#include <iostream>

using namespace std;
int N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	bool is_first = true;
	while (cin >> N) {
		is_first = false;
		cout << "2 " << N << " " << N << endl;
		for (int i = 0; i < N; i++) {
			char c = (i < 26 ? 'A' + i : 'a' + i - 26);
			for (int j = 0; j < N; j++)
				cout << c;
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				char c = (j < 26 ? 'A' + j : 'a' + j - 26);
				cout << c;
			}
			cout << endl;
		}
	}
	return 0;
}