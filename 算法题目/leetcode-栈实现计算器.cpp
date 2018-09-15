/*
下面的代码应该是跑不起来的，我写着写着发现太麻烦了，可读性太差了。
标准答案给的是两个栈实现的，一个存运算符，一个存数字
*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int calculate(string str) {
	stack<char> s;
	int index = 0;
	int res;
	while (index != str.size()) {
		if (str[index] != ')') {
			if (str[index] == '-') {

			}
			if (str[index] != ' ')
				s.push(str[index]);
		}
		else {
			// "(1+(4+5+2)-3)+(6+8)"
			//s.pop();
			char temp;
			char operate = ' ';
			int num;

			while ((temp = s.top()) != '(') {
				if (temp == '+' || temp == '-') {
					operate = temp;
					s.pop();
				}
				else if (temp >= '0') {
					int temp_res;
					if (operate != ' ') {
						if (operate == '+') {
							temp_res = num + temp - '0';
						}
						else { //operate == '-'
							temp_res = temp - num - '0';
						}
						s.pop();
						s.push(temp_res + '0');
						operate = ' ';

					}
					else {
						//第一个字符
						num = temp - '0';
						s.pop();
					}
				}
			}
			s.pop();
			s.push(num + '0');
		}
		index++;
		// "(1+(4+5+2)-3)+(6+8)"

		//已经没有括号了
		
	}
	int num;
	char temp = s.top();
	char operate = ' ';
	while (!s.empty()) {
		temp = s.top();
		if (temp == '+' || temp == '-') {
			operate = temp;
			s.pop();
		}
		else if (temp >= '0') {
			int temp_res;
			if (operate != ' ') {
				if (operate == '+') {
					temp_res = num + temp - '0';
				}
				else { //operate == '-'
					temp_res = temp - num - '0';
				}
				s.pop();
				s.push(temp_res + '0');
				operate = ' ';

			}
			else {
				//第一个字符
				num = temp - '0';
				s.pop();
			}
		}
	}
	return num;
}
int mainzsx() {
	//string s = "(1+(4+5+2)-3)+(6+8)";
	string s = " 2-1 + 2 ";
	int res = calculate(s);
	int sadfj = 3;

	//完成
	system("pause");

	return 0;
}