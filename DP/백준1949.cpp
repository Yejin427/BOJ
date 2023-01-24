#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[10001];
long long dp[10001][2];
bool visited[10001];
vector<int> v[10001];
long long treedp(int root, int usu) {
	if (v[root].size() == 1) {//leaf
		if (usu) return arr[root];
		else return 0;
	}
	if (dp[root][usu] > 0) return dp[root][usu];

	if (usu) {
		for (auto& it : v[root]) {
			if (!visited[it]) {
				visited[it] = true;
				dp[root][1] += treedp(it, 0);
			}
		}
	}
	else {
		for (auto& it : v[root]) {
			if (!visited[it]) {

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cout << max(treedp(1, 0), treedp(1, 1));
}