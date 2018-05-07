#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 5000 + 20;
int nu[maxn], N;

queue<int> q, p;
int main()
{
	while (cin >> N && N) {
		while (!q.empty())
			q.pop();
		while (!p.empty())
			p.pop();

		for (int i = 0; i < N; i++)
			cin >> nu[i];
		sort(nu, nu + N);

		for (int i = 0; i < N; i++)
			q.push(nu[i]);
		int K = N - 1;
		int res = 0;
		while (K--) {
			int a[2] = { 0 };
			for(int i = 0; i< 2;i++) {
				if(q.empty() || !p.empty() && p.front() < q.front()) {
					a[i] = p.front();
					p.pop();
				}
				else {
					a[i] = q.front();
					q.pop();
				}
			}//for int i
			int t = a[0] + a[1];
			res += t;
			p.push(t);
		}//while k
		cout << res << endl;
	}//while cin>>N
	return 0;
}