#include<bits/stdc++.h>
using namespace std;
#define MAX 504
int MAP[MAX][MAX];
int N, M;
bool visited[MAX][MAX][4];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int go(int y, int x, int dir, int len){
    if(visited[y][x][dir]) return len;
    visited[y][x][dir] = true;

    int nd = (dir + MAP[y][x] + 4) % 4;
    int ny = y + dy[nd];
    int nx = x + dx[nd];

    if(ny < 0) ny = N - 1;
    if(nx < 0) nx = M - 1;
    if(ny == N) ny = 0;
    if(nx == M) nx = 0;

    return go(ny, nx, nd, len + 1);
}
vector<int> solution(vector<string> grid) {
    vector<int> ret;
    N = grid.size();
    M = grid[0].length();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 'L') MAP[i][j] = 1;
            else if(grid[i][j] == 'R') MAP[i][j] = -1;
        }
    }
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
int main(){
    int N;
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    vector<int> res = solution(v);
    for(int r : res) cout << r << " ";
    cout << "\n";
}