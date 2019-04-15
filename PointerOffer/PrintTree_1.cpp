#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> vs;
            if(pRoot == nullptr) return vs;
            vector<int> v;
            TreeNode* p;
            queue<TreeNode*> q;
            q.push(pRoot);
            q.push(nullptr);//标志位
            while(!q.empty()){
                p = q.front();
                q.pop();
                if(p == nullptr){
                    vs.push_back(v);
                    v.clear();
                    if(q.empty())
                        break;
                    q.push(nullptr);
                    continue;
                }
                v.push_back(p->val);
                if(p->left != nullptr)
                    q.push(p->left);
                if(p->right != nullptr)
                    q.push(p->right);
            }
            return vs;
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
    vector<int> v = {8,9,10,11,12,13,14};
    TreeNode* t = creatTree(v);
    printTree(t);

    Solution s;
    vector<vector<int>> vs = s.Print(t);
    for(int i = 0; i < vs.size(); i++){
        for(int j = 0; j < vs[i].size(); j++){
            cout << vs[i][j] << ", ";
        }
        cout << endl;
    }
    deleteTree(t);
}