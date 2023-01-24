#include<iostream>
#include<algorithm>
using namespace std;
int arr[501][501], n, m;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	//----
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 3; j++) {
			int tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			ans = max(ans, tmp);
		}
	}
	//||||
	for (int i = 1; i <= n - 3; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
			ans = max(ans, tmp);
		}
	}
	//ㅁ
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int tmp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
			ans = max(ans, tmp);
		}
	}
	//---위에
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			int pick = max(arr[i + 1][j], max(arr[i + 1][j + 1], arr[i + 1][j + 2]));
			int tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + pick;
			ans = max(ans, tmp);
		}
	}
	//---아래
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m - 2; j++) {
			int pick = max(arr[i - 1][j], max(arr[i - 1][j + 1], arr[i - 1][j + 2]));
			int tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + pick;
			ans = max(ans, tmp);
		}
	}
	//|||왼쪽
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int pick = max(arr[i][j + 1], max(arr[i + 1][j + 1], arr[i + 2][j + 1]));
			int tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + pick;
			ans = max(ans, tmp);
		}
	}
	//|||오른쪽
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 2; j <= m; j++) {
			int pick = max(arr[i][j - 1], max(arr[i + 1][j - 1], arr[i + 2][j - 1]));
			int tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + pick;
			ans = max(ans, tmp);
		}
	}
	//ㄱㄴ
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			int tmp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			ans = max(ans, tmp);
		}
	}
	//ㄴㄱ
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int tmp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			ans = max(ans, tmp);
		}
	}
	//ㄱㄴ뒤집은거
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m - 2; j++) {
			int tmp = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
			ans = max(ans, tmp);
		}
	}
	//ㄴㄱ뒤집은거
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 2; j <= m; j++) {
			int tmp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
			ans = max(ans, tmp);
		}
	}
	cout << ans;
}