#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int pred[1001];
void print(int n) {
	if (pred[n] == n) {
		cout << arr[n] << " ";
	}
	else {
		print(pred[n]);
		cout << arr[n] << " ";
	}
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		pred[i] = i;
	}
	int max = 0;
	int h = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pred[i] = j;
					if (max < dp[i]) {
						max = dp[i];
						h = i;
					}
				}
			}
		}
	}
	cout << dp[h] << '\n';
	print(h);
}