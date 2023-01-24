#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int arr[1000001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		if (v.back() < arr[i]) v.push_back(arr[i]);
		else {
			v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
		}
	}
	cout << v.size();
}