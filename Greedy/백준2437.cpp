#include<iostream>
#include<algorithm>
using namespace std;
int arr[1002];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 2 <= arr[i]) break;
		sum += arr[i];
	}
	cout << sum + 1;
}