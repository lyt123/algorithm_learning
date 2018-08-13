/*
1.又没通过测试，算了。还是自己思路不够清晰啊
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
ListNode* inverse(ListNode* head, int k) {
	if (k <= 1) {
		return head;
	}

	ListNode *k_end = nullptr, *start = nullptr, *end, *list = head;

	while (list != nullptr) {
		start = list;
		for (int i = 1; i < k && list != nullptr; i++) {
			list = list->next;
		}

		if (list != nullptr) {
			end = list;
			//reverse  start  end  
			//start为逆序前的开始节点
			ListNode* temp, *pre = start, *now = start->next;
			while (now != end) {
				temp = now->next;
				now->next = pre;
				pre = now;
				now = temp;
			}
			list = end->next;
			end->next = pre;
			//逆序后start为末尾节点，end为开始节点

			if (k_end != nullptr) {
				k_end->next = end;
				k_end = start;
			}
			else {
				k_end = start;
				head = end;
			}
		}
	}
	k_end->next = start;

	return head;
}
class CreatListNode
{
public:
	ListNode* Creat(vector<int> A)
	{
		if (A.empty())
			return NULL;
		ListNode *Head = new ListNode(A[0]), *p = Head;
		for (vector<int>::iterator iter = A.begin() + 1; iter != A.end()-1; iter++)
		{
			(*p).next = new ListNode(*iter);
			p = (*p).next;
		}
		return Head;
	}
	void Print(ListNode* Head)
	{
		ListNode *p = Head;
		while (p)
		{
			cout << (*p).val << " ";
			p = (*p).next;
		}
	}
};
int mainknx() {
	//这两种都跑过测试了
	//int a[8] = { 1,2,3,4,5,6,7,8 };
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> arr(a, a + 9);
	CreatListNode C;
	ListNode *HeadA = C.Creat(arr);

	HeadA = inverse(HeadA, 3);
	C.Print(HeadA);
	system("pause");
	return 0;
}