#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int tomato[110][110][110], time=-1, m, n, h;
bool visited[110][110][110];
int dx[6] = { -1,1,0,0,0,0 }, dy[6] = { 0,0,-1,1,0,0 }, dz[6] = { 0,0,0,0,-1,1 };
queue<pair<pair<int,int>,int>> q;
int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[k][j][i];
				if (tomato[k][j][i] == 1) {
					q.push(make_pair(make_pair(k, j), i));
					visited[k][j][i] = true;
				}
				else if (tomato[k][j][i] == -1) {
					visited[k][j][i] = true;
				}
			}
		}
	}
	while (!q.empty()) {
		int size = q.size();
		++time;
		while (size--) {
			pair<pair<int, int>, int> now = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int ax, ay, az;
				ax = now.first.first + dx[i];
				ay = now.first.second + dy[i];
				az = now.second + dz[i];
				if (ax < 0 || ax >= m || ay < 0 || ay >= n || az < 0 || az >= h) continue;
				if (!visited[ax][ay][az] && tomato[ax][ay][az] == 0) {
					visited[ax][ay][az] = true;
					q.push(make_pair(make_pair(ax, ay), az));
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!visited[k][j][i]) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	cout << time;
	return 0;
}