#include<iostream>
#include<vector>
using namespace std;
void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}
string reverseSentence(string A, int n) {
	// write code here
	int begin_index = 0, end_index = n - 1;
	while (begin_index < end_index) {
		swap(A[begin_index], A[end_index]);
		begin_index++;
		end_index--;
	}

	//一个一个单词进行切分
	int current_index = 0;
	while (current_index < n) {
		begin_index = current_index;
		end_index = current_index;
		while (A[end_index] != ' ' && end_index < n) {
			end_index++;
		}
		current_index = end_index+1;
		end_index--;
		while (begin_index < end_index) {
			swap(A[begin_index], A[end_index]);
			begin_index++;
			end_index--;
		}
	}
	return A;
}
int mainrv()
{
	string A = "dog loves pig";
	A = reverseSentence(A, 13);
	//cout << A << endl;
	int a = 3;
	system("pause");
	return 0;
}