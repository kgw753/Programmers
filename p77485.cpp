#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
vector<vector<int>> MAP(104, vector<int>(104, 0));
int rotate(int y1, int x1, int y2, int x2){
    int ret = 1e9;
    vector<vector<int>> tmp(MAP);
    for(int i = x1; i < x2; i++){
        ret = min(ret, tmp[y1][i]);
        MAP[y1][i + 1] = tmp[y1][i];
    } 
    for(int i = y1; i < y2; i++){
        ret = min(ret, tmp[i][x2]);
        MAP[i + 1][x2] = tmp[i][x2];
    }
    for(int i = x2; i > x1; i--){
        ret = min(ret, tmp[y2][i]);
        MAP[y2][i - 1] = tmp[y2][i];
    }
    for(int i = y2; i > y1; i--){
        ret = min(ret, tmp[i][x1]);
        MAP[i - 1][x1] = tmp[i][x1];
    }
    return ret;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            MAP[i][j] = (j + 1) + (i * columns);
        }
    }
    for(int i = 0; i < queries.size(); i++){
        int x1 = queries[i][0] - 1, y1 = queries[i][1] - 1;
        int x2 = queries[i][2] - 1, y2 = queries[i][3] - 1;
        answer.push_back(rotate(x1, y1, x2, y2));
    }
    return answer;
}