#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#define MAX 154
int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
vector<vector<int>> visited(MAX, vector<int>(MAX, 1e9));
int minMoves(int n, int startRow, int startCol, int endRow, int endCol) {
    queue<pair<int, int>> q;
    int y, x;
    q.push({startRow, startCol});
    visited[startRow][startCol] = 0;
    while(visited[endRow][endCol] == 1e9){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[ny][nx] > visited[y][x] + 1){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return visited[endRow][endCol];
}

int main(){
    int n, sy, sx, ey, ex;
    cin >> n >> sy >> sx >> ey >> ex;
    cout << minMoves(n, sy, sx, ey, ex) << "\n";
}