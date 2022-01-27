import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public static int N, M;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[][] visited;
    public int solution(int[][] maps) {
        N = maps.length;
        M = maps[0].length;
        visited = new int[N][M];
        for(int i = 0; i < N; i++){
            Arrays.fill(visited[i], -1);
        }

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        visited[0][0] = 1;

        int y, x, ny, nx;
        while(!q.isEmpty()){
            y = q.peek()[0];
            x = q.peek()[1];
            q.poll();

            for(int i = 0; i < 4; i++){
                ny = y + dy[i];
                nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] != -1) continue;
                if(maps[ny][nx] == 1){
                    q.add(new int[]{ny ,nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
        }

        return visited[N - 1][M - 1];
    }
}