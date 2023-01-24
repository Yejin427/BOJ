#include<iostream>
#include<algorithm>
using namespace std;
int arr[5001];
int main() {
	int n, m; cin >> n >> m;
	int left = 0, right, min = 10001, max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}
	right = max - min;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		//cout << "left : " << left << "right : " << right << "\n";
		//cout << "mid : " << mid << '\n';
		min = 10001, max = 0;
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (max < arr[i]) max = arr[i];
			if (min > arr[i]) min = arr[i];
			
			if (max - min > mid) {
				cnt++;
				min = arr[i];
				max = arr[i];
			}
		}
		//cout << "cnt : " << cnt << '\n';
		if (m >= cnt) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
}