#include <iostream>
#include <memory.h>

using namespace std;

int a, b, c, d;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> a >> b >> c >> d;
	int dis = a - c;
	if (dis < 0)
		dis = -dis;

	if (dis <= d)
		cout << "Yes" << endl;
	else {
		int x = a - b;
		if(x < 0)
			x = -x;
		int  y = b - c;
		if (y < 0)
			y = -y;

		if (x <= d && y <= d)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	return 0;
}