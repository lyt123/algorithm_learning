#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	Solution() {
		for (int i = 0; i < 256; i++)
			hashtable[i] = -1;
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		str.push_back(ch);
		if (hashtable[ch] != -1 && hashtable[ch] != -2) {
			hashtable[ch] = count;
		}
		else
		{
			hashtable[ch] = -2;
		}
		count++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		if (str.size() == 0)
			return ' ';
		int index = -1;
		for (int i = 0; i < 256; i++) {
			if (hashtable[i] = -1 && hashtable[i] != -1) {
				index = (index == -1) ? i : (i < index ? i : index);
			}
		}
		return str[index];
	}
private:
	int * hashtable = new int[256];
	vector<char> str;
	int count = 0;
};


int mainzfl()
{
	//vector<int> w = { 1,2,3,5,8,8,8,9,10,12 };
	//vector<int> w = { 1,2,3,3,3,3,4,5 };
	vector<int> w = { 3,3,3,3,4,5 };

	//string aaw = to_string(w[0]) + to_string(w[1]);
	//int res = GetNumberOfK(w, 3);
	int a = 54;
	system("pause");
	return 0;
}