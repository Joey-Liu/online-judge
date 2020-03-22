#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    bool done;
    Node *nxt[26];
    string str;
    Node () {
        done = false;
        for (int i = 0; i < 26; i++) {
            nxt[i] = nullptr;
        }
        str = "";
    }
};



void init(Node * root, string str) {
    Node * cur = root;
    for (int i = 0; i < str.size(); i++) {
        int ind = str[i] - 'a';
        if (cur->nxt[ind] == nullptr) {
            cur->nxt[ind] = new Node();
        }
        cur = cur->nxt[ind];
    }
    cur->done = true;
}

string work(Node * root, string str) {
    Node * cur = root;
    for (int i = str.size() - 1; i >= 0; i--) {
        int ind = str[i] - 'a';
        if (cur->nxt[ind] == nullptr) {
            return "";
        }
        cur = cur->nxt[ind];
        if (cur->done == true) {
            return str.substr(i);
        }
    }
    return "";
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int kasenum = 0;
    cin >> kasenum;
    string str;
    map<string, string> tab;
    tab.emplace( "po", "FILIPINO");
    tab.emplace( "desu", "JAPANESE");
    tab.emplace( "masu", "JAPANESE");
    tab.emplace( "mnida", "KOREAN");

    Node * root = new Node();
    init(root, "op");
    init(root, "used");
    init(root, "usam");
    init(root, "adinm");

    for (int i = 0; i < kasenum; i++) {
        cin >> str;
        string suffix = work(root, str);
        cout << tab[suffix] << endl;
    }


    return 0;
}