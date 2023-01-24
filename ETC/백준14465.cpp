#include<iostream>
using namespace std;
int sum[100001];
bool broke[100001];
int main() {
	int n, k, b; cin >> n >> k >> b;
	while (b--) {
		int l; cin >> l;
		broke[l] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (broke[i]) sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1];
	}
	int min = k + 1;
	for (int i = k; i <= n; i++) {
		if (min > sum[i] - sum[i - k]) {
			min = sum[i] - sum[i - k];
		}
	}
	cout << min;
}