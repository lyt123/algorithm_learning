/*
1.map<xx,xx>map;这个命名不要命名成map
2.random指向的可能为空节点，所以要加一个判断
*/
#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
int chkLoop(ListNode* head) {
	// write code here
	ListNode* fast = head, *slow = head, *meet_point = nullptr;
	//看是否有环
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			meet_point = slow;
			break;
		}
	}
	if (meet_point == nullptr)
		return -1;

	//有环
	//求出环的大小->在previous的移动种体现了
	ListNode *temp = meet_point->next, *previous = head, *behind = head;
	while (temp != meet_point) {
		temp = temp->next;
		previous = previous->next;
	}
	previous = previous->next;

	//根据两个指针的移动找到环的入口
	while (previous != behind) {
		previous = previous->next;
		behind = behind->next;
	}

	return previous->val;
}


int mainlbph () {
	ListNode* new_list_head = new ListNode(1);
	new_list_head->next = new ListNode(2);
	new_list_head->next->next = new ListNode(3);
	new_list_head->next->next->next = new ListNode(4);
	new_list_head->next->next->next->next = new ListNode(5);
	new_list_head->next->next->next->next->next = new ListNode(6);
	new_list_head->next->next->next->next->next->next = new ListNode(7);
	new_list_head->next->next->next->next->next->next->next = new ListNode(8);
	new_list_head->next->next->next->next->next->next->next->next = new_list_head->next->next->next->next;

	int res = chkLoop(new_list_head);
	int aaj = 3;
	system("pause");
	return 0;
}