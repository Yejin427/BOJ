#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[40001];
vector<int> v;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (v.back() < arr[i]) v.push_back(arr[i]);
		if (v.back() > arr[i]) {
			v[lower_bound(v.begin(), v.end(), arr[i])-v.begin()] = arr[i];
		}
	}
	cout << v.size();
}