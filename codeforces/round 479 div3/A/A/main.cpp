#include <iostream>
#include <stdio.h>

using namespace std;

int N, K;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		if (0 == N % 10) {
			N /= 10;
		}
		else {
			N--;
		}
	}
	cout << N << endl;
	return 0;
}