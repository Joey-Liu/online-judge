#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int N;
    vector<int> give, rec, res;
    set<int> si;


    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        if (!tmp) {
            give.emplace_back(i);
        } else {
            si.insert(tmp);
        }
        res.emplace_back(tmp);
    }

    for (int i = 1; i <= N; i++) {
        if (!si.count(i)) {
            rec.emplace_back(i);
        }
    }

    int length = give.size();
    for (int i = 0; i + 1 < length; i++) {
        if (rec[i] == give[i]) {
            swap(rec[i], rec[i + 1]);
        }
    }
    if (rec[length - 1] == give[length - 1]) {
        swap(rec[length - 1], rec[length - 2]);
    }

    for (int i = 0; i < length; i++) {
        res[give[i] - 1] = rec[i];
    }
    cout << res[0];
    for (int i = 1; i < res.size(); i++) {
        cout << " " << res[i];
    }
    cout << endl;

    return 0;
}