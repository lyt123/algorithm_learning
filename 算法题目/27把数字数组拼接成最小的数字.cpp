#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isShorter(const int &a, const int &b)
{
	string str_ab = to_string(a) + to_string(b);
	string str_ba = to_string(b) + to_string(a);
	return str_ab < str_ba;
	//return a > b;
}
void sortStr(vector<int> &numbers) {
	sort(numbers.begin(), numbers.end(), isShorter);
}
string PrintMinNumber(vector<int>& numbers) {
	string res = "";
	//ÅÅĞò
	sortStr(numbers);
	//Æ´½ÓÆğÀ´
	string num_str;
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		res += to_string(*it);
	}
	return res;
}


int mainpjc()
{
	vector<int> w = { 3,32,321,234,112,23,11 };

	//string aaw = to_string(w[0]) + to_string(w[1]);

	sort(w.begin(), w.end(), isShorter);
	string res = PrintMinNumber(w);
	int a = 54;
	system("pause");
	return 0;
}