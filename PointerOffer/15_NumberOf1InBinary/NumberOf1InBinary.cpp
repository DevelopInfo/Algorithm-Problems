/**********************************************************
 面试题15:二进制中1的个数
 	请实现一个函数，输入一个整数，输出该二进制表示中1的个数。
 例如，把9表示成为二进制是1011，有2位是1。因此如果输入9，则
 函数输出2。
 **********************************************************/

#include <iostream>

using namespace std;

int NumberOf1_Solution1(const int number){
	unsigned int flag = 1;
	int count = 0;
	while(flag){
		if(number&flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_Solution2(const int number){
	int num = number;
	int count = 0;
	while(num){
		count++;
		num = (num-1)&num;
	}
	return count;
}

// ====================测试代码====================
void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);
    if (actual == expected)
        printf("Solution1: Test for %d passed.\n", number);
    else
        printf("Solution1: Test for %d failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if (actual == expected)
        printf("Solution2: Test for %d passed.\n", number);
    else
        printf("Solution2: Test for %d failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}
