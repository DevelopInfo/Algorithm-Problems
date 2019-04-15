#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1) return false;
        for(int i = 0; i < length; i++){
            if(numbers[i] >= length || numbers[i] < 0) return false;//数组元素大小不符合规定
            while(numbers[i] != i){
                if(numbers[numbers[i]] == numbers[i]){
                    *duplication = numbers[i];
                    return true;
                }else{
                    swap(numbers[numbers[i]], numbers[i]);
                }
            }
        }
        return false;
    }
};

int main(){
    int  numbers[] = {2,3,1,0,2,5,3};
    int length = 7;
    int duplication;
    Solution s;
    cout << s.duplicate(numbers, length, &duplication) << endl ;
    cout << duplication << endl;
}