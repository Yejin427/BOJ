#include<iostream>
using namespace std;
int n, floyd[1025][1025];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> floyd[i][j];
		}
	}

}