#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* recur(int * preorder_start, int * preorder_end, int * inorder_start, int *inorder_end) {
	//生成前序第一个元素节点
	TreeNode *root = new TreeNode(*preorder_start);

	//终止条件
	if (preorder_start == preorder_end)
		return root;

	//前序第一个元素在中序的位置  -> pivot
	int len_left = 0;//pivot到inorder_start的长度
	int * pivot = inorder_start;
	while (pivot != inorder_end) {
		if (*pivot == *preorder_start)
			break;
		len_left++;
		pivot++;
	}

	//分两边
	if (inorder_start <= pivot - 1)
		root->left = recur(preorder_start + 1, preorder_start + len_left, inorder_start, pivot - 1);

	if (pivot + 1 <= inorder_end)
		root->right = recur(preorder_start + len_left + 1, preorder_end, pivot + 1, inorder_end);

	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	return recur(&pre[0], &pre[pre.size() - 1], &vin[0], &vin[vin.size() - 1]);
}



int maincgecs()
{

	//cout << sizeof(A) << endl;
	system("pause");
	return 0;
}