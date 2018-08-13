//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//{
//	if (pHead1 == nullptr)
//		return pHead2;
//	if (pHead2 == nullptr)
//		return pHead1;
//
//	//list1代表链表第一个值更小的链表
//	ListNode* merged_head, *list1_current, *list2_current;
//	if (pHead1->val < pHead2->val) {
//		merged_head = pHead1;
//		list1_current = pHead1->next;
//		list2_current = pHead2;
//	}
//	else {
//		merged_head = pHead2;
//		list1_current = pHead2->next;
//		list2_current = pHead1;
//	}
//
//	ListNode* list1_back, *list2_temp;
//	list1_back = merged_head;
//	while (list1_current != nullptr && list2_current != nullptr) {
//		if (list1_current->val > list2_current->val) {
//			//insert
//			list2_temp = list2_current->next;
//
//			list2_current->next = list1_current;
//			list1_back->next = list2_current;
//
//			list2_current = list2_temp;
//		}
//		else {
//			list1_back = list1_current;
//			list1_current = list1_current->next;
//		}
//	}
//
//	if (list1_current == nullptr) {
//		list1_back->next = list2_current;
//	}
//
//	return merged_head;
//}
//bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//
//	vector<int> help;
//	int i = 0, j = 0;
//
//	while (1) {
//		if (help.empty()) {
//			help.push_back(pushV[i]);
//			i++;
//		}
//		if (help.top() != popV[j]) {
//			help.push_back(pushV[i]);
//			i++;
//			if (i == pushV.size())
//				break;
//		}
//		else {
//			help.pop();
//			j++;
//		}
//	}
//	bool res;
//	while (1) {
//		if (help.empty()) {
//			res = true;
//			break;
//		}
//
//		if (help.top() == popV[j]) {
//			help.pop();
//			j++;
//		}
//		else {
//			res = false;
//			break;
//		}
//	}
//	return res;
//}
//int main()
//{
//	ListNode	node1(1);
//	ListNode	node2(3);
//	ListNode	node3(7);
//	ListNode	node4(8);
//	ListNode	node5(12);
//	ListNode	node6(15);
//	node1.next = &node2;
//	node2.next = &node3;
//	node3.next = &node4;
//	node4.next = &node5;
//	node5.next = &node6;
//
//	ListNode	node21(2);
//	ListNode	node22(4);
//	ListNode	node23(10);
//	ListNode	node24(11);
//	node21.next = &node22;
//	node22.next = &node23;
//	node23.next = &node24;
//
//	ListNode * res = Merge(&node1, &node21);
//	int b = 3;
//
//	int a = 5;
//	//cout << sizeof(A) << endl;
//	system("pause");
//	return 0;
//}