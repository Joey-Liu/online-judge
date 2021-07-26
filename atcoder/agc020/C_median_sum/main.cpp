#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;
const int maxn = 2000;
int N;
int nums[maxn], sum = 0;


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    bitset<maxn * maxn + 20> bs;
    bs[0] = 1;
    for (int i = 0; i < N; i++) {
        bs |= (bs << nums[i]);
    }

    for (int i = (sum + 1) / 2; i <= sum; i++) {
        if (bs[i]) {
            cout << i << endl;
            break;
        }
    }


    return 0;
}