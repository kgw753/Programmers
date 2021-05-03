public class p43165 {
    public static int answer = 0;
    public static int max_depth;
    public static void dfs(int depth, int val, int target, int[] numbers){
        if(depth == max_depth){
            if(val == target){
                answer++;
            }
            return;
        }
        dfs(depth + 1, val + numbers[depth], target, numbers);
        dfs(depth + 1, val - numbers[depth], target, numbers);
    }
    public static int solution(int[] numbers, int target) {
        max_depth = numbers.length;
        dfs(0, 0, target, numbers);
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution(new int[]{1, 1, 1, 1, 1}, 3));
    }
}
