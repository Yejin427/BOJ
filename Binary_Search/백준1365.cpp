#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int line[100002];
vector<int> v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line[i];
	}
	v.push_back(line[0]);
	for (int i = 0; i < n; i++) {
		if (line[i] > v.back()) v.push_back(line[i]);
		else {
			v[lower_bound(v.begin(), v.end(), line[i]) - v.begin()] = line[i];
		}
	}
	cout << n - v.size();
}