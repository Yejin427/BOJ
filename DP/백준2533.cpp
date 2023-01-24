#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1000001][2];
bool visited[1000001];
vector<int> v[1000001];
void f(int root) {
	visited[root] = true;
	dp[root][1] = 1;
	for (int i = 0; i < v[root].size(); i++) {
		if (visited[v[root][i]]) continue;
		f(v[root][i]);
		dp[root][0] += dp[v[root][i]][1];
		dp[root][1] += min(dp[v[root][i]][1], dp[v[root][i]][0]);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	f(1);
	cout << min(dp[1][0], dp[1][1]);
}