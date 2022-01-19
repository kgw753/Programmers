import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class p49191 {
    public static List<Integer> w[];
    public static List<Integer> l[];
    public int solution(int n, int[][] results) {
        w = new ArrayList[n + 1];
        l = new ArrayList[n + 1];
        int ret = 0;

        for(int i = 0; i <= n; i++){
            w[i] = new ArrayList<>();
            l[i] = new ArrayList<>();
        }

        for(int[] r : results){
            w[r[0]].add(r[1]);
            l[r[1]].add(r[0]);
        }

        for(int i = 0; i < n; i++){
            int winner = bfs(i, w);
            int loser = bfs(i, l);
            if(winner + loser == n - 1) ret++;
        }
        return ret;
    }

    public static int bfs(int k, List<Integer>[] map){
        Queue<Integer> q = new LinkedList<>();
        q.add(k + 1);
        int ret = 0;
        boolean[] visited = new boolean[map.length];
        visited[k + 1] = true;

        while(!q.isEmpty()){
            int here = q.poll();
            for(int there : map[here]){
                if(visited[there]) continue;
                visited[there] = true;
                q.add(there);
                ret++;
            }
        }

        return ret;
    }
}
