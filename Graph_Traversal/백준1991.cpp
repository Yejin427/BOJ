#include<iostream>
#include<vector>
using namespace std;
vector<char> v[27];
int a[27];
int findroot(){
	int i;
	for (i = 0; i <= 26; i++) if (a[i] == 1) break;
	return i;
}
void preorder(char root){
	cout << root;
	for (int i = 0; i < v[root-'A'].size(); i++) {
		if(v[root-'A'][i]!='.') preorder(v[root - 'A'][i]);
	}
}
void inorder(char root) {
	if (v[root-'A'][0]=='.' && v[root-'A'][1]=='.') cout << root;
	else {
		if(v[root-'A'][0]!='.') inorder(v[root - 'A'][0]);
		cout << root;
		if (v[root - 'A'][1] != '.') inorder(v[root - 'A'][1]);
	}
}
void postorder(char root) {
	for (int i = 0; i < v[root - 'A'].size(); i++) {
		if (v[root - 'A'][i] != '.') postorder(v[root - 'A'][i]);
	}
	cout << root;
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		char node, d1, d2;
		cin >> node >> d1 >> d2;
		a[node - 'A']++;
		v[node - 'A'].resize(2);
		v[node - 'A'][0] = d1;
		a[d1 - 'A']++;
		
		v[node - 'A'][1] = d2;
		a[d2 - 'A']++;
		
	}
	char r = findroot()+'A';
	preorder(r); cout << '\n';
	inorder(r); cout << '\n';
	postorder(r);
}
