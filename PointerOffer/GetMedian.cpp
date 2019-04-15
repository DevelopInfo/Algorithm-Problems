#include <iostream>
#include <queue>
using namespace std;

class Solution {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    // 用一个大顶堆和一个小顶堆，维持大顶堆的数都小于等于小顶堆的数，
    // 且两者的个数相等或差1。平均数就在两个堆顶的数之中。
    void Insert(int num)
    {
        if(minHeap.empty() || minHeap.top() <= num){
            minHeap.push(num);
        }else{
            maxHeap.push(num);
        }

        if(minHeap.size() == maxHeap.size()+2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size() == minHeap.size()+2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double GetMedian()
    { 
        double median = 0;
        if(minHeap.size() > maxHeap.size())
            median = minHeap.top();
        else if(minHeap.size() < maxHeap.size())
            median = maxHeap.top();
        else
            median = (minHeap.top() + maxHeap.top())/2.0;
        return median;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,5,6,7,8,7,5,4,3};
    Solution s;
    for(int i = 0; i < nums.size(); i++){
        s.Insert(nums[i]);
        cout << s.GetMedian() << ", ";
    }
}