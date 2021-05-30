#include<bits/stdc++.h>
using namespace std;

void rotate1(vector<vector<int>> &numbers){
    int size = numbers.size();
    vector<vector<int>> tmp(size, vector<int>(size, 0));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            tmp[i][j] = numbers[j][size - i - 1];
        }
    }
    numbers = tmp;
}

void rotate2(vector<vector<int>> &numbers){
    int size = numbers.size();
    vector<vector<int>> tmp(size, vector<int>(size, 0));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            tmp[i][j] = numbers[size - j - 1][i];
        }
    }
    numbers = tmp;
}

void print(vector<vector<int>> v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            printf("%3d", v[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int size = 5;
    vector<vector<int>> v(size, vector<int>(size, 0));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            v[i][j] = i * size + j + 1;
        }
    }
    
}