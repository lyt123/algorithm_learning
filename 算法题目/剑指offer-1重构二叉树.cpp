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
	//����ǰ���һ��Ԫ�ؽڵ�
	TreeNode *root = new TreeNode(*preorder_start);

	//��ֹ����
	if (preorder_start == preorder_end)
		return root;

	//ǰ���һ��Ԫ���������λ��  -> pivot
	int len_left = 0;//pivot��inorder_start�ĳ���
	int * pivot = inorder_start;
	while (pivot != inorder_end) {
		if (*pivot == *preorder_start)
			break;
		len_left++;
		pivot++;
	}

	//������
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