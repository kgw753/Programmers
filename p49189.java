import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class p49189 {
    public static int[] dist;
    public static List<Integer> map[];
    public static PriorityQueue<int[]> pq;
    public int solution(int n, int[][] edge) {
        map = new List[n + 1];
        for(int i = 0; i <= n; i++){
            map[i] = new ArrayList<>();
        }
        for(int[] node : edge){
            map[node[0]].add(node[1]);
            map[node[1]].add(node[0]);
        }

        dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        pq = new PriorityQueue<>(new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                return a[0] - b[0];
            }
        });

        pq.add(new int[]{0, 1});
        dist[1] = 0;

        int mx = 0;
        while(!pq.isEmpty()){
            int here = pq.peek()[1];
            int here_dist = pq.peek()[0];
            pq.poll();

            if(dist[here] != here_dist) continue;
            for(int there : map[here]){
                int there_dist = dist[there];
                if(there_dist > here_dist + 1){
                    dist[there] = here_dist + 1;
                    pq.add(new int[]{dist[there], there});
                    mx = Math.max(mx, dist[there]);
                }

            }
        }

        int cnt = 0;
        for(int d : dist){
            if(d == mx) cnt++;
        }
        System.out.println(mx);
        return cnt;
    }
}