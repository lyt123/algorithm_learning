//https://leetcode-cn.com/problems/split-array-largest-sum/description/
/*
�ܽ᣺
�ҵ�˼·����
����->�ݹ�  ���Ӷȱ�������Ϊ2^50 �������������뷨��
̰��һֱ�����ҵ�����
//5 8 7 9 1 6 3 2 4 ������7��58���Ǹ�91�������Ǹ���ϵõ���ֵ��С���з���5 7 5 9 1 7 5 2 4
//	//����ô����? �������ķ������ٰ�5 7 5 = 17   ��15����2  ��5 7 ��15��3  �ʸð�5��57  ��û�з����� 6 8 3 8 9 2 4 4 1
̰�Ĳ�����
�����ö�̬�滮  �Ҳ���״̬ת�Ʒ���
���ֵݹ鸴�Ӷ����2^20��������һ�£�д�����˴��룬ͨ��25/27��д�ݹ��ڱ߽����������ֵ���ﻨ��ʱ�䡣
Ȼ�󣬾����ü������������Ƿ��ֱ仯�������� remain_m  index current_value�����䲻�ˣ�ֻ�ܸ�current_value==0�������remain_m��index�Ӽ��䣩�����Բ�֪����ô����

//���±��˵Ľⷨ���������ٿ��ɡ�
*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>  
#include<set> 
#include<map> 
#include<algorithm>
using namespace std;
//class Solution {
//public:
//	//avg_sumΪ�ֽ�  pre_sum+nums[i]>nums nums[i]������߲�����  �ݹ�
//	//��д�����  ʮ�����ڣ���д��
//	//�뵽��->�������г�m��
//	//�߽�ֵҲҪ������
//	//����Ĵ�����Ǵ�ŵ�������  �����������鷳  ��Ҫ����������
//	//��һ�����õİ취�ɣ�����
//	//��ô�붼�ܶ�����ԣ�����
//	//Ҫͻ���Լ���˼ά
//	//5 8 7 9 1 6 3 2 4 ������7��58���Ǹ�91�������Ǹ���ϵõ���ֵ��С���з���5 7 5 9 1 7 5 2 4
//	//����ô����? �������ķ������ٰ�5 7 5 = 17   ��15����2  ��5 7 ��15��3  �ʸð�5��57  ��û�з����� 6 8 3 8 9 2 4 4 1
//	//��֪���ˣ���������ɣ��ѵ����ֻ�ܵݹ��ˣ��õݹ��ټ�����������������������˰�
//
//	//̰��  �����������֣�Ҳ���ҵ�����������
//
//	//�����ܵݹ�  2^50̫����
//
//	//�ö�̬�滮  �ҵ�ǰ��ĵ��ƹ�ϵ  dp[i][j]��ʾ��ǰi�������j�ݵ�max_valueֵ  

//  //���ֵݹ�ĸ��Ӷ����Ҳ��2^20�η������Եݹ����£��ݹ���ͨ��25/27�ˣ��ü��������Ż���
//������������remain_m��index����current_value�������������  �ܷ��current_value�ӵݹ��б�Ϊ�㶨�ģ���Ȼ�ǲ��У���Ϊ�����������������
//	int splitArray(vector<int>& nums, int m) {
//		int sum = sum(nums);
//		int avg = up(sum / m);
//		return recur(nums, avg, m - 1, 0, 0);
//	}
//	int recur(vector<int>& nums, int avg, int remain_m, int index, int current_sum) {
//		//������д�Ļ���һ��ѡ����һ��������󣬺������������ѡ���������������
//		if (m == 0)
//			//��index->nums.size()-1���
//			return sum;
//		current_sum += nums[index]
//			if (current_sum < avg) {
//				recur(nums, avg, remain_m, index + 1, current_sum);
//			}
//			else {
//				int choose = recur(nums, avg, remain_m - 1, index + 1, current_sum);
//				int not_choose = recur(nums, avg, remain_m, index + 1, current_sum);
//			}
//	}
//};


/*��������  ���ǲ���ͨ��ʣ�µ�����*/
//int recur(vector<int>& nums, int remain_m, int index, long long avg, int current_value, vector<vector<int>>&help) {
//	int max_value = 0;
//
//	if (remain_m == 1) {
//		if (index == nums.size())
//			return INT_MAX;//�Ѿ�ûֵ�ˣ�������ֳ�m��
//
//						   //��ֹ ��max_value
//		for (int i = index; i < nums.size(); i++)
//			max_value += nums[i];
//		return max_value;
//	}
//
//	//index������  ����remain_m > 1 ��ôҲ�Ǵ��
//	if (index == nums.size()) {
//		return INT_MAX;
//	}
//
//	if (current_value + nums[index] > avg) {
//		//�Ƚϼ��ϺͲ�����
//		int add;
//		if (help[remain_m - 1][index + 1] == -1 && current_value == 0) {
//			help[remain_m - 1][index + 1] = recur(nums, remain_m - 1, index + 1, current_value + nums[index], 0, help);//����avg��������
//			add = help[remain_m - 1][index + 1];
//		}
//		else {
//			add = recur(nums, remain_m - 1, index + 1, current_value + nums[index], 0, help);
//		}
//
//		int not_add;
//		if (help[remain_m - 1][index] == -1 && current_value == 0) {
//			help[remain_m - 1][index] = recur(nums, remain_m - 1, index, avg, 0, help);
//			not_add = help[remain_m - 1][index];
//		}
//		else {
//			not_add = recur(nums, remain_m - 1, index, avg, 0, help);
//		}
//
//		max_value = max(current_value + nums[index], add);
//		max_value = min(max_value, not_add);
//	}
//	else {
//		//���� �����ݹ�
//
//		if (help[remain_m][index + 1] == -1 && current_value == 0) {
//			help[remain_m][index + 1] = recur(nums, remain_m, index + 1, avg, current_value + nums[index], help);
//			max_value = help[remain_m][index + 1];
//		}
//		else {
//			max_value = recur(nums, remain_m, index + 1, avg, current_value + nums[index], help);
//		}
//	}
//	if (current_value == 0)
//		help[remain_m][index] = max_value;
//	return max_value;
//}
//
//int splitArray(vector<int>& nums, int m) {
//	if (nums.size() < m)
//		return 0;
//	long long sum = 0;
//	for (int i = 0; i < nums.size(); i++)
//		sum += nums[i];
//
//
//	vector<vector<int>>help;
//	vector<int> one_layer(nums.size(), -1);
//	for (int i = 0; i <= m; i++) {
//		help.push_back(one_layer);
//	}
//
//	//�ݹ�
//	return recur(nums, m, 0, ceil(sum / m), 0, help);
//}
//ʲô��û��

