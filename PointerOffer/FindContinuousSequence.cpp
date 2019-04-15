#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> vs;
        if(sum <= 0) return vs;
        // //　思路１：双指针解法

        // int left = 1, right = 2;
        // int tempSum = 1;
        // vector<int> v;
        // v.push_back(1);
        // while(left < right){
        //     if(tempSum == sum){
        //         if(right - left != 1)//序列只有一个元素的不加入
        //             vs.push_back(v);
        //         tempSum -= left;
        //         v.erase(v.begin());
        //         left++;
        //     }else if(tempSum < sum){
        //         tempSum += right;
        //         v.push_back(right);
        //         right++;
        //     }else{
        //         tempSum -= left;
        //         left++;
        //         v.erase(v.begin());
        //     }
        // }

        // 思路２

        for(int i = (int)sqrt(2*sum); i >=2 ; i--){//i表示序列的数目
            if(i%2 == 0 && (sum%i)*2 == i){
                int left = sum/i-i/2+1;
                int right = sum/i+i/2;
                if(left>0 && right < sum){
                    vector<int> v;
                    while(left <= right){
                        v.push_back(left);
                        left++;
                    }
                    vs.push_back(v);
                }
            }
            if(i%2 == 1 && sum%i == 0){
                int left = sum/i-i/2;
                int right = sum/i+i/2;
                if(left>0 && right < sum){
                    vector<int> v;
                    while(left <= right){
                        v.push_back(left);
                        left++;
                    }
                    vs.push_back(v);
                }
            }
        }
        return vs;
    }
};

int main(){
    vector<vector<int>> vs;
    int sum = 3;
    Solution s;
    vs = s.FindContinuousSequence(sum);
    for(int i = 0; i < vs.size(); i++){
        for(int j = 0; j < vs[i].size(); j++){
            cout << vs[i][j] << ", ";
        }
        cout << endl;
    }
}