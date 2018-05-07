#include <iostream>

using namespace std;

int main() {
	int N, sum = 0, t = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		sum += t;
	}
	if (sum % 2)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}