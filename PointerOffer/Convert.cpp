#include <iostream>
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        //递归结束条件
        if(pRootOfTree->left == nullptr && pRootOfTree->right == nullptr)
            return pRootOfTree;
        TreeNode *p, *left;
        left = pRootOfTree;
        //将左子树变换成双链表
        if(pRootOfTree->left != nullptr){
            left = Convert(pRootOfTree->left);
            p = left;
            while(p->right != nullptr)
                p = p->right;
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        //将右子树变换成双链表
        if(pRootOfTree->right != nullptr){
            p = Convert(pRootOfTree->right);
            pRootOfTree->right = p;
            p->left = pRootOfTree;
        }
        return left;
    }
};

// ====================测试代码====================
void PrintTreeNode(const TreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->val);

        if(pNode->left != nullptr)
            printf("value of its left child is: %d.\n", pNode->left->val);
        else
            printf("left child is nullptr.\n");

        if(pNode->right != nullptr)
            printf("value of its right child is: %d.\n", pNode->right->val);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const TreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->left != nullptr)
            PrintTree(pRoot->left);

        if(pRoot->right != nullptr)
            PrintTree(pRoot->right);
    }
}

void PrintDoubleLinkedList(TreeNode* pHeadOfList)
{
    TreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->val);

        if(pNode->right == nullptr)
            break;
        pNode = pNode->right;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->val);

        if(pNode->left == nullptr)
            break;
        pNode = pNode->left;
    }

    printf("\n");
}

TreeNode* CreateBinaryTreeNode(int value)
{
    TreeNode* pNode = new TreeNode(value);
    pNode->left = nullptr;
    pNode->right = nullptr;

    return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void DestroyList(TreeNode* pHeadOfList)
{
    TreeNode* pNode = pHeadOfList;
    while(pNode != nullptr)
    {
        TreeNode* pNext = pNode->right;

        delete pNode;
        pNode = pNext;
    }
}

void Test(char* testName, TreeNode* pRootOfTree)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    PrintTree(pRootOfTree);

    Solution s;
    TreeNode* pHeadOfList = s.Convert(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    TreeNode* pNode10 = CreateBinaryTreeNode(10);
    TreeNode* pNode6 = CreateBinaryTreeNode(6);
    TreeNode* pNode14 = CreateBinaryTreeNode(14);
    TreeNode* pNode4 = CreateBinaryTreeNode(4);
    TreeNode* pNode8 = CreateBinaryTreeNode(8);
    TreeNode* pNode12 = CreateBinaryTreeNode(12);
    TreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyList(pNode4);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    TreeNode* pNode5 = CreateBinaryTreeNode(5);
    TreeNode* pNode4 = CreateBinaryTreeNode(4);
    TreeNode* pNode3 = CreateBinaryTreeNode(3);
    TreeNode* pNode2 = CreateBinaryTreeNode(2);
    TreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyList(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    TreeNode* pNode1 = CreateBinaryTreeNode(1);
    TreeNode* pNode2 = CreateBinaryTreeNode(2);
    TreeNode* pNode3 = CreateBinaryTreeNode(3);
    TreeNode* pNode4 = CreateBinaryTreeNode(4);
    TreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyList(pNode1);
}

// 树中只有1个结点
void Test4()
{
    TreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyList(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}