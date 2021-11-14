#include<bits/stdc++.h>
using namespace std;
int count(vector<vector<int>> board){
    int ret = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] > 0) ret++;
        }
    }
    return ret;
}
void go(vector<vector<int>> &board, vector<int> skill){
    int r1, c1, r2, c2, degree;
    r1 = skill[1], c1 = skill[2];
    r2 = skill[3], c2 = skill[4];
    degree = skill[5];
    if(skill[0] == 1) degree *= -1;

    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            board[i][j] += degree;
        }
    }
}
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    for(vector<int> v : skill){
        go(board, v);
    }
    return count(board);
}
int main(){

}