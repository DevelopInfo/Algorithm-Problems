#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
            return nullptr;
        TreeLinkNode* p = pNode;
        // 如果该节点的右子树非空
        if(pNode->right != nullptr){
            p = pNode->right;
            while(p->left != nullptr)
                p = p->left;
            return p;
        }
        // 循环判断该节点是不是其父节点的左子节点
        while(p->next != nullptr){
            if(p->next->left == p){
                return p->next;
            }else{
                p = p->next;
            }
        }

        return nullptr; // 退到根节点依然没找到
    }
};

TreeLinkNode* creatTree(vector<int> v){
    int size = v.size();
    if(size == 0) return nullptr;
    queue<TreeLinkNode*> q;
    TreeLinkNode* t = new TreeLinkNode(v[0]);
    q.push(t);
    int flag = 0;
    TreeLinkNode* p;
    for(int i = 1; i < size; i++){
        p = q.front();
        if(flag == 0){
            p->left = new TreeLinkNode(v[i]);
            p->left->next = p;
            q.push(p->left);
            flag = 1;
        }else{
            p->right = new TreeLinkNode(v[i]);
            p->right->next = p;
            q.push(p->right);
            q.pop();
            flag = 0;
        }
    }
    return t;
}

void printTree(TreeLinkNode* t){
    if(t == nullptr){
        cout << "The tree is nullptr!" << endl;
        return;
    }
    queue<TreeLinkNode*> q;
    q.push(t);
    while(!q.empty()){
        TreeLinkNode *p = q.front();
        q.pop();
        cout << "The Node val is " << p->val << endl;

        if(p->next != nullptr){
            cout << "The node next val is " << p->next->val << endl;
        }else{
            cout << "The node next val is nullptr" << endl;
        }

        if(p->left != nullptr){
            cout << "The node left val is " << p->left->val << endl;
            q.push(p->left);
        }
        else{
            cout << "The node left val is nullptr !" << endl;
        }

        if(p->right != nullptr){
            cout << "The node right val is " << p->right->val << endl;
            q.push(p->right);
        }
        else{
            cout << "The node right val is nullptr !" << endl;
        }
    }
}

void deleteTree(TreeLinkNode* t){
    if(t == nullptr) return;
    queue<TreeLinkNode*> q;
    q.push(t);
    while(!q.empty()){
        TreeLinkNode *p = q.front();
        q.pop();
        if(p->left != nullptr)
            q.push(p->left);
        if(p->right != nullptr)
            q.push(p->right);
        delete p;
    }
}

int main(){
    vector<int> v = {8,6,10,5,7,9,11};
    TreeLinkNode* t = creatTree(v);
    printTree(t);

    Solution s;
    TreeLinkNode* p = s.GetNext(t);
    cout << p->val << endl;
    p = s.GetNext(t->left->right);
    cout << p->val << endl;
    deleteTree(t);
}