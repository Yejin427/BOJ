#include<iostream>
using namespace std;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	int left = -1, right = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right += arr[i];
	}
	right++;
	while (left+1 < right) {
		int cnt = 0;
		int sum = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (sum >= mid) {
				sum = 0;
				cnt++;
			}
		}
		if (cnt >= k) left = mid;
		if (cnt < k) right = mid;
	}
	cout << left;
}