#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int col, row;
vector<string> MAP;
void dfs(int y, int x){
    MAP[y][x] = '0';
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= col || ny >= row || MAP[ny][nx] == '0' || MAP[ny][nx] != MAP[y][x]) continue;
        dfs(y, x);
    }
}
int strokesRequired(vector<string> picture) {
    MAP = picture;
    col = picture.size();
    row = picture[0].size();
    int ret = 0;
    for(int i = 0; i < picture.size(); i++){
        for(int j = 0; j < picture[i].size(); j++){
            if(picture[i][j] == '0') continue;
            dfs(i, j);
            ret++;
        }
    }
    return ret;
}
int main(){
    int N;
    vector<string> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    cout << strokesRequired(v) << "\n";
}