#include <stdio.h>

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        
        int k = n;
        if(n < 0)
            k = -n;
        
        double result = 0;
        if(k % 2 == 1)
            result = myPow(x, k/2)*myPow(x, k/2)*x;
        else
            result = myPow(x, k/2)*myPow(x, k/2);
        
        if(n < 0)
            result = 1/result;
        return result;
    }
};

int main(){
    double x = 2;
    int n = -2;
    Solution s;
    printf("%f\n", s.myPow(x, n));
}