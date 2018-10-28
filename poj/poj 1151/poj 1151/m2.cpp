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
#include <math.h>
#include <functional>
#include <limits.h>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 222;
const double eps = 1e-6;

struct Line {
	double x, y1, y2;
	int flag;
};

Line lines[maxn];
bool cmp(Line l1, Line l2) {
	if(l1.x !=l2.x)
		return l1.x < l2.x;
	return l1.flag > l2.flag;
}
int l_cnt = 1;

struct TreeNode{
	int lp, rp, cnt;
	double len;

	TreeNode(){
		lp = rp = cnt = 0;
		len = 0;
	}
};
TreeNode seg_tree[maxn << 2];

void add_line(double x, double y1, double y2, int flag) {
	lines[l_cnt].x = x;
	lines[l_cnt].y1 = y1;
	lines[l_cnt].y2 = y2;
	lines[l_cnt].flag = flag;
	l_cnt++;
}

int y_cnt = 1;
double yy[maxn << 2];


void build_tree(int t, int lp, int rp) {
	seg_tree[t].lp = lp;
	seg_tree[t].rp = rp;
	seg_tree[t].cnt = 0;
	seg_tree[t].len = 0.0;
	if (lp + 1 >= rp)
		return;
	int mid = (lp + rp) >> 1;
	build_tree(t << 1, lp, mid);
	build_tree((t << 1) | 1, mid, rp);
}

void update_len(int root) {
	if (seg_tree[root].cnt) {
		seg_tree[root].len = yy[seg_tree[root].rp] - yy[seg_tree[root].lp];
	}
	else if (seg_tree[root].lp + 1 == seg_tree[root].rp) {
		seg_tree[root].len = 0;
	}
	else {
		seg_tree[root].len = seg_tree[root << 1].len + seg_tree[(root << 1) | 1].len;
	}
}

/*这个实现目前先不使用延迟标记*/
void update_cnt(int root, int q_lp, int q_rp, int val) {
	if (seg_tree[root].lp > q_rp || seg_tree[root].rp < q_lp) 
		return;
	if (q_lp <= seg_tree[root].lp && seg_tree[root].rp <= q_rp) {
		seg_tree[root].cnt += val;
		update_len(root);
	}

	if (seg_tree[root].lp + 1 >= seg_tree[root].rp)
		return;

	update_cnt(root << 1, q_lp, q_rp, val);
	update_cnt((root << 1) | 1, q_lp, q_rp, val);
	update_len(root);

	/*
	if (seg_tree[root].lp + 1 >= seg_tree[root].rp) {
		update_len(root);
	} else {
		//int mid = (seg_tree[root].lp + seg_tree[root].rp) >> 1;
		update_cnt(root << 1, q_lp, q_rp, val);
		update_cnt((root << 1) | 1, q_lp, q_rp, val);
		update_len(root);
	}
	*/
}

bool double_less(double a, double b) {
	return (a - b) < eps;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, kasenum = 0;;
	while (cin >> N && N) {
		double a, b, c, d;
		y_cnt = 1;
		l_cnt = 1;
		for (int i = 0; i < N; i++) {
			cin >> a >> b >> c >> d;
			add_line(a, b, d, 1);
			yy[y_cnt++] = b;
			add_line(c, b, d, -1);
			yy[y_cnt++] = d;
		}
		map<int, int> tab;
		sort(yy + 1, yy + y_cnt);
		y_cnt = unique(yy + 1, yy + y_cnt) - (yy + 1);
		sort(lines + 1, lines + l_cnt, cmp);

		double res = 0;
		build_tree(1, 1, y_cnt);
		for (int i = 1; i < l_cnt; i++) {
			int q_lp = lower_bound(yy + 1, yy + y_cnt + 1, lines[i].y1) - (yy + 1);
			int q_rp = lower_bound(yy + 1, yy + y_cnt + 1, lines[i].y2) - (yy + 1);

			if (i != 1) {
				res += seg_tree[1].len * (lines[i].x - lines[i - 1].x);
			}
			update_cnt(1, q_lp + 1, q_rp + 1, lines[i].flag);
		}

		cout << "Test case #" << ++kasenum << endl;
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout <<"Total explored area: "<< res << endl<<endl;
	}//while

	return 0;
}