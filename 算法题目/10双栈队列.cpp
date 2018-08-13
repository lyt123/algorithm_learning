/*
1.�����������д������ѧһѧ
2.�������Ե�ʱ����û��ǲ�Ҫ�ֿ������ˣ��ᵼ�¿ռ临�Ӷ�������
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TwoStack {
public:
	vector<int> twoStack(vector<int> ope, int n) {
		vector<int> res;
		int pop_res;
		for (vector<int>::iterator it = ope.begin(); it != ope.end(); it++) {
			if (*it != 0) {
				push(*it);
			}
			else {
				pop_res = pop();
				if (pop_res != 0) {
					res.push_back(pop_res);
				}
			}
		}
		return res;
	}
	void push(int value) {
		stack1.push(value);
	}
	int pop() {
		int res = 0;
		if (!stack2.empty()) {
			res = stack2.top();
			stack2.pop();
		}
		else {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
			if (!stack2.empty()) {
				res = stack2.top();
				stack2.pop();
			}
		}
		return res;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
int mainsd() {
	//Solution c;
	//c.push(3);
	//cout << c.top() << endl;
	system("pause");
	return 0;
}