#include <iostream>
#include <vector>
using namespace std;

//暴力搜索
//int recur(vector<int>& penny, int index, int aim) {
//  //这里不加aim == 0会出错，aim==0说明前边配对上了
//	if (aim == 0)
//		return 1;
//	if (index == penny.size() - 1) {
//		return (aim % penny[index] == 0) ? 1 : 0;
//	}
//
//	int ways = 0;
//	if (aim >= penny[index]) {
//		int loop_num = aim / penny[index];
//		for (int i = 0; i <= loop_num; i++) {
//			ways += recur(penny, index + 1, aim - penny[index] * i);
//		}
//		return ways;
//	}
//	else {
//		return 0;
//	}
//}
//int countWays(vector<int> penny, int n, int aim) {
//	if (n == 0 || aim == 0)
//		return 0;
//	return recur(penny, 0, aim);
//}

//记忆搜索（在暴力搜索的基础上加上额外的空间存下递归计算过的值）
int recur(vector<int>& penny, int index, int aim, int ** help) {
	if (aim == 0)
		return 1;
	if (index == penny.size() - 1) {
		return (aim % penny[index] == 0) ? 1 : 0;
	}

	int ways = 0;
	if (aim >= penny[index]) {
		int loop_num = aim / penny[index];
		for (int i = 0; i <= loop_num; i++) {
			if (help[index + 1][aim - penny[index] * i] != -1)
				ways += help[index + 1][aim - penny[index] * i];
			else
				ways += recur(penny, index + 1, aim - penny[index] * i, help);
		}
		//记忆搜索的记忆是在这里打上的
		help[index][aim] = ways;
		return ways;
	}
	else {
		return 0;
	}
}
int countWays(vector<int> penny, int n, int aim) {
	if (n == 0 || aim == 0)
		return 0;
	int ** help = new int *[n];
	for (int i = 0; i < n; i++)
		help[i] = new int[aim + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < aim + 1; j++)
			help[i][j] = -1;
	return recur(penny, 0, aim, help);
}
int mainhbzl() {
	vector<int> test = { 1, 2 , 4 };
	int res = countWays(test, 3, 3);
	int a = 5;
	cout << res << endl;
	system("pause");
	return 0;
}