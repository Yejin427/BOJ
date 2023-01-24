#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n, r, c;
int arr[501][501];
typedef pair<int, int> p;
vector<p> v;
int solve(int s, int e) {
	if (s == e) return 0;
	if (arr[s][e] != -1) return arr[s][e];
	if (e == s + 1) {
		arr[s][e] = v[s].first * v[s].second * v[e].second;
		return arr[s][e];
	}
	for (int i = s; i < e; i++) {
		int cur = solve(s, i) + solve(i + 1, e) + (v[s].first * v[i].second * v[e].second);
		if (arr[s][e] != -1) {
			arr[s][e] = min(arr[s][e], cur);
		}
		else arr[s][e] = cur;
	}
	return arr[s][e];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r >> c;
		v.push_back({ r,c });
	}
	memset(arr, -1, sizeof(arr));
	cout << solve(0, n - 1);
}