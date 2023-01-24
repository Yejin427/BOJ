#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> v[130000];
int arr[130000];
bool sheep[130000];
long long int dp[130000];
bool visited[130000];
long long int dfs(int root) {
	visited[root] = true;
	if (v[root].size() == 1 && root != 1) {//leaf
		if (sheep[root]) return dp[root] = arr[root];
		else return dp[root] = 0;
	}
	if (dp[root] != -1) return dp[root];
	dp[root] = 0;
	for (int i = 0; i < v[root].size(); i++) {
		if (!visited[v[root][i]]) {
			dp[root] += dfs(v[root][i]);//leaf의 생존양들을 모두 더함
		}
	}
	if (sheep[root]) {
		dp[root] += arr[root];
	}
	else dp[root] = max(dp[root] - arr[root], 0LL);
	return dp[root];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		char c; int g;
		cin >> c >> arr[i] >> g;
		v[i].push_back(g);
		v[g].push_back(i);
		if (c == 'S') sheep[i] = true;
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(1) << '\n';
}