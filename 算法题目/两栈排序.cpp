#include <iostream>
using namespace std;


int longestSubstring(string A, int n) {
	// write code here
	//char *map = new char[n];
	int map[256];
	for (int i = 0; i < 256; i++) {
		map[i] = -1;
	}
	int longest_str = 0;
	int longest_str_help = 0;
	for (int i = 0; i < n; i++) {
		if (
			(map[A[i]] != -1) &&
			(i - map[A[i]] <= longest_str)
			)
		{
			longest_str_help = (longest_str > longest_str_help) ? longest_str : longest_str_help;
			longest_str = i - map[A[i]];
		}
		else {
			longest_str++;
		}
		map[A[i]] = i;
	}
	return (longest_str > longest_str_help) ? longest_str : longest_str_help;
}

int mainzw() {
	//string test = "aabcb";
	//string test = "aabcbaad";
	string test = "spnvw";
	int n = 5;
	int res = longestSubstring(test, 5);
	cout << res << endl;
	system("pause");
	return 0;
}