#include <iostream>
#include <stdio.h>

using namespace std;
const int maxn = 150;

int N, A[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			sum += A[i];
		}

		if (sum % N) {
			cout << -1 << endl;
		}
		else {
			int mean = sum / N;
			bool ok = true;
			for (int i = 0; i < N; i++) {
				A[i] -= mean;
				if (A[i] % 2)
					ok = false;
			}

			if (!ok)
				cout << -1 << endl;
			else {
				int ans = 0;
				for (int i = 0; i < N; i++) {
					if (A[i] > 0)
						ans += A[i];
				}
				cout <<ans / 2 << endl;
			}
		}
	}//while
	return 0;
}