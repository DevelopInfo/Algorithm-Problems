/************************************************************
 面试题3（一）：找出数组中重复的数字
 	在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中
 某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字
 重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长
 度为7的数组{2, 3, 1, 0, 2, 5, 3}，那么对应的输出是重复的数字
 2或者3。
 ************************************************************/

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool haveDuplication_0(int nums[], const int len, int* duplication){
	// 使用排序的方法
	
	if(nums == nullptr || len <= 0){
		return false;
	}
	sort(nums, nums+len);
	for(int i = 0; i < len-1; i++){
		if(nums[i] < 0 || nums[i] > len-1){
			return false;
		}
		if(nums[i] == nums[i+1]){
			*duplication = nums[i];
			return true;
		}
	}
	return false;
}

bool haveDuplication_1(int nums[], const int len, int* duplication){
	// 使用关联容器
	
	if(nums == nullptr || len <= 0)
		return false;

	map<int, int> nums_map;
	for(int i = 0; i < len; i++){
		if(nums[i] < 0 || nums[i] > len-1){
			return false;
		}

		if(++nums_map[nums[i]] != 1){
			*duplication = nums[i];
			return true;
		}
	}
	return false;
}

bool haveDuplication_2(int nums[], const int len, int* duplication){
	// 利用下标与数字的关系
	
	if(nums == nullptr || len <= 0)
		return false;

	for(int i = 0; i < len; i++){
		while(nums[i] != i){
			if(nums[i] < 0 || nums[i] > len-1){
				return false;
			}

			if(nums[nums[i]] == nums[i]){
				*duplication = nums[i];
				return true;
			}
			//swap
			int tmp = nums[i];
			nums[i] = nums[tmp];
			nums[tmp] = tmp;
		}
	}
	return false;
}
/***********测试代码***************/
bool contains(int array[], int len, int number){
	for(int i = 0; i < len; i++){
		if(array[i] == number)
			return true;
	}
	return false;
}

void test(const char* testName, int nums[], int lenNums, 
		  int expected[], int lenExpected, bool validArgument){
	cout << testName << " begins: " << endl;

	int duplication=0;
	// bool validInput = haveDuplication_0(nums, lenNums, &duplication);
	// bool validInput = haveDuplication_1(nums, lenNums, &duplication);
	bool validInput = haveDuplication_2(nums, lenNums, &duplication);

	if(validArgument == validInput){
		if(validArgument){
			if(contains(expected, lenExpected, duplication)){
				cout << "Passed." << endl;
			}else{
				cout << "FAILED." << endl;
			}
		}else{
			cout << "Passed." << endl;
		}
	}else{
		cout << "FAILED." << endl;
	}

}

// 重复的数字是数组中最小的数字
void test1(){
	int nums[] = { 2, 1, 3, 1, 4};
	int duplications[] = { 1 };
	test("test1", nums, sizeof(nums)/sizeof(int), 
		 duplications, sizeof(duplications)/sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2(){
	int nums[] = {2, 1, 3, 4, 4};
	int duplications[] = { 4 };
	test("test2", nums, sizeof(nums)/sizeof(int), 
		 duplications, sizeof(duplications)/sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3(){
	int nums[] = {2, 4, 1, 4 ,1};
	int duplications[] = {1,4};
	test("test3", nums, sizeof(nums)/sizeof(int), 
		 duplications, sizeof(duplications)/sizeof(int), true);
}

// 没有重复的数字
void test4(){
	int nums[] = {2, 1, 3, 4, 0};
	int duplications[] = {-1};
	test("test4", nums, sizeof(nums)/sizeof(int), 
		 duplications, sizeof(duplications)/sizeof(int), false);
}

// 没有重复的数组，但数组中数字超出范围
void test5(){
	int nums[] = {2,1,4,5,0};
	int duplications[] = { -1 };
	test("test5", nums, sizeof(nums)/sizeof(int), 
		 duplications, sizeof(duplications)/sizeof(int), false);
}
// 无效输入
void test6(){
	int* nums = nullptr;
	int duplications[] = {-1};
	test("test6", nums, sizeof(nums)/sizeof(int), 
		 duplications, sizeof(duplications)/sizeof(int), false);
}

int main(void){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();	
}
