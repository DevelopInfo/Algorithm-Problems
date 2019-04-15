#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
        vector<int> v;
        if(input.size() == 0 || input.size() < k)
            return v;

        int size = input.size();

        // 使用快速排序算法
        quickSort(input, 0, size-1, k);

        for(int i = 0; i < k; ++i){
            v.push_back(input[i]);
        }

        return v;
    }

    void quickSort(vector<int> &input, int left, int right, int k){
        if(left >= right) return;
        int index = partition(input, left, right);
        if(index == k-1) return;
        quickSort(input, left, index-1, k);
        quickSort(input, index+1, right, k);
    }

    int partition(vector<int> &input, int left, int right){
        int temp = input[left];
        int low = left, high = right;
        while(low < high){
            // 注意顺序问题
            //　先从右往左找
            while(low < high && input[high] >= temp){
                high--;
            }
            while(low < high && input[low] <= temp){
                low++;
            }
            swap(input[low], input[high]);
        }
        swap(input[low], input[left]);
        return low;
    }

    vector<int> GetLeastNumbers_Solution_0(vector<int> input, int k) {
        vector<int> v;
        if(input.size() == 0 || input.size() < k)
            return v;
        
        int size = input.size();

        // 使用堆排序算法
        for(int i = size/2-1; i >= 0; --i){//建立小根堆
            adjustMinHeap(input, i, size);
        }

        for(int i = 0; i < k; ++i){
            v.push_back(input[0]);
            swap(input[size-1-i], input[0]);
            adjustMinHeap(input, 0, size-i-1);
        }

        return v;
    }
    
    void adjustMinHeap(vector<int> &input, int index, int len){
        for(int i  = index*2+1; i < len; i = i*2+1){
            int k = i;
            if(i+1 < len && input[i+1] < input[i]){
                k = i+1;
            }
            if(input[i/2] > input[k]){
                swap(input[i/2], input[k]);
                i = k;
            }else{
                break;
            }
        }
    }
};

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main(){
    vector<int> input = {4,6,8,5,9};
    vector<int> input2 = {4,6};
    int k = 5;
    Solution s;
    vector<int> v = s.GetLeastNumbers_Solution(input, k);
    printVector(v);
    v = s.GetLeastNumbers_Solution(input2, k);
    printVector(v);
}