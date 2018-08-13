#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void reOrderArray(vector<int> &array) {
	//两种办法  ： 用O(n)空间  不用
	for (int i = 0; i < array.size() - 1; i++) {
		for (int j = array.size() - 1; j > 0; j--) {
			if ((array[j] % 2) == 1 && (array[j - 1] % 2) == 0) {
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}
int mainjsfd()
{
	vector<int> arr = { 2,4,6,1,3,5,7 };
	reOrderArray(arr);
	int b = 3;

	int a = 5;
	//cout << sizeof(A) << endl;
	system("pause");
	return 0;
}