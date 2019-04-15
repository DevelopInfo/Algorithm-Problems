#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

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
    bool isSymmetrical(TreeNode* pRoot){
        // 中序遍历有问题

        // vector<int> v;
        // //非递归中序遍历
        // stack<TreeNode*> s;
        // TreeNode* p = pRoot;
        // while(p != nullptr || !s.empty()){
        //     if(p != nullptr){
        //         s.push(p);
        //         p = p->left;
        //     }else{
        //         p = s.top();
        //         v.push_back(p->val);
        //         s.pop();
        //         p = p->right;
        //     }
        // }
        
        // bool flag = true;
        // int size = v.size();
        // //遍历中序序列
        // for(int i = 0; i < size/2; i++){
        //     if(v[i] != v[size-1-i]){
        //         flag = false;
        //         break;
        //     }
        // }
        // return flag;

        if(pRoot == nullptr) return true;
        return compare(pRoot->left, pRoot->right);
    }
    
    bool compare(TreeNode *l, TreeNode *r){
        if(l == nullptr) return r == nullptr;
        if(r == nullptr) return l == nullptr;
        if(l->val != r->val) return true;
        return compare(l->right, r->left) && compare(l->left, r->right);
    }

};

TreeNode* creatTree(vector<int> v){
    int size = v.size();
    if(size == 0) return nullptr;
    queue<TreeNode*> q;
    TreeNode* t = new TreeNode(v[0]);
    q.push(t);
    int flag = 0;
    TreeNode* p;
    for(int i = 1; i < size; i++){
        p = q.front();
        if(flag == 0){
            p->left = new TreeNode(v[i]);
            q.push(p->left);
            flag = 1;
        }else{
            p->right = new TreeNode(v[i]);
            q.push(p->right);
            q.pop();
            flag = 0;
        }
    }
    return t;
}

void printTree(TreeNode* t){
    if(t == nullptr){
        cout << "The tree is nullptr!" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(t);
    while(!q.empty()){
        TreeNode *p = q.front();
        q.pop();
        cout << "The Node val is " << p->val << endl;

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

void deleteTree(TreeNode* t){
    if(t == nullptr) return;
    queue<TreeNode*> q;
    q.push(t);
    while(!q.empty()){
        TreeNode *p = q.front();
        q.pop();
        if(p->left != nullptr)
            q.push(p->left);
        if(p->right != nullptr)
            q.push(p->right);
        delete p;
    }
}

int main(){
    vector<int> v = {8,10,10,5,6,6,6};
    TreeNode* t = creatTree(v);
    printTree(t);

    Solution s;
    bool flag = s.isSymmetrical(t);
    cout << flag << endl;
    deleteTree(t);
}