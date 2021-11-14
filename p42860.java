public class p42860 {
    public static int solution(String name) {
        char start = 'A';
        int answer = 0;
        System.out.println();
        for(int i = 0; i < name.length(); i++){
            char now = name.charAt(i);
            answer += Math.min(now - start, 'Z' - now + 1);

            int next = i + 1;
            while(next < name.length() && name.charAt(next) != 'A'){
                next++;
            }
            answer++;
        }
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution("JEROEN"));
        System.out.println(solution("JAN"));
        System.out.println(solution("JAZ"));
    }
}
