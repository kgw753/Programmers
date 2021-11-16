#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, M;
int dy[] = {0, -1, -1};
int dx[] = {-1, -1, 0};
void check(int y, int x, vector<vector<int>> &board){
    int mn = 1e9;
    for(int i = 0; i < 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0) return;
        mn = min(mn, board[ny][nx]);
    }
    board[y][x] = mn + 1;
}
int solution(vector<vector<int>> board){
    int mx = 0;
    N = board.size();
    M = board[0].size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 1){
                check(i, j, board);
                mx = max(mx, board[i][j]);
            }
        }
    }
    return mx > 0 ? pow(mx, 2) : 0;
}