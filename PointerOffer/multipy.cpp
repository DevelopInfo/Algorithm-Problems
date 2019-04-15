#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        //　方法一

        // vector<int> B;
        // if(A.size() == 0) return B;
        // for(int i = 0; i < A.size(); i++){
        //     int b = 1;
        //     for(int j = 0; j < A.size(); j++){
        //         if(j!= i)
        //             b *= A[j];
        //     }
        //     B.push_back(b);
        // }
        // return B;

        //　方法二

        vector<int> B;
        if(A.size() == 0) return B;
        B.push_back(1);
        //计算下三角连乘
        for(int i = 0; i < A.size()-1; i++){
            B.push_back(B.back()*A[i]);
        }
        int temp = 1;
        //　计算下三角连乘
        for(int i = A.size()-1; i >= 0; i--){
            B[i] *= temp;
            temp *= A[i];
        }

        return B;
    }
};

int main(){
    vector<int> A = {2,3,4,5,6,7,8,9};
    Solution s;
    vector<int> B = s.multiply(A);
    for(vector<int>::iterator it = B.begin(); it < B.end(); it++){
        cout << *it << ", ";
    }

}