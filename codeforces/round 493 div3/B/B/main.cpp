#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int a, b, x;
	cin >> a >> b >> x;
	bool rever = false;
	if (a < b) {
		rever = true;
		swap(a, b);
	}
	string ans = "0";
	
	bool flag = true;
	for (int i = 0; i < x; i++) {
		if (flag)
			ans += "1";
		else
			ans += "0";
		flag = !flag;
	}
	int cnt_0 = 0;
	for (int i = 0; i < ans.size(); i++)
		if (ans[i] == '0')
			cnt_0++;
	
	if(a - cnt_0 > 0)
		ans.insert(0, a - cnt_0, '0');

	int cnt_1 = 0, ind = -1;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == '1') {
			cnt_1++;
			ind = i;
		}
	}

	if(b - cnt_1 > 0)
		ans.insert(ind, b - cnt_1, '1');
	if (rever) {
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == '1')
				ans[i] = '0';
			else
				ans[i] = '1';
		}
	}
	cout << ans << endl;


	return 0;
}