class Solution {
    public static int L, answer;
    public static boolean[] visited;
    public int solution(int k, int[][] dungeons) {
        L = dungeons.length;
        visited = new boolean[L];
        answer = 0;

        for(int i = 0; i < L; i++){
            visited[i] = true;
            dfs(k, dungeons, i, 1);
            visited[i] = false;
        }
        
        return answer;
    }

    public static void dfs(int k, int[][] dungeons, int idx, int depth){
        if(k < dungeons[idx][0]) return;
        answer = Math.max(answer, depth);

        for(int i = 0; i < L; i++){
            if(visited[i]) continue;

            visited[i] = true;
            dfs(k - dungeons[idx][1], dungeons, i, depth + 1);
            visited[i] = false;
        }
    }
}