#include <iostream>
#include <vector>
using namespace std;

//��������
//int recur(vector<int>& penny, int index, int aim) {
//  //���ﲻ��aim == 0�����aim==0˵��ǰ���������
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

//�����������ڱ��������Ļ����ϼ��϶���Ŀռ���µݹ�������ֵ��
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
		//���������ļ�������������ϵ�
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