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
		//���������һ������ر����
		//��һ���룬�ñ�"abcabdabf"��nextval[]Ϊ{000120120}����2�½�Ϊ0����һ��ֵ����Ҫ������
		for (int i = 1; i < nextval.size() - 3; i++) {
			if (nextval[i] >= nextval[i + 1]) {
				better_nextval[i] = nextval[i];
			}
		}

		//���һ��Ԫ������Դ�
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

		//��һ���Ż�
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

		//��ͷ��ʼ�ȶԣ�û�ҵ��ͻ���
		int str_point = 0, src_point = 0;

		while (
			src_point < src.size() - 1 &&
			str_point < str.size() - 1
			) {

			if (src[src_point] == str[str_point]) {  //��� �Ƚ���ȥ
				str_point++;
				src_point++;
			}
			else if (str_point == 0) {				 //str�ĵ�һ��Ԫ�غ�src�ĵ�һ��Ԫ�ز���  src_point������
				src_point++;
			}
			else {									 //����
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

		//ע�����ﲻ����������������if�жϣ���Ȼ�ͽ���ȥ�ˣ�'��'Ҳ�Ͳ��ܼ���
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
��Ŀ���ж�һ��������һ�����������ṹ
��ǰ���õݹ�ʵ�֣���kmp�㷨����Ч
*/