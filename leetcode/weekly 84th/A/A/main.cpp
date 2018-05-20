#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		const int maxn = N;
		int layer[N], tab[maxn][maxn], dis[maxn][maxn];
		memset(dis, -1, sizeof(dis));

		for (int i = 0; i < edges.size(); i++) {
			int x = edges[i][0], y = edges[i][1];
			dis[x][y] = dis[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (dis[i][j] < 0 && dis[i][k] > 0 && dis[k][j] > 0) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
					else if (dis[i][k] > 0 && dis[k][j] > 0 && dis[i][k] + dis[k][j] < dis[i][j])
						dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}

		vector<int> res(N, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;
				res[i] += dis[i][j];
			}
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> A = { {0, 1}, {1, 1} };
	vector<vector<int>> B = { { 1, 1 },{ 1, 0 } };
	Solution s;
	int res =  s.largestOverlap(A, B);
	return 0;
}