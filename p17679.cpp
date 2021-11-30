#include<bits/stdc++.h>
using namespace std;
int N, M;
int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};
queue<pair<int, int>> del;
vector<string> MAP;
void arrange(){
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] == '.') continue;
            int y = i + 1;
            while(y < N && MAP[y][j] == '.') y++;
            y--;
            if(y != i){
                MAP[y][j] = MAP[i][j];
                MAP[i][j] = '.';
            }
        }
    }
}
void deleteFour(int y, int x, int &cnt){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(MAP[ny][nx] != '.') {
            MAP[ny][nx] = '.';
            cnt++;
        }
    }
}
bool isSame(int y, int x){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(MAP[y][x] != MAP[ny][nx]) return false;
    }
    return true;
}
int solution(int m, int n, vector<string> board) {
    N = m, M = n;
    MAP = board;
    int ret = 0;
    while(true){
        for(int i = 0; i < N - 1; i++){
            for(int j = 0; j < M - 1; j++){
                if(MAP[i][j] != '.' && isSame(i, j)){
                    del.push({i, j});
                }
            }
        }
        if(del.empty()) break;
        while(del.size()){
            deleteFour(del.front().first, del.front().second, ret);
            del.pop();
        }
        arrange();
    }
    return ret;
}