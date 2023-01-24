//1561
#include<iostream>
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; 
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> arr[i];
	long long left = 0, right = 6e10;
	long long total = 0;
	if (n <= m) {
		cout << n;
		return 0;
	}
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long p = m;
		for (int i = 1; i <= m; i++) {
			p += mid / arr[i];
		}
		if (p >= n) {
			total = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	long long p = m;
	for (int i = 1; i <= m; i++) {
		p += ((total - 1) / arr[i]);
	}
	for (int i = 1; i <= m; i++) {
		if (total % arr[i] == 0) p++;
		if (p == n) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}