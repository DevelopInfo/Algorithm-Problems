/*******************************************************************
 面试题11：旋转数组的最小数字
 	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
 {3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 *******************************************************************/\

#include <iostream>
#include <exception>

using namespace std;

int MinInOrder(const int* nums, const int start, const int end){
	int result = nums[start];
	for(int i = start; i <= end; i++ ){
		if(result > nums[i])
			result = nums[i];
	}
	return result;
}

int Min(const int* nums, const int len){
	if(nums == nullptr || len <= 0)
		throw "Invalid parameters";
	int start = 0, end = len-1;
	while(nums[start] >= nums[end]){
		if(start == end -1){
			break;
		}
		int mid = (start+end)/2;
		if(nums[start] == nums[mid] && nums[start] == nums[end])
			return MinInOrder(nums, start, end);

		if(nums[mid] >= nums[start])
			start = mid;
		else if(nums[mid] <= nums[end])
			end = mid;
	}
	if(nums[start] > nums[end])
		return nums[end];
	else
		return nums[start];

}

// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(nullptr, 0, 0);

    return 0;
}
