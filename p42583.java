import java.util.LinkedList;
import java.util.Queue;

public class p42583 {
    public static int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> bridge = new LinkedList<>();
        int sec = 0;
        int totalWeight = 0;
        for(int w : truck_weights){
            while(true){
                if(bridge.isEmpty()){
                    bridge.add(w);
                    totalWeight += w;
                    sec++;
                    break;
                }
                
                if(bridge.size() == bridge_length){
                    totalWeight -= bridge.poll();
                }

                if(totalWeight + w <= weight){
                    bridge.add(w);
                    totalWeight += w;
                    sec++;
                    break;
                }
                else{
                    bridge.add(0);
                    sec++;
                }
            }
        }
        return sec + bridge_length;
    }

    public static void main(String[] args){
        System.out.println(solution(2, 10, new int[]{7, 4, 5, 6}));
        System.out.println(solution(100, 100, new int[]{10}));
        System.out.println(solution(100, 100, new int[]{10,10,10,10,10,10,10,10,10,10}));
    }
}
