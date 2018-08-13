/*
1.map<xx,xx>map;���������Ҫ������map
2.randomָ��Ŀ���Ϊ�սڵ㣬����Ҫ��һ���ж�
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
	//���Ƿ��л�
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

	//�л�
	//������Ĵ�С->��previous���ƶ���������
	ListNode *temp = meet_point->next, *previous = head, *behind = head;
	while (temp != meet_point) {
		temp = temp->next;
		previous = previous->next;
	}
	previous = previous->next;

	//��������ָ����ƶ��ҵ��������
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