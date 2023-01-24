#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
char word[1002][52];
int num[1002];
bool compare(string& a, string& b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		int a_sum = 0, b_sum = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9') a_sum += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') b_sum += b[i] - '0';
		}
		if (a_sum != b_sum) return a_sum < b_sum;
		else {
			return a < b;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) cout << v[i] << "\n";
}