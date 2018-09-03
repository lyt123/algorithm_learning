#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x = 0) :
		val(x), left(NULL), right(NULL) {
	}
};


TreeNode* CreateBinaryTreeNode(int value)
{
	TreeNode* pNode = new TreeNode();
	pNode->val = value;
	pNode->left = nullptr;
	pNode->right = nullptr;

	return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;
	}
}

class IdenticalTree {
public:
	vector<int> &  get_better_nextval(vector<char> & str, vector<int> & nextval) {
		vector<int> better_nextval;
		//理论依据我还不是特别清楚
		//简单一点想，好比"abcabdabf"，nextval[]为{000120120}当从2下降为0的那一个值才需要保留啊
		for (int i = 1; i < nextval.size() - 3; i++) {
			if (nextval[i] >= nextval[i + 1]) {
				better_nextval[i] = nextval[i];
			}
		}

		//最后一个元素特殊对待
		if (nextval[str.size() - 2] < nextval[str.size() - 3]) {
			better_nextval[str.size() - 3] = nextval[str.size() - 3];
		}

		return better_nextval;
	}
	void get_nextval(vector<char> & str, vector<int> & nextval) {
		nextval.push_back(0);
		int index = 1;
		while (index < str.size() - 2) {
			if (str[index] == str[nextval[index - 1]]) {
				nextval.push_back(nextval[index - 1] + 1);
			}
			else if (str[index] == str[0]) {
				nextval.push_back(1);
			}
			else {
				nextval.push_back(0);
			}
			index++;
		}

		//进一步优化
		for (int i = 1; i < str.size() - 3; i++) {
			if (nextval[i] < nextval[i + 1]) {
				nextval[i] = 0;
			}
		}
	}

	bool checkSubStrExist(vector<char> & src, vector<char> & str) {
		vector<int> nextval;
		get_nextval(str, nextval);
		//vector<int> better_nextval = get_better_nextval(str, nextval);

		//从头开始比对，没找到就回溯
		int str_point = 0, src_point = 0;

		while (
			src_point < src.size() - 1 &&
			str_point < str.size() - 1
			) {

			if (src[src_point] == str[str_point]) {  //相等 比较下去
				str_point++;
				src_point++;
			}
			else if (str_point == 0) {				 //str的第一个元素和src的第一个元素不等  src_point往后移
				src_point++;
			}
			else {									 //回溯
				str_point = nextval[str_point - 1];
			}

		}
		return (str_point == str.size() - 1) ? true : false;
	}

	void tree_to_string(TreeNode *root, vector<char> &str) {
		if (root == nullptr) {
			str.push_back('!');
			return;
		}

		int value = root->val;
		while (value % 10) {
			str.push_back((root->val % 10) + '0');
			value = root->val / 10;
		}
		str.push_back(',');

		//注意这里不用像下面那样加上if判断，不然就进不去了，'！'也就不能加了
		tree_to_string(root->left, str);
		tree_to_string(root->right, str);

		/*if (root->left) {
			tree_to_string(root->left, str);
		}
		if (root->right) {
			tree_to_string(root->right, str);
		}*/
	}

	bool chkIdentical(TreeNode* A, TreeNode* B) {
		// write code here
		vector<char> str_A;
		tree_to_string(A, str_A);
		str_A.push_back('\0');
		vector<char> str_B;
		tree_to_string(B, str_B);
		str_B.push_back('\0');

		return checkSubStrExist(str_A, str_B);
	}
};

int mainit()
{
	TreeNode* pNode10 = CreateBinaryTreeNode(1);
	TreeNode* pNode6 = CreateBinaryTreeNode(2);
	TreeNode* pNode14 = CreateBinaryTreeNode(3);
	TreeNode* pNode4 = CreateBinaryTreeNode(4);
	TreeNode* pNode8 = CreateBinaryTreeNode(5);
	TreeNode* pNode12 = CreateBinaryTreeNode(6);
	TreeNode* pNode16 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	TreeNode* pNodeA = CreateBinaryTreeNode(1);

	IdenticalTree c;
	bool d = c.chkIdentical(pNode10, pNodeA);
	//cout << (d ? "nice" : "awful") << endl;
	system("pause");
	return 0;
}
/*
题目：判断一棵树是另一个数的子树结构
以前我用递归实现，用kmp算法更高效
*/