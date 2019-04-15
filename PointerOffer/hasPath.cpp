#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
        if(matrix == nullptr || str == nullptr) return false; 
        vector<int> visited(rows*cols, 0);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(hasPathCore(matrix, rows, cols, str, i, j, visited))
                    return true;
            }
        }
        return false;
    }

    bool hasPathCore(char* m, int rows, int cols, char* str, int row, int col, vector<int> &visited){
        if(row < 0 || row >= rows || col < 0 || col >= cols ) 
            return false;
        bool flag = false;
        if(*str == m[row*cols+col] && visited[row*cols+col] == 0){
            visited[row*cols+col] = 1;
            if(*(str+1) == '\0') return true;
            flag =  hasPathCore(m, rows, cols, str+1, row+1, col, visited) ||
            hasPathCore(m, rows, cols, str+1, row-1, col, visited) || 
            hasPathCore(m, rows, cols, str+1, row, col+1, visited) || 
            hasPathCore(m, rows, cols, str+1, row, col-1, visited);
            if(flag == false) visited[row*cols+col] = 0;
        }
        return flag;
    }
};

int main(){
    char m[] = {'a','b','c','e','s','f','c','s','a','d','e','e'};
    char str1[] = {'b','c','c','e','d'};
    char str2[] = {'a','b','c','b'};
    int rows = 3;
    int cols = 4;
    Solution s;
    cout << s.hasPath(m, rows, cols, str1) << endl;
    cout << s.hasPath(m, rows, cols, str2) << endl;
}