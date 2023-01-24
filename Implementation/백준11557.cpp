#include<iostream>
#include<utility>
#include<string>
using namespace std;
pair<string, int> p[102];
int main() {
	int N, k, max = 0, h = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> p[i].first >> p[i].second;
			if (max < p[i].second) {
				max = p[i].second;
				h = i;
			}
		}
		cout << p[h].first << "\n";
	}
}