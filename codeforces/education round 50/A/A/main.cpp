#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long LL;;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	LL N, K;
	cin >> N >> K;
	LL res = K / N;
	
	if (res * N == K) {
		cout << res << endl;
	}
	else {
		cout << res + 1 << endl;
	}

	return 0;
}