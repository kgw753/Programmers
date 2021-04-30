public class p60058 {

    public static int check(String str){
        int cnt = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '(') cnt++;
            else cnt--;

            if(cnt == 0) return i;
        }
        return -1;
    }

    public static boolean isCorrect(String str){
        int cnt = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '(') cnt++;
            else cnt--;

            if(cnt < 0) return false;
        }
        return true;
    }

    public static String solution(String p) {
        if(p.equals("")) return p;

        int idx = check(p);
        String u = p.substring(0, idx + 1);
        String v = p.substring(idx + 1);

        String answer = "";

        if(isCorrect(u)){
            answer = u + solution(v);
        }
        else{
            answer += "(" + solution(v) + ")";
            String tmp = "";
            u = u.substring(1, u.length() - 1);
            for(int i = 0; i < u.length(); i++){
                if(u.charAt(i) == ')') tmp += "(";
                else tmp += ")";
            }
            answer += tmp;
        }
        
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution("(()())()"));
        System.out.println(solution(")("));
        System.out.println(solution("()))((()"));
    }
}
