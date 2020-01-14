#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<char, int> PCI;

void work(string s1, string s2, vector<int> & vi) {
    for (int i = 0 ; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            vi.emplace_back(i);
        }
    }
}


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    string s1, s2;
    vector<PCI > vp;

    cin >> kasenum;
    while(kasenum--) {
        cin >> s1 >> s2;
        vp.clear();
        vp.resize(s1.size());


        vp.back().first = 'Z';
        vp.back().second = -1;

        for (int i = s1.size() - 2; i >= 0; i--) {
            if (s1[i + 1] < vp[i + 1].first) {
                vp[i].first = s1[i + 1];
                vp[i].second = i + 1;
            } else {
                vp[i] = vp[i + 1];
            }
        }

        bool flag = false;
        int i = 0;
        for (i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] < s2[i]) {
                flag = true;
                break;
            }
            if (vp[i].first < s2[i]) {
                flag = true;
                swap(s1[i], s1[vp[i].second]);
                break;
            }
            if (s1[i] > s2[i]) {
                break;
            }
        }
        if (i == min(s1.size(), s2.size()) && s1.size() < s2.size()) {
            flag = true;
        }

        if (flag == true) {
            cout << s1 << endl;
        } else if (s1.size () < s2.size()){
            vector<int> vi;
            work(s1, s2, vi);
            if (vi.size() == 2) {
                swap(s1[vi[0]], s1[vi[1]]);
                if (s1 == s2.substr(0, s1.size())) {
                    cout << s1 << endl;
                } else {
                    cout << "---" <<endl;
                }
            } else {
                cout << "---" << endl;
            }
        } else {
            cout << "---" << endl;
        }
    }
    return 0;
}