#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false;

        //查找最大最小值，并检验除0之外是否有重复元素
        int min = 14, max = -1;
        map<int, int> m_repeat;
        m_repeat.insert(pair<int, int>(0, -5));
        int count_0 = 0;
        for(int i = 0; i < 5; i++){
            if(m_repeat.find(numbers[i]) != m_repeat.end()){
                m_repeat[numbers[i]]++;
            }else{
                m_repeat.insert(pair<int, int>(numbers[i], 0));
            }
            
            if(m_repeat[numbers[i]] > 0) return false;
            if(numbers[i] == 0) count_0++;
            if(min > numbers[i] && numbers[i] != 0) min = numbers[i];
            if(max < numbers[i]) max = numbers[i];
        }

        if(max - min < 5){
            return true;
        }else{
            return false;
        }

    }
};