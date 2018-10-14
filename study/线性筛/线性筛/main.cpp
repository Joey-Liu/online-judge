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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;
typedef long long LL;

const LL maxn = 2e+8;
int prime[maxn] = { 0 };//基于0
LL num_prime = 0;
bool isNotPrime[maxn] = { 1,1 };//除了0,1外其余都是素数

int main()
{
	freopen("out2.txt", "w", stdout);
	for (LL i = 2; i < maxn; i++)//依次枚举各个数字
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;

		//进行线性筛除
		for (LL j = 0; j < num_prime && i * prime[j] < maxn; j++)
		{
			isNotPrime[i * prime[j]] = 1;//把小于 i 的素数 和 i 的乘积置为合数这里可以分为两种情况 1.i是素数  2.i不是素数
			if (!(i % prime[j]))//只筛除不大于 其最小质因数 与 i 的乘积
				break;
		}
	}
	for (LL i = 0; i < num_prime; i++)
	{
		if (0 == i % 50)
			cout << endl;
		cout << prime[i] << " ";
	}
	return 0;
}

