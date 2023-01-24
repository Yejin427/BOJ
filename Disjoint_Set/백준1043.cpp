#include<iostream>
#include<vector>
using namespace std;
int parent[51];
int find(int x) {
	if (parent[x] == x) return x;
	return x = find(parent[x]);
}
void uni(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	parent[rootx] = rooty;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> real;
	vector<int> v[51];
	int n, m, r; cin >> n >> m;//n사람수 m파티수
	for (int i = 1; i <= n; i++) parent[i] = i;
	cin >> r;//진실 사람수
	while (r--) {
		int t; cin >> t;
		real.push_back(t);
	}
	for (int i = 0; i < m; i++) {
		int num, prev, party;
		cin >> party;
		for (int j = 0; j < party; j++) {
			if (j >= 1) {
				prev = num; cin >> num;
				uni(prev, num);//전에 입력한 숫자와 합침
			}
			else cin >> num;
			v[i].push_back(num);
		}
	}
	int ans = m;
	for (int i = 0; i < m; i++) {
		bool fact = false;
		for (int j = 0; j < v[i].size(); j++) {
			if (fact) break;
			for (int k = 0; k < real.size(); k++) {
				if (find(v[i][j]) == find(real[k])) {
					fact = true;
					break;
				}
			}
		}
		if (fact) ans--;
	}
	cout << ans;
	return 0;
}