#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int casenum, N;
    cin >> casenum;
    while(casenum--) {
        cin >> N;
        vector<string> vs;
        map<string, int> str_cnt;
        map<string, int> str_ind;
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            vs.push_back(str);
            str_cnt[str] += 1;
            str_ind[str] = 0;
        }

        vector<string> res;
        int res_num = 0;
        for (int i = 0; i < N; i++) {
            string str = vs[i];
            int ind = str_ind[str];
            while (true) {
                if (ind == 0) {
                    str_ind[str] += 1;
                    res.push_back(str);
                    break;
                }
                int t = str[0] - '0';
                t = (t + ind) % 10;
                str[0] = '0' + t;
                if (!str_cnt.count(str)) {
                    res_num += 1;
                    res.push_back(str);
                    str_ind[vs[i]] = ind + 1;
                    str_cnt[str] += 1;
                    break;
                }
                str[0] -= t;
                ind = (ind + 1) % 10;
            }
        }
        cout << res_num << endl;
        for (auto it = res.begin(); it != res.end(); it++) {
            cout << *it << endl;
        }

    }
    return 0;
}