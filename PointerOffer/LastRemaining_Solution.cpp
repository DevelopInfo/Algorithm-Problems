#include <iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        // f = (f_1+m)%n

        //非递归写法
        if(n == 0) return -1;
        if(n == 1) return 0;

        int f = 0, f_1 = 0;
        for(int i = 2; i <= n; i++){
            f = (f_1+m)%i;
            f_1 = f;
        }
        return f;
    }
};

int main(){
    Solution s;
    int n = 5, m = 3;
    cout << s.LastRemaining_Solution(n, m) << endl;
}