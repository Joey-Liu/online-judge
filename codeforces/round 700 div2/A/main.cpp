#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        string str;
        cin >> str;
        int N = str.size(), ind = 0;
        while (ind < N) {
            if (ind % 2 == 0) {
                if(str[ind] != 'a') {
                    str[ind] = 'a';
                } else {
                    str[ind] = 'b';
                }
            } else {
                if (str[ind] != 'z') {
                    str[ind] = 'z';
                } else {
                    str[ind] = 'y';
                }
            }
            ind += 1;
        }// while
        cout << str << endl;
    }
    return 0;
}