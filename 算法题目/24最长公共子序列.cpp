#include <iostream>
#include <vector>
using namespace std;

int findLCS(string A, int n, string B, int m) {
	int * help = new int[n];
	int * help2 = new int[n];
	for (int i = 0; i < n; i++) {
		help[i] = 0;									//求出最长子序列
		help2[i] = -1;
		for (int j = 0; j < m; j++) {
			if (A[i] == B[j]) {							//可能有多个位置等于
				help[i] = 1;
				for (int k = 0; k < j; k++) {
					for (int kk = 0; kk < i; kk++) {
						if (A[kk] == B[k]) {
							if (help[kk] >= help[i] && help2[kk] < j) {
								help[i] = help[kk] + 1;
								help2[i] = j;
							}
						}
					}
				}
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (help[i] > max)
			max = help[i];
	}
	return max;
}


int mainzcg()
{
	string A = "1A2C3D4B56";
	string B = "B1D23CA45B6A";
	int res = findLCS(A, 10, B, 12);
	int a = 54;
	system("pause"); 
	return 0;
}