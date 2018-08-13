/*
1.放两个节点pre和now来跑，还是通不过，不知道什么原因
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
ListNode* insert(vector<int> A, vector<int> nxt, int val) {
	ListNode * pHead, *new_node, *temp;

	//case 1  链表为空
	if (A.empty()) {
		pHead = new ListNode(val);
		return pHead;
	}

	//构造链表
	new_node = new ListNode(A[0]);
	pHead = new_node;

	temp = pHead;
	for (int i = 1; i < A.size(); i++) {
		temp->next = new ListNode(A[i]);
		temp = temp->next;
	}
	temp->next = pHead;


	//  链表不为空
	ListNode * pre = pHead, *now = pHead->next;

	//case 2  插入第一个节点
	if (val <= pHead->val) {
		new_node = new ListNode(val);
		new_node->next = pHead;
		pHead = new_node;
	}
	else {
		while (now != pHead) {
			if (now->val >= val && pre->val <= val) {
				break;
			}
			else {
				temp = now;
				now = now->next;
				pre = temp;
			}
		}
		if (now == pHead) {
			//case 3  插入末尾
			new_node = new ListNode(val);
			new_node->next = pHead;
			pre->next = new_node;
		}
		else {
			//case 4  插入中间
			new_node = new ListNode(val);
			new_node->next = now;
			pre->next = new_node;
		}
	}

	pre = pHead, now = pHead->next;
	while (now != pHead) {
		temp = now;
		now = now->next;
		pre = temp;
	}
	pre->next = nullptr;

	return pHead;
}

int mainlbfh() { 
	int a[7] = { 3,3,7,7,8,12,13 }, nxt[7] = { 1,2,3,4,5,6,0 };
	vector<int> arr(a, a + 7), next(nxt, nxt + 7);
	int val = 2;
	ListNode * res = insert(arr, next, 11);
	int tttt = 5;
	system("pause");
	return 0;
}