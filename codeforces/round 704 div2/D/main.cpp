#include <iostream>

using namespace std;
const int maxn = 5e5 + 300;

int A, B, K;
int X[maxn] = { 0 };
int Y[maxn] = { 0 };

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> A >> B >> K;
    int N = A + B;

    X[0] = 1; Y[0] = 1;
    B -= 1;
    int nxt = N - 1;
    if (K > 0) {
        int ind = N - 1;
        Y[ind] = 1;
        nxt = ind - K;
        if (nxt <= 0) {
            cout << "No" << endl;
            return 0;
        }

        X[nxt] = 1;
        B -= 1;
        nxt -= 1;
    }

    if (nxt < B || B < 0) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = nxt ; i > 0; i--) {
        if (B <= 0) {
            break;
        }
        X[i] = 1;
        Y[i] = 1;
        B -= 1;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        cout << X[i];
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << Y[i];
    }

    return 0;
}