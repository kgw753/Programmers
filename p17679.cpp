#include<bits/stdc++.h>
using namespace std;
#define MAX 34
int N, M;
queue<pair<int, int>> delPos;
vector<string> MAP;
int dy[] = {0, 1, 1};
int dx[] = {1, 1, 0};
void arrange(){
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] == '.') continue;
            int npos = i + 1;
            while(npos < N && MAP[npos][j] == '.') npos++;
            npos--;
            if(npos != i){
                MAP[npos][j] = MAP[i][j];
                MAP[i][j] = '.';
            }
        }
    }
}
void deleteFour(int y, int x, int &cnt){
    if(MAP[y][x] != '.'){
        cnt++;
        MAP[y][x] = '.';
    }
    for(int i = 0; i < 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(MAP[ny][nx] != '.'){
            cnt++;
            MAP[ny][nx] = '.';
        }
    }
}
bool isFour(char c, int y, int x){
    for(int i = 0; i < 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || MAP[y][x] != MAP[ny][nx]) return false;
    }
    return true;
}
int solution(int n, int m, vector<string> board) {
    N = n, M = m;
    MAP = board;
    int answer = 0;
    bool bomb = true;
    while(bomb){
        bomb = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(MAP[i][j] == '.') continue;
                if(isFour(MAP[i][j], i, j)){
                    delPos.push({i, j});
                    bomb = true;
                }
            }
        }
        if(bomb){
            while(delPos.size()){
                int y = delPos.front().first;
                int x = delPos.front().second;
                delPos.pop();
                deleteFour(y, x, answer);
            }
            arrange();
        }
    }
    return answer;
}