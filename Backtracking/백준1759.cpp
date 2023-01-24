#include<iostream>
#include<algorithm>
char password[16];
char ans[16];
int n, m;
using namespace std;
bool isok(void) {
	int mo = 0, ja = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') mo++;
		else ja++;
	}
	if (ja >= 2 && mo >= 1) return true;
	else return false;
}
void print(int front, int depth) {
	if (depth == n) {
		if (isok()) {
			for (int i = 0; i < n; i++) {
				cout << ans[i];
			}
			cout << "\n";
		}
		return;
	}
	for (int i = front; i < m; i++) {
		ans[depth] = password[i];
		print(i + 1, depth + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> password[i];
	sort(password, password + m);
	print(0, 0);
}