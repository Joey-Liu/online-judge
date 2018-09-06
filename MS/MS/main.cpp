#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;

	TreeNode(int v = 0) {
		val = v;
		left = NULL;
		right = NULL;
	}
};


vector<int> work(TreeNode* root) {
	vector<int> ans;
	queue<TreeNode *> que;
	if (!root)
		return ans;

	que.push(root);
	while (!que.empty()) {
		TreeNode * cur = que.front(); que.pop();
		ans.push_back(cur->val);
		if (cur->left)
			que.push(cur->left);
		if (cur->right)
			que.push(cur->right);
	}//while
	return ans;
}

TreeNode * work_input(vector<string> & vs, int & cur) {
	TreeNode *root = NULL;
	if (vs[cur] == "#")
		return root;

	root = new TreeNode(atoi(vs[cur].c_str()));
	TreeNode *left = work_input(vs, ++cur);
	TreeNode *right = work_input(vs, ++cur);
	root->left = left;
	root->right = right;
	return root;
}

class Solution {
public:
	int calculate(string s) {
		char sign = '+';
		int num = 0;
		stack<int> sta;

		for (int i = 0; i < s.size(); i++) {

			if (isdigit(s[i])) {
				num = num * 10 + s[i] - '0';
			}
			if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
				cout << s[i] << " ";
				if (sign == '-') {
					num = -num;
					sta.push(num);
				}
				else if (sign == '*') {
					int t = sta.top(); sta.pop();
					sta.push(t * num);
				}
				else if (sign == '/') {
					int t = sta.top(); sta.pop();
					sta.push(t / num);
				}
				else if (sign == '+') {
					sta.push(num);
				}
				num = 0;
				if (!isdigit(s[i]))
					sign = s[i];
			}
		}//for

		int ans = 0;
		while (!sta.empty()) {
			ans += sta.top();
			sta.pop();
		}
		return ans;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	Solution sol;
	string s = "3 + 20 * 5";
	int ans = sol.calculate(s);
	return 0;
}