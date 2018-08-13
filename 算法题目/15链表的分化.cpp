/*
1.测试案例通不过，这里的代码太丑了，next取值前应该确认它是有值的
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
class Divide {
public:
	ListNode* listDivide(ListNode* head, int val) {
		if (!head)
			return NULL;
		// write code here
		ListNode* list1, *list2, *list3;
		ListNode* temp = head, *temp2;
		while (temp) {
			temp = temp->next;
			temp2 = temp;

			if (temp->val > val) {
				list1 = buildList(list1, temp2);
			}
			else if (temp->val == val) {
				list2 = buildList(list2, temp2);
			}
			else {
				list3 = buildList(list3, temp2);
			}
		}
		list1 = concatList(list1, list2, list3);
		return list1;
	}
	ListNode* buildList(ListNode* head, ListNode* node) {
		if (!head) {
			head = node;
			node->next = NULL;
		}
		else {
			node->next = head->next;
			head->next = node;
		}
		return head;
	}
	ListNode* concatList(ListNode* list1, ListNode* list2, ListNode* list3) {
		ListNode* list, *last_node;
		if (list1) {
			list = list1;
			while (list1->next) {
				list1 = list1->next;
			}
			last_node = list1;
			if (list2) {
				last_node->next = list2;
				while (list2->next) {
					list2 = list2->next;
				}
				last_node = list2;
				if (list3) {
					last_node->next = list3;
				}
			}
		}
		else if (list2) {
			list = list2;
			while (list2->next) {
				list2 = list2->next;
			}
			last_node = list2;
			if (list3) {
				last_node->next = list3;
			}
		}
		else {
			list = list3;

		}
		return list;
	}
};
int maintbgh() {
	int a[5] = { 1,3,4,5,7 };
	int b[5] = { 1,2,3,4,0 };
	vector<int> va(a, a + 5);
	vector<int>vb(b, b + 5);
	int val = 2;
	//ListNode * res = insert(va, vb, 2);
	int tttt = 5;
	system("pause");
	return 0;
}