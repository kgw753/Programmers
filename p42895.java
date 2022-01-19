public class p42895 {
    public static int ret = -1;
    public int solution(int N, int number) {
        dfs(N, number, 0, 0);
        return ret;
    }

    public static void dfs(int N, int number, int depth, int val){
        if(depth > 8) return;
        if(val == number){
            if(ret == -1) ret = depth;
            else ret = Math.min(ret, depth);
            return;
        }

        int k = N;
        for(int i = 1; i <= 8 - depth; i++){
            dfs(N, number, depth + i, val + k);
            dfs(N, number, depth + i, val - k);
            dfs(N, number, depth + i, val / k);
            dfs(N, number, depth + i, val * k);   
            k = k * 10 + N;
        }
    }
}
