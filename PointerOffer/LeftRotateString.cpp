#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string s = str;
        
        int size = str.size();
        if(size <= 1) return s;

        int rotateNum = n % size;

        int left = 0, right = rotateNum-1;
        while(left < right){
            swap(s[left], s[right]);
            ++left;
            --right;
        }

        left = rotateNum;
        right = size-1;
        while(left < right){
            swap(s[left], s[right]);
            ++left;
            --right;
        }

        left = 0;
        right = size-1;
        while(left < right){
            swap(s[left], s[right]);
            ++left;
            --right;
        }

        return s;
    }
};

int main(){
    string str = "abcXYZdef";
    int n = 30;
    Solution s;
    cout << s.LeftRotateString(str, n) << endl;
}
