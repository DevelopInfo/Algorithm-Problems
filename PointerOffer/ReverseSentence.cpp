#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string s = str;
        int size = str.size();
        if(size <= 1) return s;

        int left = 0, right = size-1;
        for(int i = 0; i <= size; i++){
            if(str[i] == ' ' || str[i] == '\0'){
                right = i-1;
                while(left < right){
                    swap(s[left], s[right]);
                    ++left;
                    --right;
                }
                left = i+1;
            }
        }

        left = 0; right = size-1;
        while(left < right){
            swap(s[left], s[right]);
            ++left;
            --right;
        }

        return s;
    }
};

int main(){
    string str = "I am a  student.";
    Solution s;
    cout << s.ReverseSentence(str) << endl;
}
