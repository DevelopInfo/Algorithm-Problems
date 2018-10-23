/****************************************************************
 面试题３（二）：不修改数组找出重复的数字。
 	在一个长度为n+1的数组里的所有数字都在１～ｎ的范围内，所以数组
 中至少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能
 修改输入的数组。例如，如果输入长度为８的数组{2,3,5,4,3,2,6,7}，那
 么对应的输出是重复的数字２或者３。
 ****************************************************************/

#include <iostream>

using namespace std;

int getDuplication_0(const int* nums, const int len){
	// 使用辅助数组
	if(nums == nullptr || len <= 0)
		return -1; 
	
	int tmp[len] = {};
	for(int i = 0; i < len; i++){
		if(nums[i] >= len || nums[i] <= 0)
			return -1;
		if(tmp[nums[i]] != 0)
			return nums[i];
		tmp[nums[i]]++;
	}
}

int countRange(const int* nums, const int len, const int low, const int high){
	if(nums == nullptr || len <= 0)
		return 0;

	int count = 0;
	for(int i = 0; i < len; i++){
		if(nums[i] >= low && nums[i] <= high)
			count++;
	}
	return count;
}

int getDuplication_1(const int* nums, const int len){
	// 使用类似二分查找的方法
	if(nums == nullptr || len <= 0)
	   	return -1;

	int start = 1, end = len-1;
	while(start <= end){
		int mid = ( start + end ) / 2;
		int count = countRange(nums, len, start, mid);
		if(start == end)
			if(count > 1)
				return start;
			else
				break;
		
		if(count > mid-start+1)
			end = mid;
		else
			start = mid+1;
	}
	return -1;	
}


// =======================测试代码==============================
void test(const char* testName, int* nums, int len, int* duplications, int dupLen){
	// int result = getDuplication_0(nums, len);
	int result = getDuplication_1(nums, len);
	for(int i = 0; i < dupLen; i++){
		if(result == duplications[i]){
			cout << testName << " passed" << endl;
			return;
		}
	}
	cout << testName << " failed." << endl;
}

//多个重复数字
void test1(){
	int nums[] = {2,3,5,4,3,2,6,7};
	int duplications[] = {2,3};
	test("test1", nums, sizeof(nums)/sizeof(int), duplications, sizeof(duplications)/sizeof(int));
}

//一个重复数字
void test2(){
	int nums[] = {3,2,1,4,4,5,6,7};
	int duplications[] = {4};
	test("test2", nums, sizeof(nums)/sizeof(int), duplications, sizeof(duplications));
}

// 重复的数字是数组中最小的数字
void test3()
{
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
    int duplications[] = { 1 };
    test("test3", nums, sizeof(nums) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最大的数字
void test4()
{
    int nums[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    int duplications[] = { 8 };
    test("test4", nums, sizeof(nums) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 数组中只有两个数字
void test5()
{
    int nums[] = { 1, 1 };
    int duplications[] = { 1 };
    test("test5", nums, sizeof(nums) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字位于数组当中
void test6()
{
    int nums[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
    int duplications[] = { 3 };
    test("test6", nums, sizeof(nums) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 多个重复的数字
void test7()
{
    int nums[] = { 1, 2, 2, 6, 4, 5, 6 };
    int duplications[] = { 2, 6 };
    test("test7", nums, sizeof(nums) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个数字重复三次
void test8()
{
    int nums[] = { 1, 2, 2, 6, 4, 5, 2 };
    int duplications[] = { 2 };
    test("test8", nums, sizeof(nums) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 没有重复的数字
void test9()
{
    int nums[] = { 1, 2, 6, 4, 5, 3 };
    int duplications[] = { -1 };
    test("test9", nums, sizeof(nums) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 无效的输入
void test10()
{
    int* nums = nullptr;
    int duplications[] = { -1 };
    test("test10", nums, 0, duplications, sizeof(duplications) / sizeof(int));
}

int main(void){
	test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}
