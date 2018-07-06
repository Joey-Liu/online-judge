#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {
	
	}
};


class Solution {
private:
	TreeNode * decode(char *&str) {
		while (*str == ',')
			str++;
		0

		if (*str == '#') {
			str++;
			return NULL;
		}
		int num = 0;
		while (isdigit(*str))
			num = num * 10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = decode(str);
		root->right = decode(str);
		return root;
	}
public:
	char* Serialize(TreeNode *root) {
		if (!root) {
			char *s = new char[3];
			s[0] = '#'; s[1] = ','; s[2] = '\0';
			return s;
		}
		string r = to_string(root->val);
		r.push_back(',');
		char *left = Serialize(root->left);
		char *right = Serialize(root->right);
		char *ret = new char[strlen(left) + strlen(right) + r.size()];
		strcpy(ret, r.c_str());
		strcat(ret, left);
		strcat(ret, right);
		return ret;
	}
	TreeNode* Deserialize(char *str) {
		return decode(str);
	}
};

int main() {
	TreeNode *tn = new TreeNode(13);
	Solution sol;
	char * s = sol.Serialize(tn);
	TreeNode * root = sol.Deserialize(s);
	return 0;
}