/*********************************************************************
 面试题14:剪绳子
 	给你一根长度为n的绳子，请把绳子剪成m段(m、n都是整数，n>1并且m>=1)。
 每段绳子的长度记为k[0],k[1],...,k[m]。k[0]*k[1]*...*k[m]可能的最大乘积
 是多少?例如当绳子的长度是8时，我们把它剪成长度分别是2,3,3的三段，此时
 得到最大乘积18。
 *********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

// ====================动态规划====================
int maxProductAfterCutting_solution1(const int len){
	if(len <= 1)
		return 0;
	else if(len == 2)
		return 1;
	else if(len == 3)
		return 2;
	int maxProduct[len] = {0};
	maxProduct[0] = 1;// 绳子长1时不剪
	maxProduct[1] = 2;// 绳子长2时不剪
	maxProduct[2] = 3;// 绳子长3时不剪

	for(int i = 3; i < len; i++){
		for(int j = 0; j <= i/2; j++){
			if(maxProduct[i] < maxProduct[j]*maxProduct[i-j-1])
				maxProduct[i] = maxProduct[j]*maxProduct[i-j-1];
		}
	}

	return maxProduct[len-1];
}

// ====================贪婪算法====================
int maxProductAfterCutting_solution2(const int len){
	if(len <= 1)
		return 0;
	else if(len == 2)
		return 1;
	else if(len == 3)
		return 2;
	else if(len == 4)
		return 4;
	int i = len/3;
	int j = len%3;
	if(j == 1){
		i--;
		j += 3;
	}else if(j == 0){
		j++;
	}
	return pow(3,i)*j;
	
}


// ====================测试代码====================
void test(const char* testName, int length, int expected)
{
    int result1 = maxProductAfterCutting_solution1(length);
    if(result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProductAfterCutting_solution2(length);
    if(result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
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
    test11();

    return 0;
}
