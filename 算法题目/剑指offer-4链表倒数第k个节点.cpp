#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == nullptr || k <= 0)
		return nullptr;

	ListNode * current = pListHead, *pre = pListHead;
	while (k-- != 0) {
		if (pre == nullptr)
			return nullptr;
		pre = pre->next;
	}
	while (pre != nullptr) {
		pre = pre->next;
		current = current->next;
	}

	return current;
}
int mainlbds()
{
	ListNode	node1(1);
	ListNode	node2(2);
	ListNode	node3(3);
	ListNode	node4(4);
	ListNode	node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	ListNode * res = FindKthToTail(&node1, 2);
	int b = 3;

	int a = 5;
	//cout << sizeof(A) << endl;
	system("pause");
	return 0;
}