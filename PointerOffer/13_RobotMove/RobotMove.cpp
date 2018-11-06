/***********************************************************************
 面试题13：机器人的运动范围
 	地上有一个m行n列的方格。一个机器人从坐标(0,0)的格子开始移动，它
 每次可以向左、右、上、下移动一个，但不能进入行坐标和列坐标的数位之和
 大于k的格子。例如，当k=18时，机器人能够进入方格(35,37)，因为3+5+3+7=18。
 但他不能进入方格(35, 38)，以为3+5+3+8=19。请问该机器人能够到达多少个格子？
 *************************************************************************/

#include <iostream>

using namespace std;

void movingCountCore(const int, const int, const int, int&, int, int, bool*);
int getDigitSum(int);

int movingCount(const int threshold, const int rows, const int cols){
	if(threshold < 0 || rows <= 0 || cols <= 0)
		return 0;

	bool* visited = new bool[rows*cols];
	for(int i = 0; i < rows*cols; i++)
		visited[i] = false;
	int count = 0;
	movingCountCore(threshold, rows, cols, count, 0, 0, visited);
	
	delete[] visited;
	return count;
}

void movingCountCore(
	const int threshold, const int rows, const int cols, 
	int& count, int row, int col, bool* visited){
	if(row >= 0 && row < rows && col >= 0 && col < cols && !visited[row*cols+col] 
		&& getDigitSum(row)+getDigitSum(col) <= threshold){
		count++;
		visited[row*cols+col] = true;
		movingCountCore(threshold, rows, cols, count, row-1, col, visited);
		movingCountCore(threshold, rows, cols, count, row, col+1, visited);
		movingCountCore(threshold, rows, cols, count, row+1, col, visited);
		movingCountCore(threshold, rows, cols, count, row, col-1, visited);
	}
	return;
}

int getDigitSum(int number){
	int sum = 0;
	while(number > 0){
		sum += number%10;
		number /= 10;
	}
	return sum;
}

// ====================测试代码====================
void test(const char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
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

    return 0;
}
