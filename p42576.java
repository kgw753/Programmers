import java.util.PriorityQueue;
public class p42576 {
        public static String solution(String[] participant, String[] completion) {
            String answer = "";
            PriorityQueue<String> pq = new PriorityQueue<>();
            PriorityQueue<String> pq2 = new PriorityQueue<>();

            for(String str : participant){
                pq.offer(str);
            }
            for(String str : completion){
                pq2.offer(str);
            }

            while(true){
                if(!pq.peek().equals(pq2.poll())){
                    answer = pq.poll();
                    break;
                }
                pq.poll();
            }

            return answer;
        }

    public static void main(String[] args){
        String ans = solution(new String[]{"leo", "kiki", "eden"},
                                     new String[]{"eden", "kiki"});
        System.out.println(ans);

        ans = solution(new String[]{"marina", "josipa", "nikola", "vinko", "filipa"},
                        new String[]{"josipa", "filipa", "marina", "nikola"});
        System.out.println(ans);
    }
}
