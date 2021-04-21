import java.util.LinkedList;
import java.util.Queue;

public class p42587 {
    public static int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<>();
        int[] importance = new int[9];
        for(int i = 0; i < priorities.length; i++){
            q.add(priorities[i]);
            importance[priorities[i] - 1]++;
        }
        
        for(int i = 8; i > -1 && location > -1; i--){
            while(importance[i] > 0 && location-- > -1){
                if(q.peek() == (i + 1)){
                    importance[i]--;
                    q.poll();
                    answer++;
                }
                else{
                    q.add(q.poll());
                    if(location < 0) location = q.size() - 1;
                }
            }
        }
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution(new int[]{2, 1, 3, 2}, 2));
        System.out.println(solution(new int[]{1, 1, 9, 1, 1, 1}, 0));
    }
}
