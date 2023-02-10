#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[32001];
int arr[32001];
int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) pq.push(i);
	}
	while (!pq.empty()) {
		int x = pq.top();
		cout << x << " ";
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (arr[v[x][i]] == 1) pq.push(v[x][i]);
			arr[v[x][i]]--;
		}
	}
}