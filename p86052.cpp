#include<bits/stdc++.h>
using namespace std;
#define MAX 504
int N, M;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int MAP[MAX][MAX];
bool visited[MAX][MAX][4];
int getNPos(int pos, int mx){
    if(pos == mx) return 0;
    else if(pos < 0) return mx - 1;
    else return pos;
}
int go(int y, int x, int dir, int len){
    if(visited[y][x][dir]) return len;
    visited[y][x][dir] = true;
    int nd = (dir + MAP[y][x] + 4) % 4;
    int ny = getNPos(y + dy[nd], N);
    int nx = getNPos(x + dx[nd], M);
    return go(ny, nx, nd, len + 1);
}
void setMap(vector<string> grid){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 'L') MAP[i][j] = 1;
            else if(grid[i][j] == 'R') MAP[i][j] = -1;
            else MAP[i][j] = 0;
        }
    }
}
vector<int> solution(vector<string> grid){
    vector<int> ret;
    N = grid.size();
    M = grid[0].size();
    setMap(grid);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 4; k++){
                int len = go(i, j, k, 0);
                if(len) ret.push_back(len);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}