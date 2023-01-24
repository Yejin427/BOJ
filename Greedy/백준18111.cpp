#include<iostream>
int arr[502][502];
using namespace std;
int main() {
	int N, B, M;
	cin >> M >> N >> B;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int ans_time = 9876545321, ans_layer = -1;
	for (int now_layer = 256; now_layer >= 0; now_layer--) {
		int now_time = 0;
		int now_inventory = B;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] > now_layer) {
					now_inventory += (arr[i][j] - now_layer);
					now_time += (arr[i][j] - now_layer) * 2;
				}
				else if (arr[i][j] < now_layer) {
					now_inventory -= (now_layer - arr[i][j]);
					now_time += (now_layer - arr[i][j]);
				}
			}
		}
		if (now_inventory < 0) continue;
		if (now_time < ans_time) ans_time = now_time, ans_layer = now_layer;
	}
	cout << ans_time << " " << ans_layer << "\n";
}