/*
1.�������˿������ܿ��ܾ�������ȥд�����ˣ������������˼·��д�����룬������ͨ��һ���֣�������ʱ�������Ż��ɼ�����������
2.�����ֱ�����dp��״̬ת�Ʒ��̣��Ǿͼ���
3.��������д��������˼·���Ȳ�ִ�У��ҵ��˹��ɣ�ֱ���ü��������ķ���ȥ�ģ�δ���Թ���
*/
#include <iostream>
#include <vector>
using namespace std;
//����
int recur(vector<int> & w, vector<int>& v, int n, int current_index, int cap, int current_cap, int current_value) {
	if (current_index == n)
		return current_value;
	//װ������
	int use = 0;
	if ((current_cap + w[current_index]) <= cap)
		use = recur(w, v, n, current_index + 1, cap, current_cap + w[current_index], current_value + v[current_index]);
	//װ������
	int no_use = recur(w, v, n, current_index + 1, cap, current_cap, current_value);

	return use > no_use ? use : no_use;
}
int max(vector<int> w, vector<int> v, int n, int cap) {
	return recur(w, v, n, 0, cap, 0, 0);
}

//��������
//int recur(vector<int> & w, vector<int>& v, int n, int current_index, int cap, int **help) {
//	if (current_index == n)
//		return 0;
//
//	//װ������
//	int use = 0;
//	int cap_remain = cap - w[current_index];
//	if (cap_remain >= 0) {
//		use = v[current_index];
//		if (help[current_index + 1][cap_remain] == -1)
//			help[current_index + 1][cap_remain] = recur(w, v, n, current_index + 1, cap_remain, help);
//		use += help[current_index + 1][cap_remain];
//	}
//	//װ������
//	if (help[current_index + 1][cap] == -1)
//		help[current_index + 1][cap] = recur(w, v, n, current_index + 1, cap, help);
//	int no_use = help[current_index + 1][cap];
//
//	return use > no_use ? use : no_use;
//}
//int max(vector<int> w, vector<int> v, int n, int cap) {
//	//help��ά������µݹ���Ľ��
//	int ** help = new int*[n + 1];
//	for (int i = 0; i < n + 1; i++) {
//		help[i] = new int[cap + 1];
//	}
//	for (int i = 0; i < n + 1; i++) {
//		for (int j = 0; j < cap + 1; j++)
//			help[i][j] = -1;
//	}
//	return recur(w, v, n, 0, cap, help);
//}

//��̬�滮
//int max(vector<int> w, vector<int> v, int n, int cap) {
//	int ** dp = new int *[n];
//	for (int i = 0; i < n; i++) {
//		dp[i] = new int[cap + 1];
//	}
//
//	for (int i = 0; i < n; i++) {
//		dp[i][0] = 0;
//	}
//	for (int i = 0; i < cap + 1; i++) {
//		if (i >= w[0])
//			dp[0][i] = v[0];
//		else
//			dp[0][i] = 0;
//	}
//
//	for (int i = 1; i < n; i++) {
//		for (int j = 1; j < cap + 1; j++) {
//			if (j >= w[i] && dp[i - 1][j] < (dp[i - 1][j - w[i]] + v[i]))
//				dp[i][j] = dp[i - 1][j - w[i]] + v[i];
//			else
//				dp[i][j] = dp[i - 1][j];
//		}
//	}
//	return dp[n - 1][cap];
//}

int mainbbwt() {
	//����1
	//vector<int> w = { 1, 2, 3};
	//vector<int> v = { 1, 2, 3};
	//int res = max(w, v, 3, 6);//6

	//����2
	//vector<int> w = { 42,25,30,35,42,21,26,28 };
	//vector<int> v = { 261,247,419,133,391,456,374,591 };
	//int res = max(w, v, 8, 297);//2872

	//����3  �ñ�����ͨ����
	vector<int> w = { 15, 21, 33, 36, 30, 19, 37, 19, 16, 29, 34, 40, 31, 27, 16, 31, 38, 17, 35, 22, 17, 36, 28, 28, 21, 19, 32, 17 };
	vector<int> v = { 523, 612, 359, 90, 79, 630, 437, 83, 520, 463, 262, 44, 354, 531, 150, 186, 642, 122, 93, 383, 125, 70, 271, 519, 76, 368, 46, 278 };
	int res = max(w, v, 28, 394);//6849

	int a = 5;
	cout << res << endl;
	system("pause");
	return 0;
}