#include<bits/stdc++.h>
using namespace std;
const int N = 5;
int n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct Info{
    int y, x, dist;
};
vector<Info> checkPos(vector<string> MAP){
    vector<Info> ret;
    for(int i = 0; i < MAP.size(); i++){
        for(int j = 0; j < MAP[i].size(); j++){
            if(MAP[i][j] == 'P') ret.push_back({i, j, 0});
        }
    }
    return ret;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int visited[5][5];
    for(int i = 0; i < places.size(); i++){
        int res = 1;
        vector<string> MAP = places[i];
        vector<Info> info = checkPos(MAP);
        for(int j = 0; j < info.size(); j++){
            memset(visited, -1, sizeof(visited));
            queue<Info> q;
            q.push(info[j]);
            while(q.size()){
                Info here = q.front();
                q.pop();
                visited[here.y][here.x] = here.dist;
                if(here.dist != 0 && MAP[here.y][here.x] == 'P') {
                    res = 0;
                    break;
                }
                else if(here.dist == 2) continue;
                for(int k = 0; k < 4; k++){
                    int nx = here.x + dx[k];
                    int ny = here.y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N || MAP[ny][nx] == 'X') continue;
                    if(visited[ny][nx] == -1) q.push({ny, nx, here.dist + 1});
                }
            }
            if(res == 0) break;
        }
        answer.push_back(res);
    }
    return answer;
}