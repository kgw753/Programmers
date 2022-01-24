
class Solution {
    public static int L;
    public static boolean[][] isPalin;
    public int solution(String s){
        L = s.length();
        isPalin = new boolean[L][L];
        
        int answer = 1;
        for(int i = 0; i < L; i++){
            isPalin[i][i] = true;
        }
        
        for(int i = 0; i < L - 1; i++){
            if(s.charAt(i) == s.charAt(i + 1)) {
                isPalin[i][i + 1] = true;
                answer = Math.max(answer, 2);
            }
        }

        for(int size = 2; size < L; size++){
            for(int start = 0; start < L - size ; start++){
                if(isPalin[start + 1][start + size - 1] && s.charAt(start) == s.charAt(start + size)){
                    isPalin[start][start + size] = true;
                    answer = Math.max(answer, size + 1);
                }
            }
        }
        
        return answer;
    }   
}