#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//#include <math.h>
#include <iomanip>
using namespace std;

//https://leetcode-cn.com/problems/house-robber/description/

//暴力方法  通过90%
/*int rob(vector<int>& nums) {
int start_one = recur(nums, 0, 0);
int start_two = recur(nums, 1, 0);

return start_one > start_two ? start_one : start_two;
}

int recur(vector<int>& nums, int index, int sum){
if(index >= nums.size())
return sum;
sum+=nums[index];
int jump_one = recur(nums, index+2, sum);
int jump_two = recur(nums, index+3, sum);
return jump_one > jump_two ? jump_one : jump_two;
}*/

//记忆搜索   通过100%  记忆搜索推导出来后  动态规划也就基本出来了   
int recur(vector<int>& nums, int index, int * help) {
	if (index >= nums.size())
		return 0;
	//把nums从参数中抽出来，从而让记忆搜索成为可能
	int jump_one = nums[index] + ((help[index + 2] == -1) ? recur(nums, index + 2, help) : help[index + 2]);
	int jump_two = nums[index] + ((help[index + 3] == -1) ? recur(nums, index + 3, help) : help[index + 3]);

	help[index] = jump_one > jump_two ? jump_one : jump_two;
	return help[index];
}
int rob(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return nums[0] > nums[1] ? nums[0] : nums[1];
	int * help = new int[nums.size() + 3];
	for (int i = 0; i < nums.size() + 3; i++) {
		help[i] = -1;
	}
	int start_one = recur(nums, 0, help);
	int start_two = recur(nums, 1, help);

	return start_one > start_two ? start_one : start_two;
}
int maintzb()
{
	vector<int> arr = { 1, 2, 3, 1 };
	rob(arr);
	int asdf = 5;
	//system("pause");
	return 0;
}