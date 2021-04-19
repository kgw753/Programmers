import java.util.ArrayList;
public class p42586 {
    public ArrayList<Integer> solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer = new ArrayList<>();
        int i = 0;
        while(i < progresses.length){
            int day = 0;
            int cnt = 1;
            while(progresses[i] + (speeds[i] * day) < 100) day++;
            i++;
            while(i < progresses.length && progresses[i] + (speeds[i] * day) >= 100){
                i++;
                cnt++;
            }
            answer.add(cnt);
        }
        return answer;
    }
}
