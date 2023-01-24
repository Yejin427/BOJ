#include<iostream>
using namespace std;
typedef struct node node;
struct node {
	int num;
	node* left;
	node* right;
};
node* Insert(node* root, int n) {
	if (!root) {
		root = new node;
		root->num = n;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->num < n) {
		root->right = Insert(root->right, n);
	}
	else if (root->num > n) {
		root->left = Insert(root->left, n);
	}
	return root;
}
void traverse(node* root) {
	if (root) {
		traverse(root->left);
		traverse(root->right);
		cout << root->num << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	node* root = NULL;
	while (!cin.eof()) {
		cin >> n;
		root = Insert(root, n);
	}
	traverse(root);
}