#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

const int maxn = 510;

struct Mission {
	int ed;
	int day;
	int hour, minu;
	double second;
	double ti;
};

struct Route {
	int st, ed;
	double st_ti, ed_ti;
	int s_hour, s_minu, e_hour, e_minu;
	double s_second, e_second;
	int price;
};


bool m_cmp(Mission m1, Mission m2) {
	double d1 = m1.day * 24 * 3600.0 + m1.hour * 3600.0 + m1.minu * 60.0 + m1.second;
	double d2 = m2.day * 24 * 3600.0 + m2.hour * 3600.0 + m2.minu * 60.0 + m2.second;
	return d1 < d2;
}


int N, M, K;
Mission miss[20];
Route route[maxn];
vector<vector<int>> ron(maxn);


int work(int day, double cur, int pos, int ind, bool visited[], bool & flag) {
	if (day > miss[ind].day || (day == miss[ind].day && cur >= miss[ind].ti)) {
		flag = false;
		return -1;
	}
	if (pos == miss[ind].ed) {
		flag = true;
		return 0;
	}
	//bool visited[maxn];
	
	int tmp = 0, ans = INT_MAX;
	
	for (int i = 0; i < ron[pos].size(); i++) {
		int x = ron[pos][i];
		int des = route[x].ed;
		if (visited[des]) {
			continue;
		}
		
		if (cur > route[x].st_ti)
			continue;

		visited[des] = true;
		int cost = route[x].price;
		bool is_ok = false;
		tmp = work(day, route[x].ed_ti, des, ind, visited, is_ok);
		visited[des] = false;
		
		if (is_ok) {
			flag = true;
			ans = min(ans, tmp + cost);
		}
	}

	int day_2 = day + 1;
	double cur_2 = 0.0;
	bool is_ok = false;
	int tmp_2 = work(day_2, cur_2, pos, ind, visited, is_ok);
	if (is_ok) {
		flag = true;
		ans = min(ans, tmp_2);
	}

	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> miss[i].ed;
		double tmp;
		char c;
		cin >> tmp >> c;
		cin >> miss[i].day;
		cin >> miss[i].hour >> c >> miss[i].minu >> c >> miss[i].second;
		miss[i].ti = miss[i].hour * 3600.0 + miss[i].minu * 60.0 + miss[i].second;
	}

	sort(miss, miss + N, m_cmp);
	for (int i = 0; i < M; i++) {
		cin >> route[i].st >> route[i].ed;
		cin >> route[i].price;
		char c;
		cin >> route[i].s_hour >> c >> route[i].s_minu >> c >> route[i].s_second;
		cin >> route[i].e_hour >> c >> route[i].e_minu >> c >> route[i].e_second;
		route[i].st_ti = 3600.0 * route[i].s_hour + 60.0 * route[i].s_minu + route[i].s_second;
		route[i].ed_ti = 3600.0 * route[i].e_hour + 60.0 * route[i].e_minu + route[i].e_second;
		ron[route[i].st].push_back(i);
	}

	double cur = 23 * 3600.0 + 59 * 60.0 + 59.999;
	int day = 0;
	int pos = 1, ans = 0;
	bool flag;

	for (int i = 0; i < N; i++) {
		flag = false;
		bool visited[maxn];
		memset(visited, false, sizeof(visited));
		visited[pos] = true;

		int cost = work(day, cur, pos, i, visited, flag);
		if (!flag)
			break;
		ans += cost;
		day = miss[i].day;
		cur = miss[i].ti;
		pos = miss[i].ed;
	}
	if (flag)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}