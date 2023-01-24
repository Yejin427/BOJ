#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001];
int main() {
	int n; cin >> n;
	int minus = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] < 0) minus++;
	}
	sort(arr + 1, arr + n + 1);
	int ans = 0;
	int k = n;
	while (arr[k-1] > 1 && k>=1) {
		ans += arr[k] * arr[k - 1];
		k -= 2;
	}
	while (arr[k] > 0 && k>=1) {
		ans += arr[k];
		k--;
	}
	if (arr[1] < 0) {
		if (minus % 2 == 0) {//음수 짝수개
			for (int i = 1; arr[i + 1] < 0; i += 2) {
				ans += arr[i] * arr[i + 1];
			}
		}
		else {//음수 홀수개
			int i = 1;
			while (arr[i + 2] < 0) {
				ans += arr[i] * arr[i + 1];
				i += 2;
			}
			if (arr[i + 1] != 0 || i + 1 > n) ans += arr[i];//0이 없을때
		}
	}
	cout << ans;
}