#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> K;
        vector<int> A(N, 0);
        for (int i = 0 ; i < N; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < N; i++) {
            int cur = min(K, A[i]);
            A[i] -= cur;
            A[N - 1] += cur;

            K -= cur;
        }

        for (int i = 0; i < N; i++) {
            cout << A[i] << " ";
        }
        cout << endl;

    }// while
    return 0;
}