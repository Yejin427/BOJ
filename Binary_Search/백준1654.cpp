#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001], n;
long long int num_lan(long long int h) {
	long long int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (arr[i] / h);
	}
	return ans;
}
long long int ans(int k) {
	long long int dab;
	long long int min = 1; long long int max = arr[n];
	while (min <= max) {
		long long int mid = (min + max) / 2;
		if (k <= num_lan(mid)) {
			min = mid + 1;
			dab = mid;
		}
		else {
			max = mid - 1;
		}
	}
	return dab;
}
int main() {
	int k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	cout << ans(k);
}