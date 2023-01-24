#include<iostream>
int num[502][502], n, arr[502][502];
using namespace std;
int max(int x, int y) {
	if (x < y) return y;
	else return x;
}
int topdown(int i, int j) {
	if (i == n) {
		arr[i][j] = num[i][j];
		return arr[i][j];
	}
	if (arr[i][j] >= 0) return arr[i][j];
	arr[i][j]= num[i][j]+max(topdown(i + 1, j) , topdown(i + 1, j + 1));
	return arr[i][j];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
			arr[i][j] = -1;
		}
	}
	cout << topdown(1, 1);
}