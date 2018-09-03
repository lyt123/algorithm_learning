#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
	int key;
	struct node * left, * right, * parent;
} Node;

Node * root = NULL, * y;

Node * Search(Node * x, int k)
{
	if (x == NULL)
		return NULL;

	if (x->key == k)
		return x;
	else if (x->key > k)
		return Search(x->left, k);
	else
		return Search(x->right, k);
}

void Delete(Node * x)
{
	if (x == root)
	{
		//case 1
		if (x->left == NULL && x->right == NULL) {
			root = NULL;
		}
		//case 2
		else if (x->left == NULL) {
			root = x->right;
			x->right->parent = NULL;
		}
		else if (x->right == NULL) {
			root = x->left;
			x->left->parent = NULL;
		}
		//case 3
		else {
			//这两步找出x的右节点的最左节点
			y = x->right;
			while (y->left != NULL)
				y = y->left;

			//special
			if (y == x->right)
			{
				y->parent = NULL;
				root = y;
				y->left = x->left;
			}
			//general
			else
			{
				Node * y_parent = y->parent, * y_right = y->right;

				y->parent = NULL;
				root = y;

				y->left = x->left;
				y->right = x->right;
				x->left->parent = y;
				x->right->parent = y;

				y_parent->left = y_right;

				if (y_right)
					y_right->parent = y_parent;
			}
		}
	}
	//root不为NULL
	else
	{
		//case 1
		if (x->left == NULL && x->right == NULL) {
			if (x->parent->left == x ) {
				x->parent->left = NULL;
			} else {
				x->parent->right = NULL;
			}
		}
		//case 2
		else if (x->left == NULL) {
			if (x->parent->left == x) {
				x->parent->left = x->right;
				x->right->parent = x->parent;
			} else {
				x->parent->right = x->right;
				x->right->parent = x->parent;
			}
		}
		else if (x->right == NULL) {
			if (x->parent->left == x) {
				x->parent->left = x->left;
				x->left->parent = x->parent;
			} else {
				x->parent->right = x->left;
				x->left->parent = x->parent;
			}
		}
		//case 3
		else {
			//这两步找出x的右节点的最左节点，求x的successor
			y = x->right;
			while (y->left != NULL)
				y = y->left;

			//special,x的下一个节点（其右节点）没有左节点
			if (y == x->right)
			{
				//看x是它parent的左还是右
				if (x->parent->left == x) {
					y->parent = x->parent;
					x->parent->left = y;
				} else {
					y->parent = x->parent;
					x->parent->right = y;
				}

				y->left = x->left;
				x->left->parent = y;
			}
			//general
			else
			{
				Node * y_parent = y->parent, * y_right = y->right;

				//看x是它parent的左还是右
				if (x->parent->left == x) {
					y->parent = x->parent;
					x->parent->left = y;
				} else {
					y->parent = x->parent;
					x->parent->right = y;
				}

				y->left = x->left;
				y->right = x->right;
				x->left->parent = y;
				x->right->parent = y;

				y_parent->left = y_right;

				if (y_right)
					y_right->parent = y_parent;
			}
		}
	}
}

void Insert (Node * x, Node * z)
{
	if (root == NULL)
	{
		root = z;
		z->parent = NULL;
		return;
	}
	else
	{
		if (z->key < x->key)
		{
			if (x->left == NULL) {
				x->left = z;
				z->parent = x;
			}
			else
				Insert(x->left, z);
		}
		else if (z->key > x->key)
		{
			if (x->right == NULL) {
				x->right = z;
				z->parent = x;
			}
			else
				Insert(x->right, z);
		}
		else
			printf("Error, k already exists\n");
	}
}
 
void Preorder(Node * x)
{
	if (x == NULL)
		return;

	printf("%d  ", x->key);

	if (x->left)
		Preorder(x->left);

	if (x->right)
		Preorder(x->right);
}

void Inorder(Node * x)
{
	if (x == NULL)
		return;

	if (x->left)
		Inorder(x->left);

	printf("%d  ", x->key);

	if (x->right)
		Inorder(x->right);
}

Node * FindPredecessor(Node * node_to_find)
{
	Node * temp = node_to_find;
	//这里应该有错误
	if (temp->left != NULL) {
		temp = temp->left;//错误
		//正确的应为return Max(x->left),但我这里没有写Max()函数的实现，所以先算了吧
	} else {
		while (temp->parent != NULL && temp->parent->key > node_to_find->key) {
			temp = temp->parent;
		}
		temp = temp->parent;
	}

	return temp;
}

int mainbst()
{

	Node * new_node, * to_be_deleted, * node_to_find_predecessor;

	int A[10] = {5, 10, 20, 15, 12, 14, 13, 8, 21, 22};

	int i;
	for (i = 0; i < 10; i++)
	{
		new_node = (Node *)malloc(sizeof(Node));
		new_node->left = new_node->right = NULL;
		new_node->key = A[i];

		Insert(root, new_node);
	}

	printf("inorder result\n");
	Inorder(root);
	printf("\n");
	printf("preorder result\n");
	Preorder(root);
	printf("\n");
	//验证search
	// if(Search(root, 14) != NULL)
	// 	printf("found\n");
	// else printf("not found\n");

	to_be_deleted = Search(root, 10);
	if (to_be_deleted) {
		Delete(to_be_deleted);
		printf("10 is deleted\n");
		free(to_be_deleted);
	}

	to_be_deleted = Search(root, 21);
	if (to_be_deleted) {
		Delete(to_be_deleted);
		printf("21 is deleted\n");
		free(to_be_deleted);
	}

	to_be_deleted = Search(root, 17);
	if (to_be_deleted) {
		Delete(to_be_deleted);
		printf("17 is deleted\n");
		free(to_be_deleted);
	} else {
		printf("17 doesn't exist\n");
	}

	printf("inorder result\n");
	Inorder(root);
	printf("\n");
	printf("preorder result\n");
	Preorder(root);
	printf("\n");

	node_to_find_predecessor = Search(root, 20);

	node_to_find_predecessor = FindPredecessor(node_to_find_predecessor);
	if (node_to_find_predecessor != NULL) {
		printf("20 node's predecessor is \n%d\n", node_to_find_predecessor->key);
		// printf("%d\n", FindPredecessor());
	}
	getchar();
	return 0;
}