#include<iostream>
using namespace std;
bool visited[35][35];
int direction[4], N, moving[15], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
double ans, cnt = 1;
void backtracking(int depth,int nowx,int nowy) {
	if (depth == N) {
		for (int i = 0; i < N; i++) {
			cnt *= (double)moving[i]/100;
		}
		ans += cnt; 
		cnt = 1;
		return;
	}
	visited[nowx][nowy] = true;
	for (int i = 0; i < 4; i++) {
		if (!visited[nowx + dx[i]][nowy + dy[i]]) {
			moving[depth] = direction[i];//È®·ü°ª
			visited[nowx + dx[i]][nowy + dy[i]] = true;
		}
		else continue;
		backtracking(depth + 1,nowx+dx[i],nowy+dy[i]);
		visited[nowx + dx[i]][nowy + dy[i]] = false;
	}
}
int main() {
	cin >> N;
	cin >> direction[0] >> direction[1] >> direction[2] >> direction[3];//µ¿0¼­1³²2ºÏ3
	backtracking(0,18,18);
	cout << fixed;
	cout.precision(10);
	cout << ans;
}