#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int arr[100002];
vector<int> v;
int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		v.push_back(arr[0]);
		for (int i = 1; i < n; i++) {
			if (v.back() < arr[i]) v.push_back(arr[i]);
			else {
				v[lower_bound(v.begin(),v.end(), arr[i]) - v.begin()] = arr[i];
			}
		}
		cout << v.size() << "\n";
		v.clear();
	}
}