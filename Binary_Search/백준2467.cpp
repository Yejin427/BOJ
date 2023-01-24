//2467
#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int left = 0, right = n - 1;
	int l = arr[0]; int r = arr[n - 1];
	int res = abs(l + r);
	while (left < right) {
		int val = arr[left] + arr[right];
		if (abs(val) < res) {
			res = abs(val);
			l = arr[left];
			r = arr[right];
		}
		if (val < 0) left++;
		else right--;
	}
	cout << l << " " << r;
}