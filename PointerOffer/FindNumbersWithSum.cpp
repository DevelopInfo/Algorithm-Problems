#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> v;
        if(array.size() == 0) return v;
        int i = 0, j = array.size()-1;
        while(i < j){
            int s = array[i]+array[j];
            if(s == sum){
                v.push_back(array[i]);
                v.push_back(array[j]);
                break;
            }
            if(s > sum){
                --j;
            }else{
                ++i;
            }
        }
        return v;
    }
};

int main(){
    vector<int> array = {1,2,3,4,11,15};
    int sum = 15;
    Solution s;
    vector<int> v = s.FindNumbersWithSum(array, sum);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ", ";
    }
}