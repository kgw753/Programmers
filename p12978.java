    import java.util.ArrayList;
    import java.util.Arrays;
    import java.util.Comparator;
    import java.util.List;
    import java.util.PriorityQueue;

    class Solution {
        static class Road{
            int destination;
            int distance;
            
            public Road(int destination, int distance){
                this.destination = destination;
                this.distance = distance;
            }
        };

        public static int[] visited;
        public static PriorityQueue<Road> pq;
        public static List<List<Road>> map;

        public int solution(int N, int[][] road, int K) {
            map = new ArrayList<>();
            for(int i = 0; i <= N; i++){
                map.add(new ArrayList<>());
            }

            for(int i = 0; i < road.length; i++){
                map.get(road[i][1]).add(new Road(road[i][0], road[i][2]));
                map.get(road[i][0]).add(new Road(road[i][1], road[i][2]));
            }
            
            pq = new PriorityQueue<>(new Comparator<Road>(){
                @Override
                public int compare(Road r1, Road r2){
                    return r1.distance - r2.distance;
                }
            });
            
            pq.add(new Road(1, 0));
            visited = new int[N + 1];
            Arrays.fill(visited, Integer.MAX_VALUE);
            visited[1] = 0;

            Road here;
            int here_idx, here_dist;

            while(!pq.isEmpty()){
                here = pq.poll();
                here_idx = here.destination;
                here_dist = here.distance;

                if(here_dist != visited[here_idx]) continue;
                
                for(Road there : map.get(here_idx)){
                    int there_idx = there.destination;
                    int there_dist = there.distance;

                    if(visited[there_idx] > there_dist + here_dist){
                        visited[there_idx] = there_dist + here_dist;
                        pq.add(new Road(there_idx, visited[there_idx]));
                    }
                }
            }


            int answer = 0;
            for(int dist : visited){
                if(dist > K) continue;
                answer++;
            }
            return answer;
        }
    }