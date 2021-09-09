#include <bits/stdc++.h>
using namespace std;
#define MAX 104
vector<vector<int>> MAP;
int visited[MAX][MAX];
int N, M;
int row, col;
int dx[4], dy[4];
int bfs(int y, int x){
    queue<pair<int, int>> q;
    int size = 1;
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()){
        x = q.front().second;
        y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= col || ny >= row || visited[ny][nx] || MAP[ny][nx] != MAP[y][x]) continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
            size++;
        }
    }
    return size;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visited, 0, sizeof(visited));
    MAP = picture;
    dx[0] = 1, dx[1] = 0, dx[2] = -1, dx[3] = 0;
    dy[0] = 0, dy[1] = 1, dy[2] = 0, dy[3] = -1;
    row = m, col = n;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(MAP[i][j] == 0 || visited[i][j]) continue;
            number_of_area++;
            int s = bfs(i, j);
            max_size_of_one_area = max(max_size_of_one_area, s);
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main(){
    cin >> N >> M;
    vector<vector<int>> MAP(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
    vector<int> v = solution(N, M, MAP);
    for(int i : v) cout << i << " ";
    cout << "\n";
}