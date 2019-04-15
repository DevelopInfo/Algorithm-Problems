#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) 
            return false;
        stack<int> s;
        int k = 0;
        for(int i = 0; i < pushV.size(); i++){
            s.push(pushV[i]);
            while(k < popV.size() && s.top() == popV[k]){
            //while(s.top() == popV[k] && k < popV.size())
            //这里容易出现段错误
                s.pop();
                k++;
            }
        }
        return s.empty();
    }
};

int main(){
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,5,3,2,1};
    Solution s;
    cout << s.IsPopOrder(pushV, popV) << endl;
}