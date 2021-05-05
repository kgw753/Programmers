import java.util.PriorityQueue;

public class p42626 {
    public static int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int s : scoville) pq.add(s);

        while(pq.peek() < K && pq.size() >= 2){
            int min1 = pq.poll();
            int min2 = pq.poll();
            int new_scv = min1 + (min2 * 2);
            answer++;
            pq.add(new_scv);
        }
        if(pq.isEmpty() || pq.peek() < K) answer = -1;
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution(new int[]{1, 2, 3, 9, 10, 12}, 7));
    }
}
