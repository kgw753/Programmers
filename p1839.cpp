#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int MAX = 101;
bool visited[MAX][MAX];

int checkArea(vector<vector<int>> picture, int y, int x, int color, int maxY,
              int maxX) {
  int count = 0;

  queue<pair<int, int>> q;
  q.push({y, x});

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    if (visited[y][x])
      continue;
    visited[y][x] = true;
    count++;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= maxY || nx >= maxX || visited[ny][nx]) {
        continue;
      }
      if (picture[ny][nx] == color) {
        q.push({ny, nx});
      }
    }
  }

  return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
  int numberOfArea = 0;
  int maxSizeOfOneArea = 0;

  fill(&visited[0][0], &visited[0][0] + MAX * MAX, false);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && picture[i][j]) {
        int currArea = checkArea(picture, i, j, picture[i][j], m, n);
        maxSizeOfOneArea = max(maxSizeOfOneArea, currArea);
        numberOfArea++;
      }
    }
  }

  vector<int> answer(2);
  answer[0] = numberOfArea;
  answer[1] = maxSizeOfOneArea;
  return answer;
}