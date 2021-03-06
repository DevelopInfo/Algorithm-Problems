#include <iostream>
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr) return nullptr;
        TreeNode* p = pRoot;
        stack<TreeNode*> s;
        int count = k;
        while(p != nullptr || !s.empty()){
            if(p != nullptr){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                if(--count<=0){
                    break;
                }
                p = p->right;
            }
        }
        if(count != 0)
            return nullptr;//树没有ｋ个节点
        return p;
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
    vector<int> v = {8,6,10,5,7,9,11};
    TreeNode* t = creatTree(v);
    printTree(t);

    int k = 3;
    Solution s;
    TreeNode* kp = s.KthNode(t, k);
    cout << kp->val << endl;
    deleteTree(t);
}