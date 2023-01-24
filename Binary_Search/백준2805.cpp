#include<iostream>
#include<algorithm>
using namespace std;
long long int namu[1000002], n;
long long int cut(long long int h) {
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		if (h < namu[i]) ans += (namu[i] - h);
	}
	return ans;
}
long long int answer(int m) {
	long long int max, min, mid, x;
	min = 1, max = namu[n-1];
	while (min <= max) {
		mid = (min+max) / 2;
		if (m > cut(mid)) {
			max = mid - 1;
		}
		else if (m < cut(mid)) {
			x = mid;
			min = mid + 1;
		}
		else {
			return mid;
			break;
		}
 	}
	return x;
}
int main() {
	long long int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> namu[i];
	}
	sort(namu,namu+n);
	cout << answer(m);
}