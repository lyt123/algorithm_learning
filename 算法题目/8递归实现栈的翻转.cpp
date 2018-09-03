/*没看懂，貌似跟栈的规律啥的联系紧密*/
#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class StackReverse {
public:
	vector<int> reverseStack(vector<int> A, int n)
	{
		stack<int> sta;
		int i;
		for (i = n - 1; i >= 0; i--)
			sta.push(A[i]);
		revStack(sta);
		vector<int> res;
		while (!sta.empty())
		{
			res.push_back(sta.top());
			sta.pop();
		}
		return res;

	}
	void revStack(stack<int> & sta) {
		//两个函数，一个是得到栈最末尾元素的函数和翻转函数，想法是先得到最末尾的元素，之后将栈翻转，将最末尾的元素压入栈即可
		if (!sta.empty()) {
			int end = getAndRemoveEnd(sta);
			revStack(sta);
			sta.push(end);
		}
	}
	int getAndRemoveEnd(stack<int> & sta) {
		int top = sta.top();
		sta.pop();
		if (!sta.empty()) {
			int res = getAndRemoveEnd(sta);
			sta.push(top);
			return res;
		}
		else {
			return top;
		}
	}
};
int maindgsx()
{
	int a[4] = { 4,3,2,1 };
	vector<int> arr(a, a + 4), res;
	StackReverse A;
	res = A.reverseStack(arr, 4);
	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
		cout << *iter << " ";
	return 0;
}