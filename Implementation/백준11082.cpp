#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
typedef long long int ll;
ll gcd(ll x, ll y) {
	ll tmp, n;
	if (x < y) {
		tmp = x; x = y; y = tmp;
	}
	while (y != 0) {
		n = x % y;
		x = y;
		y = n;
	}
	return x;
}
string backjoon(string word) {
	string ans;
	if (word.find(".") != string::npos) {
		if (word.find(".(") != string::npos) {//순환소수
			int f = word.find("(");
			string s;
			ll i=stoi( word.substr(0, f-1));
			s += word.substr(f + 1, word.find(")") - f - 1);
			ll x = stoi(s);
			int length = word.find(")") - f - 1;
			ll n = pow(10, length) - 1;
			ll g = gcd(x, n);
			ans += to_string((n / g) * i + x / g);
			ans += "/";
			ans += to_string(n / g);
		}
		else if (word.find("(") != string::npos) {
			string s;
			int f = word.find("("); int f2 = word.find(".");
			ll in= stoi(word.substr(0, f - 1));
			string k = word.substr(f2 + 1, f - f2 - 1);
			ll i = stoi(k);//순환하지 않는 소수부분
			string j1 = word.substr(f + 1, word.find(")")-f- 1);//순환소수부분
			ll j = stoi(k + j1);
			ll n = pow(10, (k + j1).length()) - pow(10, k.length());
			ll g = gcd(j - i, n);
			ans += to_string((n / g) * in + (j - i) / g);
			ans += "/";
			ans += to_string(n / g);
		}
		else {//걍소수
			char* cstr = new char[word.length() + 1];
			strcpy(cstr, word.c_str());
			char* p = strtok(cstr, ".");
			ll chk = 0, n; string x;
			while (p != nullptr) {
				chk++;
				if (chk == 1) x += string(p);
				else {
					n = pow(10, strlen(p));
					x += string(p);
				}
				p = strtok(NULL, ".");
			}
			ll g = gcd(stoi(x), n);
			ans += to_string(stoi(x) / g);
			ans += "/";
			ans += to_string(n / g);
			delete[] cstr;
		}
	}
	else {//자연수
		ans = word + "/1";
	}
	return ans;
}
int main() {
	string word; cin >> word;
	cout << backjoon(word);
}