#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[501][501];
int time[260];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, b;
	cin >> n >> m >> b;
	int low = 300, high = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			low = min(low, arr[i][j]);
			high = max(high, arr[i][j]);
		}
	}
	memset(time, -1, sizeof(time));
	for (int a = low; a <= high; a++) {
		time[a] = 0;
		int invent = b;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] > a) {
					time[a] += (arr[i][j] - a) * 2;
					invent += (arr[i][j] - a);
				}
				else if (arr[i][j] < a) {
					time[a] += (a - arr[i][j]);
					invent -= (a - arr[i][j]);
				}
			}
		}
		if (invent < 0) {
			time[a] = -1;
		}
	}
	int ans = time[low];
	int h = low;
	for (int i = low; i <= high; i++) {
		if (time[i] != -1) {
			if (ans >= time[i]) {
				ans = time[i];
				h = i;
			}
		}
		//cout << time[i] << " ";
	}
	//cout << '\n';
	cout << ans << " " << h;
}