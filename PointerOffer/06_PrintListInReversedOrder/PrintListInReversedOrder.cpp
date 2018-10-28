/***********************************************************
 面试题6：从尾到头打印链表
 	输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
 ***********************************************************/

#include <iostream>
#include <forward_list>
using namespace std;

void readElem(forward_list<int>::const_iterator ite, forward_list<int>::const_iterator end_ite){
	if(ite != end_ite){
		cout << *ite << " ";
		readElem(++ite, end_ite);
	}
	return;
}

void PrintList(forward_list<int> *fl){
	if(fl == nullptr)
		return;

	readElem(fl->cbegin(), fl->cend());
	cout << endl;
}

void readElem_reversingly(forward_list<int>::const_iterator ite, forward_list<int>::const_iterator end_ite){
	if(ite != end_ite){
		auto elem = *ite;
		readElem_reversingly(++ite, end_ite);
		cout << elem << " ";
	}
	return;
}
void PrintListReversingly(forward_list<int> *fl){
	if(fl == nullptr)
		return;

	readElem_reversingly(fl->cbegin(), fl->cend());
	cout << endl;
}



// ====================测试代码====================
void Test(forward_list<int> *fl)
{	
    PrintList(fl);
    PrintListReversingly(fl);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");
	
	forward_list<int> fl;
	fl.assign({1,2,3,4,5});

	Test(&fl);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

	forward_list<int> fl;
	fl.assign({1});
    Test(&fl);
}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
