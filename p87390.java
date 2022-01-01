public class p87390 {
    public int[] solution(int n, long left, long right) {
        int[] answer = new int[(int)(right - left)];

        int idx = 0;
        for(long i = left; i <= right; i++){
            answer[idx++] = (int)Math.max(i % n, i / n) + 1;
        }

        return answer;
    }
}
