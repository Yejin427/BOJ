#include<iostream>
using namespace std;
int main() {
	int n, k, mid, min = 1, midnum, ans;
	cin >> n >> k;
	int max = k;
	while (1) {
		mid = (min + max) / 2;
		midnum = 0;
		for (int i = 1; i <= n; i++) {
			if (mid / i >= n) midnum += n;
			else midnum += (mid / i);
		}
		if (k > midnum) {//���ݺ��� ū ���� ���ؾ� �Ҷ�
			min = mid + 1;
		}
		else {
			max = mid - 1;
			ans = mid;
		}
		if (min > max) {
			cout << ans;
			break;
		}
	}
}