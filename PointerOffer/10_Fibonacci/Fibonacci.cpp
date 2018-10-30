/******************************************************
 面试题10：斐波那契数列
 	写一个函数，输入n,求斐波那契(Fabonacci)数列的第n项。
 *****************************************************/

#include <iostream>

using namespace std;

int Fibonacci_Solution1(int n){
	// 递归方法
	if(n < 0)
		return -1;
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2);
}

int Fibonacci_Solution2(int n){
	// 循环方法
	if(n < 0)
		return -1;
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	int f0 = 0, f1 = 1;
	int f2;
	for(int i = 2; i <= n; i++){
		f2 = f0+f1;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}

// ====================测试代码====================
void Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);
/*
    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
*/
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}

