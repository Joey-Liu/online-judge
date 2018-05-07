#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

void work(int a[], int len, int k)
{
	deque<int> dq;
	for(int i = 0;i < len;i++) {
		if (i >= k) {
			cout << dq.front() << " ";
			if (dq.front() == a[i - k])
				dq.pop_front();
		}
		while (!dq.empty() && dq.back() > a[i])
			dq.pop_back();
		dq.push_back(a[i]);
	}
	cout << dq.front() << endl;;
}

int main()
{
	int a[] = { 5, 2, 6, 8, 10, 7, 4 };
	int k = 4;
	int n = 7;
	work(a, n, k);
	cin >> k;
	return 0;
}