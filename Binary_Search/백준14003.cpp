#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int arr[1000001];
int dp[1000001];
vector<int> v;
stack<int> s;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[1]);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			dp[i] = v.size();
		}
		else {
			v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
			dp[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
		}
	}
	cout << v.size() << '\n';
	int idx;
	for (idx = 1; idx <= n; idx++) {
		if (dp[idx] == v.size()) break;
	}
	s.push(arr[idx]);
	int curidx = idx;
	for (int i = idx - 1; i >= 1; i--) {
		if (arr[i] < arr[curidx] && dp[i] == dp[curidx] - 1) {
			curidx = i;
			s.push(arr[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}