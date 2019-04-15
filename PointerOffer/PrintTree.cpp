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
        
        int levelIndex = 0;
        int count = 1;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(pRoot);
        vector<int> v;
        TreeNode* p;
        while(!s1.empty() || !s2.empty()){
            if(count > 0){
                if(levelIndex % 2 == 0){
                    p = s1.top();
                    s1.pop();
                    v.push_back(p->val);
                    if(p->left != nullptr){
                        s2.push(p->left);
                    }
                    if(p->right != nullptr){
                        s2.push(p->right);
                    }
                }else{
                    p = s2.top();
                    s2.pop();
                    v.push_back(p->val);
                    if(p->right != nullptr){
                        s1.push(p->right);
                    }
                    if(p->left != nullptr){
                        s1.push(p->left);
                    }
                }
                count--;
            }else{
                vs.push_back(v);
                v.clear();
                if(levelIndex % 2 == 0){
                    count = s2.size();
                }else{
                    count = s1.size();
                }
                    
                levelIndex++;
            }
        }
        vs.push_back(v);
        
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