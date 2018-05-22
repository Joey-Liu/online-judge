#include <iostream>
#include <set>
#include <stack>

const int maxn = 50 + 10;
using namespace std;

stack<int> st;
set<int> si;
int N, nums[maxn];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	bool flag = false;
	for (int i = N - 1; i >= 0; i--) {
		if (!si.count(nums[i])) {
			st.push(nums[i]);
			si.insert(nums[i]);
		}
	}

	cout << st.size() << endl;
	while (!st.empty()) {
		int t = st.top();
		st.pop();
		if (flag)
			cout << " ";
		flag = true;
		cout << t;
	}
	cout << endl;
	cin >> N;
	return 0;
}