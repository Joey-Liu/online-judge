#include <iostream>
#include <memory.h>

using namespace std;

typedef long long LL;
const LL maxn = 100 + 50;

struct Node {
	LL nu;
};

LL nodes[maxn], du[maxn], jin[maxn];
LL tab[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (LL i = 0; i < N; i++) {
		cin >> nodes[i];
	}

	for (LL i = 0; i < N; i++) {
		for (LL j = 0; j < N; j++) {
			if (nodes[i] * 2 == nodes[j] || nodes[j] * 3 == nodes[i])
			{
				tab[i] = j;
				du[i]++;
				jin[j]++;
			}
		}
	}

	LL ind = -1;
	for (LL i = 0; i < N; i++) {
		if (0 == jin[i]) {
			ind = i;
			break;
		}
	}

	cout << nodes[ind];
	while (true) {
		if (!du[ind])
			break;
		ind = tab[ind];
		cout << " " << nodes[ind];
	}
	cout <<  endl;
	return 0;
}