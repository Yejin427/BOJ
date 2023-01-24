#include<iostream>
int sangdam[18][2];
using namespace std;
int maxi(int x, int y) {
	if (x < y) return y;
	else return x;
}
int main() {
	int n, x, ans=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sangdam[i][0] >> sangdam[i][1];//0이 기간 1이 돈
	}
	for (int i = n; i >= 1;i--) {
		if (i + sangdam[i][0] > n + 1) sangdam[i][1] = sangdam[i + 1][1];
		else {
			sangdam[i][1] = maxi(sangdam[i + 1][1], sangdam[i][1] + sangdam[i + sangdam[i][0]][1]);
			ans = maxi(ans, sangdam[i][1]);//최대값 갱신중
		}
	}
	
	cout << ans;
}