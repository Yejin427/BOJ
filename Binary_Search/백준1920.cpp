#include<iostream>
#include<algorithm>
using namespace std;
int a[100002], m, n;
void search(int k) {
	int min, max, mid;
	if (k > a[n - 1] || k < a[0]) {
		cout << "0" << "\n";
		return;
	}
	else {
		min = 0; max = n - 1;
		while (min <= max) {
			mid = (min + max) / 2;
			if (a[mid] > k) {
				max = mid - 1;
			}
			else if (a[mid] < k) {
				min = mid + 1;
			}
			else {
				cout << "1" << "\n";
				return;
			}
		}
		cout << "0" << "\n";
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a[i] = k;
	}
	sort(a,a+n);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> k;
		search(k);
	}
}