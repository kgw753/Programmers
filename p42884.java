import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int solution(int[][] routes) {
        Arrays.sort(routes, new Comparator<int[]>(){
            @Override
            public int compare(int[] r1, int[] r2){
                return r1[1] - r2[1];
            }
        });

        int cam = -30001;
        int answer = 0;

        for(int[] route : routes){
            if(route[0] > cam){
                cam = route[1];
                answer++;
            }
        }
        return answer;
    }
}