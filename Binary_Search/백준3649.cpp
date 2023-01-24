#include<iostream>
#include<algorithm>
#define NANO 10000000
using namespace std;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, n;
	while (cin >> x) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int real = x * NANO;
		bool exist = false;
		int ans1, ans2;
		for (int i = 0; i < n; i++) {
			int half = real - arr[i];
			int left = i + 1, right = n - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (arr[mid] > half) {
					right = mid - 1;
				}
				else if (arr[mid] == half) {//막을 2개 존재함
					exist = true;
					ans1 = arr[i]; ans2 = arr[mid];
					break;
				}
				else {
					left = mid + 1;
				}
			}
			if (exist) break;
		}
		if (exist) cout << "yes " << ans1 << " " << ans2 << "\n";
		else cout << "danger" << "\n";
	}
}