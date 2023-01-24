#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;//벡터선언
int main() {
	int N, A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		v.push_back(A);//원소추가
	}
	sort(v.begin(), v.end());//sort() <algorithm>에 내장된 함수, v를 오름차순으로 정렬
	vector<int>::iterator iter;//반복자

	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << "\n";
	}
	return 0;
}