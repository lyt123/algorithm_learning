///*
//1.这道题重新做吧，放两个节点pre和now来跑，比我这里的temp->next->next的形式好一点。虽然都能实现，但是优雅很多
//*/
//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//ListNode* insert(vector<int> A, vector<int> nxt, int val) {
//	ListNode * pHead, *new_node, *temp;
//
//	//case 1  链表为空
//	if (A.empty()) {
//		pHead = new ListNode(val);
//		return pHead;
//	}
//
//	//构造链表
//	new_node = new ListNode(A[0]);
//	pHead = new_node;
//
//	temp = pHead;
//	for (int i = 1; i < A.size(); i++) {
//		temp->next = new ListNode(A[i]);
//		temp = temp->next;
//	}
//	temp->next = pHead;
//
//	//case 2  链表不为空
//	temp = pHead;
//
//	//case 2.1 在第一个节点插入
//
//	if (val <= pHead->val) {
//		new_node = new ListNode(val);
//		new_node->next = pHead->next;
//		pHead->next = new_node;
//		return pHead;
//	}
//
//	while (1) {
//		if (val > temp->next->val && temp->next->next != pHead) {
//			temp = temp->next;
//		}
//		else {
//			//到达最后一个节点		
//			if (temp->next->next == pHead) {
//				if (val <= temp->next->val) {
//					//case2.2 在倒数第二个位置插入
//					//temp = temp->next;
//				}
//				else {
//					//case2.3在末尾插入
//					temp = temp->next;
//				}
//			}
//
//			//case 2.4在中间插入
//			new_node = new ListNode(val);
//			new_node->next = temp->next;
//			temp->next = new_node;
//			break;
//		}
//	}
//	temp = pHead;
//	while (temp->next != pHead) {
//		temp = temp->next;
//	}
//	temp->next = nullptr;
//	return pHead;
//}
//
//int maintng() {
//	int a[5] = { 1,3,4,5,7 };
//	int b[5] = { 1,2,3,4,0 };
//	vector<int> va(a, a + 5);
//	vector<int>vb(b, b + 5);
//	int val = 2;
//	ListNode * res = insert(va, vb, 2);
//	int tttt = 5;
//	system("pause");
//	return 0;
//}