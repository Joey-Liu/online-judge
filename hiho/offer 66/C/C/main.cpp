#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
int N, A, B;


int main()
{
	
	cin >> N >> A >> B;
	int ans = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j >= 1; j = i & (j - 1)) {
			ans = max(ans, (A * i + B * j) ^ (A * j + B * i));
		}
	}
	cout << ans << endl;
	system("pause");

	return 0;
}