//��������
//int recur(vector<int>& nums, int remain_m, int index, long long avg, int current_value) {
//	int max_value = 0;
//
//	if (remain_m == 1) {
//		if (index == nums.size())
//			return INT_MAX;//�Ѿ�ûֵ�ˣ�������ֳ�m��
//
//						   //��ֹ ��max_value
//		for (int i = index; i < nums.size(); i++)
//			max_value += nums[i];
//		return max_value;
//	}
//
//	//index������  ����remain_m > 1 ��ôҲ�Ǵ��
//	if (index == nums.size()) {
//		return INT_MAX;
//	}
//
//	if (current_value + nums[index] > avg) {
//		//�Ƚϼ��ϺͲ�����
//		int add = recur(nums, remain_m - 1, index + 1, avg, 0);//����avg��������
//
//		int not_add = recur(nums, remain_m - 1, index, avg, 0);
//		max_value = max(current_value + nums[index], add);
//		max_value = min(max_value, not_add);
//		//max_value = (current_value + nums[index]) > not_add ? (current_value + nums[index]) : not_add;
//	}
//	else {
//		//���� �����ݹ�        
//		max_value = recur(nums, remain_m, index + 1, avg, current_value + nums[index]);
//	}
//	return max_value;
//}
//int splitArray(vector<int>& nums, int m) {
//	if (nums.size() < m)
//		return 0;
//	long long sum = 0;//����sum���ܻ����������long long
//	for (int i = 0; i < nums.size(); i++)
//		sum += nums[i];
//	//�ݹ�
//	return recur(nums, m, 0, ceil(sum / m), 0);
//}


//�ٿ��ɣ������� leetcode�ϱ����ṩ�ļ�������
//�ܽ᣺��ݹ�Ĵ����˼·ʮ�ֵ�����������Ȼ����ݹ������������ϼ��������Ļ���ʱ�临�Ӷ���n!,�������˼���������ʱ�临�ӶȾͲ��ᳬ��n*m�ˣ��ռ临�Ӷ�Ϊn*m
//Ҳ����˵������ܳ�ĵݹ����Ϊ�Ż������˿��ܣ����������avg��current_value��Ȼ�Ż��˵ݹ飬��ȴ�������ϼ��������ˡ���
int findSA(vector<int>& nums, int start, int m, vector<int>& sums, vector<vector<int>>& memo) {
	if (m == 1) return sums[start];//sum����ֻ�������õ����������ظ�����
	if (memo[start][m] > 0)
		return memo[start][m];
	int min_value = 2147483647, sum = 0;
	for (int i = start; i <= nums.size() - m; i++) {
		sum += nums[i];
		min_value = min(max(sum, findSA(nums, i + 1, m - 1, sums, memo)), min_value);
	}
	memo[start][m] = min_value;
	return memo[start][m];
}
int splitArray(vector<int>& nums, int m) {

	int mm, n;
	mm = nums.size(), n = m + 1;
	vector<vector<int>>memo;
	vector<int> one_layer(n, -1);
	for (int i = 0; i < mm; i++) {
		memo.push_back(one_layer);
	}
	vector<int> sum(mm, -1);
	sum[mm - 1] = nums[mm - 1];
	for (int i = mm - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + nums[i];
	}
	
	return findSA(nums, 0, m, sum, memo);
}
int main()
{
	vector<int> nums = { 5,8,7,9,1,6,3,2,4 };
	//vector<int> nums = { 1, 2147483647 };
	//vector<int> nums = { 499,498,497,496,495,494,493,492,491,490,489,488,487,486,485,484,483,482,481,480,479,478,477,476,475,474,473,472,471,470,469,468,467,466,465,464,463,462,461,460,459,458,457,456,455,454,453,452,451,450,449,448,447,446,445,444,443,442,441,440,439,438,437,436,435,434,433,432,431,430,429,428,427,426,425,424,423,422,421,420,419,418,417,416,415,414,413,412,411,410,409,408,407,406,405,404,403,402,401,400,399,398,397,396,395,394,393,392,391,390,389,388,387,386,385,384,383,382,381,380,379,378,377,376,375,374,373,372,371,370,369,368,367,366,365,364,363,362,361,360,359,358,357,356,355,354,353,352,351,350,349,348,347,346,345,344,343,342,341,340,339,338,337,336,335,334,333,332,331,330,329,328,327,326,325,324,323,322,321,320,319,318,317,316,315,314,313,312,311,310,309,308,307,306,305,304,303,302,301,300,299,298,297,296,295,294,293,292,291,290,289,288,287,286,285,284,283,282,281,280,279,278,277,276,275,274,273,272,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };

	int res = splitArray(nums, 3);
	int sfklj = 3;
	system("pause");
	return 0;
}