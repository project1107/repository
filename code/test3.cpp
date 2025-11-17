#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void pri(TreeNode *root) {
	if (root == nullptr)
		return;
	else {

		pri(root->left);
		std::cout << root->val << " ";
		pri(root->right);
	}
}

TreeNode *buildtree(int a[], int n, int *p) {
	if (*p >= n) {
		return nullptr;
	}
	if (a[*p] == -1) {  // Using -1 to represent null nodes
		(*p)++;
		return nullptr;
	}
	TreeNode* node = new TreeNode(a[(*p)++]);
	node->left = buildtree(a, n, p);
	node->right = buildtree(a, n, p);
	return node;
}

int main() {
	int a[] = {1, 2, -1, -1, 3, 4, -1, -1}; // Using -1 to represent null nodes
	int n = sizeof(a) / sizeof(a[0]);
	int p = 0;  // Initialize index
	TreeNode* root = buildtree(a, n, &p);
	std::cout << "Preorder traversal of the tree: ";
	pri(root);
	std::cout << std::endl;
	return 0;
}