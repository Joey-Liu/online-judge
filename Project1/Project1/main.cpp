#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x = -13) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		ListNode *ans = NULL, *prev = NULL, *cur = head;
		int state = 0;
		bool flag = false;
		while (cur) {
			ListNode *t = cur->next;
			if (t != NULL && t->val != cur->val) {
				if (!flag) {
					ans = cur;
					flag = true;
				}
				else {
					prev->next = cur;
				}
				prev = cur;
				prev->next = NULL;
				cur = t;
			}
			else if (t == NULL) {
				if (!flag) {
					ans = cur;
					flag = true;
					prev = cur;
				} else {
					prev->next = cur;
					prev = cur;
				}
				cur = t;
			}
			else {
				cout << "TFW" << endl;
				ListNode *u = t->next;
				while (u && u->val == t->val) {
					t = u;
					u = u->next;
				}
				cur = u;
				//cout << cur->val << endl;
			}
		}//while
		return ans;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N;
	cin >> N;
	ListNode *head = new ListNode();
	ListNode *prev = NULL;
	for (int i = 0; i < N; i++) {
		int v;
		cin >> v;
		if (!i) {
			head->val = v;
			prev = head;
		}
		else {
			ListNode *tmp = new ListNode();
			tmp->val = v;
			prev->next = tmp;
			prev = tmp;
		}
	}

	Solution sol;
	ListNode *ans = sol.deleteDuplicates(head);
}