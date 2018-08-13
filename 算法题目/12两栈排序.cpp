/*
1.代码一次过了，很爽。注意iterator那里的写法
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		// write code here
		for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
			stack1.push(*it);
		}

		while (!stack1.empty()) {
			int stack1_top = stack1.top();
			stack1.pop();
			if (stack2.empty()) {
				stack2.push(stack1_top);
			}
			else {
				while (!stack2.empty() && stack1_top < stack2.top()) {
					stack1.push(stack2.top());
					stack2.pop();
				}
				stack2.push(stack1_top);
			}
		}

		vector<int>res;
		while (!stack2.empty()) {
			res.push_back(stack2.top());
			stack2.pop();
		}
		return res;
	}
private:
	stack<int>stack1;
	stack<int>stack2;
};
int mainzfzd() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	StackReverse c;
//	vector<int> test(a, a + 10);
//	vector<int> test2 = c.reverseStack(test, 10);
//	int aaa = 5;
//	//c.push(3);
//	//cout << c.top() << endl;
	system("pause");
	return 0;
}