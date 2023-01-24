#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main() {
	int T, n, x, sum = 0,k;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		if (n == 0) s.pop();
		else s.push(n);
	}
	k = s.size();
	for (int i = 1; i <= k; i++) {
		x = s.top();
		s.pop();
		sum += x;
	}
	cout << sum;
}