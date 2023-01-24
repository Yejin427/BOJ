#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int map[1001][1001], n, m, visited[1001][1001][2], change;
int dx[] = { 0,-1,0,1 }, dy[] = { 1,0,-1,0 };
inline bool isok(int column, int row, int flag) {
	if (column<1 || row<1 || column>n || row>m ) {
		return false;
	}
	if (flag==0 && map[column][row]) {
		change = 1;
		return true;
	}
	if (!map[column][row]&&visited[column][row][flag]==0) return true;
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	typedef pair<pair<int, int>, int> p;
	queue<p> q;
	visited[1][1][0] = 1;
	q.push(make_pair(make_pair(1, 1), 0));
	while (!q.empty()) {
		int front_c = q.front().first.first;
		int front_r = q.front().first.second;
		int front_f = q.front().second;
		q.pop();
		if (front_c == n && front_r == m) {
			cout << visited[n][m][front_f];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			if (isok(front_c + dx[i], front_r + dy[i], front_f)) {//front_f isok함수에서 바뀌면
				if (change) {
					visited[front_c + dx[i]][front_r + dy[i]][front_f+1] = visited[front_c][front_r][front_f] + 1;
					change = 0;
					q.push(make_pair(make_pair(front_c + dx[i], front_r + dy[i]), front_f+1));
				}
				else {
					visited[front_c + dx[i]][front_r + dy[i]][front_f] = visited[front_c][front_r][front_f] + 1;
					q.push(make_pair(make_pair(front_c + dx[i], front_r + dy[i]), front_f));
				}
			}
		}
	}
	cout << "-1";
}