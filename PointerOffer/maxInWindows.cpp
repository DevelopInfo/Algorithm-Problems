#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> v;
        if(num.size() == 0) return v;
        if(size == 0) return v;
        deque<int> dq;
        int begin = 0;
        for(int i = 0; i < num.size(); i++){
            begin = i-size+1;
            if(dq.front() < begin){
                dq.pop_front();
            }
            while(!dq.empty() && num[dq.back()] <= num[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(begin >= 0)
                v.push_back(num[dq.front()]);
        }
        return v;
    }
};

int main(){
    vector<int> num = {2,3,4,2,6,2,5,1};
    unsigned int size = 0;
    Solution s;
    vector<int> v = s.maxInWindows(num, size);
    for(int i = 0; i < v.size(); i++ ){
        cout << v[i] << ", ";
    }
}
