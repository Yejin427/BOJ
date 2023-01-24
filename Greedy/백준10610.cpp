#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
char n[100002];
int main() {
	int sum = 0, chk = 0;
	cin >> n;
	for (int i = 0; n[i]!='\0'; i++) {
		sum += n[i] - '0';
		a.push_back(n[i] - '0');
	}
	if (sum % 3 != 0) {
		cout << "-1";
		return 0;
	}
	for (int i = 0; n[i]!='\0'; i++) {
		if (n[i] == '0') chk = 1;
	}
	if (chk == 0) {
		cout << "-1";
		return 0;
	}
	sort(a.begin(), a.end());
	for (int i = a.size() - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}