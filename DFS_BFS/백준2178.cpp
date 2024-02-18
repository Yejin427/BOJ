#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> p;
queue<p> q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int map[101][101], m, n, ans, time[101][101];
bool visited[101][101];
bool go(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || map[x][y] == 0)return false;
	else return true;
}
void bfs(int x, int y) {//(x,y)가 시작점
	visited[x][y] = true;
	time[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (go(nowx + dx[i], nowy + dy[i])) {
				q.push(make_pair(nowx + dx[i], nowy + dy[i]));
				time[nowx + dx[i]][nowy + dy[i]] = time[nowx][nowy] + 1;
				visited[nowx + dx[i]][nowy + dy[i]] = true;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	bfs(0, 0);
	printf("%d", time[m-1][n-1]);
}