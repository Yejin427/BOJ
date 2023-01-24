#include<iostream>
#include<algorithm>
using namespace std;
char chess[51][51];
int main() {
	int n, m,w,b, ans=2500, cnt;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[j][i];
		}
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			w = 0; b = 0;
			for (int k = i; k < i+8; k++) {
				for (int l = j; l < j+8; l++) {
					if ((k + l) % 2 == 0) {
						if (chess[l][k] != 'W') {
							w++;
						}
						else b++;
					}
					else {
						if (chess[l][k] != 'B'){
							w++;
						}
						else b++;
					}

				}
			}
			cnt= min(w, b);
			ans = min(ans, cnt);
		}
	}
	cout << ans;
}
