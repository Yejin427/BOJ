#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;//���ͼ���
int main() {
	int N, A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		v.push_back(A);//�����߰�
	}
	sort(v.begin(), v.end());//sort() <algorithm>�� ����� �Լ�, v�� ������������ ����
	vector<int>::iterator iter;//�ݺ���

	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << "\n";
	}
	return 0;
}