#include<iostream>
using namespace std;
int arr[10], ans, n, w, t, k;
int cp[10];
void dfs(int time, int num) {
	if (time == t) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (arr[i] > 0) cnt++;
		if (cnt >= k) ans++;
		return;
	}
	int copy2[10];
	for (int i = 1; i <= n; i++)copy2[i] = arr[i];
	for (int nxt = num - 1; nxt <= num + 1; nxt++) {
		if (1 <= nxt && nxt <= n) {
			int copy[10];//화력감소
			for (int i = 1; i <= n; i++) copy[i] = arr[i];
			for (int i = 1; i <= n; i++) {
				if (arr[i] <= 0 || i == nxt) continue;
				else if (arr[i + 1] > 0 && arr[i - 1] > 0) copy[i]--;
				else if (arr[i + 1] > 0) copy[i] -= 2;
				else if (arr[i - 1] > 0) copy[i] -= 2;
				else copy[i] -= 3;
			}
			for (int i = 1; i <= n; i++) {
				arr[i] = copy[i];
			}
			dfs(time + 1, nxt);//장작넣기
			for (int i = 1; i <= n; i++) arr[i] = copy2[i];//화력 돌려놓기
		}
	}
}
int main() {
	cin >> n >> w >> t >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cp[i] = arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i + 1] > 0 && arr[i - 1] > 0) cp[i]--;
		else if (arr[i + 1] > 0) cp[i] -= 2;
		else if (arr[i - 1] > 0) cp[i] -= 2;
		else cp[i] -= 3;
	}
	for (int i = 1; i <= n; i++)arr[i] = cp[i];
	dfs(1, w + 1);
	cout << ans;
}