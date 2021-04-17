import java.util.ArrayList;

public class p42840 {
    public static ArrayList<Integer> solution(int[] answers) {
        ArrayList<Integer> answer = new ArrayList<>();
        int[] p1 = {1, 2, 3, 4, 5};
        int[] p2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int[] score = new int[3];
        
        for(int i = 0; i < answers.length; i++){
            if(p1[i % p1.length] == answers[i]){
                score[0]++;
            }
            if(p2[i % p2.length] == answers[i]){
                score[1]++;
            }
            if(p3[i % p3.length] == answers[i]){
                score[2]++;
            }
        }
        int max = 0;
        for(int i = 0; i < 3; i++){
            max = Math.max(max, score[i]);
        }
        for(int i = 0; i < 3; i++){
            if(max == score[i]){
                answer.add(i + 1);
            }
        }

        
        
        return answer;
    }

    public static void main(String[] args){
        ArrayList<Integer> a = solution(new int[]{1, 2, 3, 4, 5});
        ArrayList<Integer> b = solution(new int[]{1, 3, 2, 4, 2});
        
        System.out.println("first");
        for(Integer i : a){
            System.out.println(i);
        }
        System.out.println();
        System.out.println("second");
        for(Integer i : b){
            System.out.println(i);
        }
    }
}
