#include<iostream>
#include<algorithm>
using namespace std;
int area[10002], n, ans;
long long int f(int x) {
	long long int y = 0;
	for (int i = 0; i < n; i++) {
		y += min(x, area[i]);
	}
	return y;
}
int main() {
	long long int m;
	int maxbudget = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> area[i];
		maxbudget = max(maxbudget, area[i]);
	}
	cin >> m;
	int l = 1, r = maxbudget;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (f(mid) <= m) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}