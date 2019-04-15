#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> Permutation(string str) {
    vector<string> v;
    if(str.size() == 0)
        return v;
    if(str.size() == 1){
        v.push_back(str);
        return v;
    }
    vector<string> p;
    for(int i = 0; i < str.size(); i++){
        string temp = str;
        p = Permutation(temp.erase(i,1));
        for(int j = 0; j < p.size(); j++){
            p[j] += str[i];
            v.push_back(p[j]);
        }
    }
    return v;
}

int main(){
    vector<string> v = Permutation("ab");
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}