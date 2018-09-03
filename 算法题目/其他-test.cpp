#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//#include <math.h>
#include <iomanip>
using namespace std;
int sum(int i) {
	int res = 0;
	int value;
	while (i != 0) {
		value = i % 10;
		res += pow(value, 3);
		i = i / 10;
	}
	return res;
}
int maintettt()
{
	vector<vector<int>> data;

	int a, b;
	vector<int> one_layer;
	//int count = 3;
	while (cin >> a >> b) {
		//a = 300; b = 380;
		int res = 0;
		int is_ok = 0;
		for (int i = a; i <= b; i++) {
			res = sum(i);
			if (res == i) {
				if (!is_ok) {
					cout << res;
					is_ok = 1;
				}
				else
				{
					cout << ' ' << res;
				}
			}
		}
		if (!is_ok)
			cout << "no";
		cout << endl;

	}

	//int attt = 5;
	//system("pause");
	return 0;
}