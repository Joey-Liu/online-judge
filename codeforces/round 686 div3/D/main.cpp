#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
long long int N;

vector<long long> decompose() {
    long long int numbe = N;
    vector<long long int > vi;

    for (long long int  i = 2; i <= sqrt(N); i++) {
        int ind = 0;
        while ((numbe % i) == 0) {
            if (ind >= vi.size()) {
                vi.emplace_back(i);
            } else {
                vi[ind] *= i;
            }
            ind += 1;
            numbe /= i;
        }
    }//for int i

    if (numbe != 1) {
        if (vi.size() == 0) {
            vi.emplace_back(numbe);
        } else {
            vi[0] *= numbe;
        }
    }

    return vi;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        vector<long long int> vi = decompose();
        cout << vi.size() << endl;
        reverse(vi.begin(), vi.end());
        for (int i = 0; i < vi.size(); i++) {
            cout << vi[i] << " ";
        }
        cout << endl;
    }

    return 0;
}