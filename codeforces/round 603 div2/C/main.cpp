#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int casenum;
    cin >> casenum;
    while (casenum--) {
        int N;
        cin >> N;
        set<int> res;
        res.insert(0);
        res.insert(1);
        res.insert(N);

        for (int i = 2; i <= sqrt(N); i++) {
            int b = N / i;
            res.insert(i);
            res.insert(b);
        }
        cout << res.size() << endl;
        for (set<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}