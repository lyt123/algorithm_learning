#include<iostream>
#include<vector>
using namespace std;
//int Flip(int c)
//{
//	return c ^ 1;
//
//}
//int GetSign(int c)
////�Ǹ�Ϊ1����Ϊ0.
//{
//	return Flip((c >> 31) & 1);
//}
//int getMax(int a, int b)
//{
//	int c = a - b;
//	int as = GetSign(a);
//	int bs = GetSign(b);
//	int cs = GetSign(c);
//	int sam = Flip(as^bs);
//	if (sam)
//		return cs ? a : b;
//	else
//		return (as - bs) ? a : b;
//}
int getSign(int num) {
	//������0 ������1
	return (num >> 31) & 1 ^ 1;
}
int getMax(int a, int b) {
	// write code here
	int a_sign = getSign(a);
	int b_sign = getSign(b);
	int c = a - b;
	int c_sign = getSign(c);
	if (a_sign && b_sign) {
		return c_sign ? a : b;
	}
	else if (a_sign && !b_sign) {
		return a;
	}
	else if (!a_sign && b_sign) {
		return b;
	}
	else {
		return c_sign ? a : b;
	}
}


int mainwys()
{
	int res = getMax(4597112, 14102417);
	int a = 5;
	system("pause");
	return 0;
}