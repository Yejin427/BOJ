#include<iostream>
#include<vector>
using namespace std;
vector<int> v(80);
int n;
bool test1(int depth,int num) {
	if (v[depth - 1] == num) return false;
	else return true;
}
bool test2(int depth, int num) {
	if (v[depth - 1] == v[depth - 3] && v[depth - 2] == num) return false;
	else return true;
}
bool test3(int depth, int num) {
	if (v[depth - 1] == v[depth - 4] && v[depth - 2] == v[depth - 5] && v[depth - 3] == num) return false;
	else return true;
}
void good(int depth) {
	if (depth == n) {
		for (int i = 0; i < n; i++) {
			cout << v[i];
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (depth < 4) {
			if (test1(depth, i)) {
				v[depth] = i;
				good(depth + 1);
			}
		}
		else if (depth >= 4 && depth < 6) {
			if (test1(depth, i) && test2(depth, i)) {
				v[depth] = i;
				good(depth + 1);
			}
		}
		else {
			if (test1(depth, i) && test2(depth, i) && test3(depth, i)) {
				v[depth] = i;
				good(depth + 1);
			}
		}
	}
}
int main() {
	cin >> n;
	v[0] = 1;
	good(1);

}
