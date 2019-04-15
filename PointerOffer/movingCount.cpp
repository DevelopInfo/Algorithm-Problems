#include <iostream>
using namespace std;

class Solution {
public:
    // 思路有问题

    // int movingCount(int threshold, int rows, int cols)
    // {
    //     if(rows <= 0 || cols <= 0 || threshold < 0)
    //         return 0;
    //     int rowSum = 0;
    //     int colSum = 0;
    //     //找规律
    //     //从下往上
    //     colSum = returnSum(cols-1);
    //     int i;
    //     for(i = rows-1; i >= 0; i--){
    //         rowSum = bitSum(i);
    //         if(colSum+rowSum <= threshold){
    //             int h = rows-1-i;
    //             int s = rows*cols;
    //             if(h > cols){
    //                 return s-(h+h-cols)*cols/2;
    //             }else{
    //                 return s-(h+1)*h/2;
    //             }
    //         }                
    //     }
    //     //从右往左
    //     rowSum = 0;
    //     for(i = cols-1; i >= 0; i--){
    //         colSum = bitSum(i);
    //         if(colSum+rowSum <= threshold){
    //             int w = i+1;
    //             if(w > rows){
    //                 return (w+w-rows)*rows/2;
    //             }else{
    //                 return (w+1)*w/2;
    //             }
    //         }
    //     }
    //     return 0;
    // }

    int movingCount(int threshold, int rows, int cols){

        if(rows <= 0 || cols <= 0 || threshold < 0)
            return 0;

        bool visited[rows * cols];
        for(int i = 0; i < rows*cols; i++){
            visited[i] = false;
        }

        return movingStep(visited, 0, 0, threshold, rows, cols);
    }

    int movingStep(bool *visited, int row, int col, int threshold, int rows, int cols){
        if(visited[row*cols+col] == true || bitSum(row) + bitSum(col) > threshold ||
        row < 0 || row >= rows || col < 0 || col >= cols)
            return 0;
        visited[row*cols+col] = true;
        return movingStep(visited, row-1, col, threshold, rows, cols) + 
            movingStep(visited, row+1, col, threshold, rows, cols) + 
            movingStep(visited, row, col-1, threshold, rows, cols) +
            movingStep(visited, row, col+1, threshold, rows, cols) + 1;
    }


    int bitSum(int num){
        if(num < 0) return 0;
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};

int main(){
    int threshold = 18;
    int rows = 10;
    int cols = 10;

    Solution s;
    cout << s.movingCount(threshold, rows, cols) << endl;
}