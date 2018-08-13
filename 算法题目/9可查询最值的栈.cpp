/*注意栈空的判断，如果栈空时读stack.top()是会出错的*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	void push(int value) {
		value_stack.push(value);
		if (min_stack.empty()) {
			min_stack.push(value);
		}
		else if (!min_stack.empty() && value <= min_stack.top()) {
			min_stack.push(value);
		}
	}
	void pop() {
		if (!value_stack.empty()) {
			if (value_stack.top() == min_stack.top()) {
				min_stack.pop();
			}
			value_stack.pop();
		}
	}
	int top() {
		if (!value_stack.empty())
		return value_stack.top();
	}
	int min() {
		if (!min_stack.empty())
		return min_stack.top();
	}
private:
	stack<int> value_stack;
	stack<int> min_stack;
};
int mainsv () {
	Solution c;
	c.push(3);
	cout << c.top() << endl;
	system("pause");
	return 0;
}