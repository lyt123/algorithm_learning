#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define SRC_LEN 15
#define STR_LEN 7
char src[SRC_LEN] = "dgoogddkgoogle";
char str[STR_LEN] = "google";

void str_match() {
	//��ͷ��ʼ�ȶԣ�û�ҵ��ͻع�
	int str_point = 0, src_point = 0;

	while (
		src_point < SRC_LEN - 1 &&
		str_point < STR_LEN - 1
		) {
		if (src[src_point] == str[str_point]) {
			src_point++;
			str_point++;
		}
		else {
			src_point = src_point - str_point + 1;
			str_point = 0;
		}

	}
	if (str_point == STR_LEN - 1) {
		cout << "ƥ��ɹ�";
	}
}

int main() {
	str_match();

	system("pause");

	return 0;
}