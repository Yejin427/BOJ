#include<iostream>
#include<algorithm>
using namespace std;
int kii[10];
int main() {
	int plus = 0;
	for (int i = 0; i < 9; i++) {
		cin >> kii[i];
		plus += kii[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (plus - kii[i] - kii[j] == 100) {
				kii[i] = 0, kii[j] = 0;
				sort(kii, kii + 9);
				for (int i = 2; i < 9; i++) {
					cout << kii[i] << "\n";
				}
				break;
			}
		}
	}
}
