/*
1.map<xx,xx>map;这个命名不要命名成map
2.random指向的可能为空节点，所以要加一个判断
*/
#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* Clone(RandomListNode* pHead) {
	if (pHead == nullptr)
		return nullptr;

	map<RandomListNode*, RandomListNode*> list_map;
	RandomListNode* new_list_head = nullptr, *new_list_current = nullptr, *current = nullptr;

	//构造出来new_list_head
	current = pHead;
	new_list_current = new RandomListNode(current->label);
	new_list_head = new_list_current;
	list_map.insert(make_pair(current, new_list_current));

	//遍历链表拷贝到new_list_head
	current = current->next;
	while (current != nullptr) {
		new_list_current->next = new RandomListNode(current->label);
		new_list_current = new_list_current->next;

		list_map.insert(make_pair(current, new_list_current));

		current = current->next;
	}

	//补全new_list_head链表的random
	current = pHead;
	new_list_current = new_list_head;
	while (current != nullptr) {
		//random指向的可能为空节点，所以要加一个判断
		new_list_current->random = (current->random == nullptr) ? current->random :list_map.find(current->random)->second;

		current = current->next;
		new_list_current = new_list_current->next;
	}
	return new_list_head;
}


int mainfzfzlb() {
	RandomListNode* new_list_head = new RandomListNode(1);
	new_list_head->next = new RandomListNode(2);
	new_list_head->next->next = new RandomListNode(3);
	new_list_head->next->next->next = new RandomListNode(4);
	new_list_head->next->next->next->next = new RandomListNode(5);

	new_list_head->random = new_list_head->next;
	new_list_head->next->random = new_list_head->next->next->next;
	new_list_head->next->next->random = new_list_head->next->next->next->next;
	new_list_head->next->next->next->random = nullptr;
	new_list_head->next->next->next->next->random = new_list_head;

	new_list_head = Clone(new_list_head);
	int aaj = 3;
	system("pause");
	return 0;
}