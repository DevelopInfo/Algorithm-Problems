#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //基于冒泡排序的思想
        int size = array.size();
        int i = 0, j = 0;
        for(i = 0; i < size; i++){
            while(array[i]%2 != 0 && i < size)
                i++;
            j = i+1;
            while(array[j]%2 != 1 && j < size)
                j++;
            if(j < size){
                int temp = array[j];
                int k = j;
                while(j > i){
                    array[j] = array[j-1];
                    j--;
                }
                array[i] = temp;
            }else{
                break;   
            }
        }
    }
};

int main(){
    vector<int> array = {1,2,3,4,5,6,7};
    Solution s;
    s.reOrderArray(array);
    for(int i = 0; i < (int)array.size(); i++)
        printf("%d ", array[i]);
}