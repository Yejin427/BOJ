#include<iostream>
#include<stack>
using namespace std;
stack<int> s[7];
int main() {
	int N, sumP, J, P, t;
	int ans = 0;
	cin >> N >> sumP;
	while (N--) {
		cin >> J >> P;
		while (1) {
			if (s[J].empty()) {
				s[J].push(P);
				ans++;
				break;

			}
			t = s[J].top();
			if (P == t) break;
			else if (P > t) {
				s[J].push(P);
				ans++;
			}
			else {
				s[J].pop();
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}


