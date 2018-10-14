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
int prime[maxn] = { 0 };//����0
LL num_prime = 0;
bool isNotPrime[maxn] = { 1,1 };//����0,1�����඼������

int main()
{
	freopen("out2.txt", "w", stdout);
	for (LL i = 2; i < maxn; i++)//����ö�ٸ�������
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;

		//��������ɸ��
		for (LL j = 0; j < num_prime && i * prime[j] < maxn; j++)
		{
			isNotPrime[i * prime[j]] = 1;//��С�� i ������ �� i �ĳ˻���Ϊ����������Է�Ϊ������� 1.i������  2.i��������
			if (!(i % prime[j]))//ֻɸ�������� ����С������ �� i �ĳ˻�
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

