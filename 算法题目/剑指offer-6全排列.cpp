#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res;
		if (str.size() == 0)
			return res;
		if (str.size() == 1) {
			res.push_back(str);
			return res;
		}

		string str_help;
		recur(&str[0], &str[str.size() - 1], str_help, res);
		return res;
	}

	void recur(char * start, char * end, string str, vector<string> & res) {
		if (start != end) {
			char * temp = start;
			while (temp <= end) {
				swap(temp, start);
				recur(start + 1, end, str + *start, res);
				swap(start, temp);
				temp++;
			}
		}
		else {
			//得到结果
			str = str + *start;
			res.push_back(str);
		}
	}

	void swap(char * a, char * b) {
		char c;
		c = *a;
		*a = *b;
		*b = c;
	}
};

int mainaaa()
{
	Solution s;
	string str = "abcde";
	s.Permutation(str);
	int a = 5;
	return 0;
}