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


int gcd(int a, int b) {
	
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;

}

int main()
{
	int a, b;
	while (cin >> a >> b) {
		int c = gcd(a, b);
		cout << c << endl;
	}
	return 0;
}