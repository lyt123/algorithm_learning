#include<iostream>
#include<vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x = 0) :
		val(x), left(NULL), right(NULL) {
	}
};


TreeNode* CreateBinaryTreeNode(int value);
//{
//	TreeNode* pNode = new TreeNode();
//	pNode->val = value;
//	pNode->left = nullptr;
//	pNode->right = nullptr;
//
//	return pNode;
//}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight);
//{
//	if (pParent != nullptr)
//	{
//		pParent->left = pLeft;
//		pParent->right = pRight;
//	}
//}

void inorder(vector<int>& res, TreeNode* root) {
	/*if (!root)
		return;
	stack<TreeNode *> temp;
	TreeNode *p = root;
	while (!temp.empty() || p)
	{
		while (p)
		{
			temp.push(p);
			p = (*p).left;
		}
		p = temp.top();
		temp.pop();
		res.push_back((*p).val);
		p = (*p).right;
	}*/
	stack<TreeNode*> help;
	TreeNode* top_node = root, *temp = nullptr;

	help.push(root);
	temp = root->left;
	while (temp) {
		help.push(temp);
		temp = temp->left;
	}

	while (!help.empty()) {
		top_node = help.top();
		help.pop();
		res.push_back(top_node->val);
		temp = top_node->right;
		while (temp) {
			help.push(temp);
			temp = temp->left;
		}
	}

	//有错误，死循环了。因为每次出去的时候又插入了所有left进来
	/*while (!help.empty()) {
		top_node = help.top();
		if (top_node->left && top_node->left != previous_top_node) {
			help.push(top_node->left);
		}
		else {
			help.pop();
			res.push_back(top_node->val);
			if (top_node->right)
				help.push(top_node->right);
			previous_top_node = top_node;
		}
	}*/
}
void postorder(vector<int>& res, TreeNode* root) {

	stack<TreeNode *> s;
	TreeNode *h = root, *c = NULL, *p = NULL;
	s.push(root);
	while (!s.empty())
	{
		c = s.top();
		if ((*c).left&&h != (*c).left&&h != (*c).right)
			s.push((*c).left);
		else if ((*c).right&&h != (*c).right)
			s.push((*c).right);
		else
		{
			res.push_back((*c).val);
			h = c;
			s.pop();
		}
	}
}
int mainsfse()
{
	TreeNode* pNode10 = CreateBinaryTreeNode(8);
	TreeNode* pNode6 = CreateBinaryTreeNode(4);
	TreeNode* pNode14 = CreateBinaryTreeNode(10);
	TreeNode* pNode4 = CreateBinaryTreeNode(2);
	TreeNode* pNode8 = CreateBinaryTreeNode(6);
	TreeNode* pNode12 = CreateBinaryTreeNode(9);
	TreeNode* pNode16 = CreateBinaryTreeNode(12);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);
	vector<int> res;
	postorder(res, pNode10);
	int abc = 5;

	//cout << (d ? "nice" : "awful") << endl;
	system("pause");
	return 0;
}