#include<iostream>
using namespace std;
int arr[500001], n_arr[500001];
long long change;
void merge(int start, int mid, int end) {
	int pos1 = start;
	int pos2 = mid + 1;
	int idx = start;
	while (pos1 <= mid && pos2 <= end) {
		if (arr[pos1] <= arr[pos2]) {
			n_arr[idx++] = arr[pos1++];
		}
		else {
			n_arr[idx++] = arr[pos2++];
			change += (mid + 1 - pos1);
		}
	}
	if (pos1 > mid) {
		for (int i = pos2; i <= end; i++) {
			n_arr[idx++] = arr[i];
		}
	}
	else {
		for (int i = pos1; i <= mid; i++) {
			n_arr[idx++] = arr[i];
		}
	}
	for (int i = start; i <= end; i++) {
		arr[i] = n_arr[i];
	}
}
void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	merge_sort(1, n);
	cout << change;
}