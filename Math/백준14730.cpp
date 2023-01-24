#include<iostream>
using namespace std;
int main() {
	int n, a, b, ans = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		ans += a * b;
	}
	cout<< ans;
}