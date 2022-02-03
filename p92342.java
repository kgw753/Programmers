class Solution {

    public static int max_gap;
    public static int[] answer;
    public static int[] lion;
    public int[] solution(int n, int[] info) {
        answer = new int[]{-1};
        lion = new int[11];
        dfs(0, n, info);
        return answer;
    }

    public static void dfs(int depth, int n, int[] info){
        if(depth == n){
            int apeach_score = 0;
            int lion_score = 0;

            for(int i = 0; i <= 10; i++){
                if(info[i] != 0 || lion[i] != 0){
                    if(lion[i] > info[i]){
                        lion_score += (10 - i);
                    }
                    else{
                        apeach_score += (10 - i);
                    }
                }
            }

            if(apeach_score < lion_score){
                if(lion_score - apeach_score >= max_gap){
                    answer = lion.clone();
                    max_gap = lion_score - apeach_score;
                }
            }
            return;
        }

        for(int i = 0; i <= 10 && lion[i] <= info[i]; i++){
            lion[i]++;
            dfs(depth + 1, n, info);
            lion[i]--;
        }
    }
}