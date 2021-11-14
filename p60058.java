public class p60058 {
    public static boolean isCorrect(String str){
        int count = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '(') count++;
            else count--;

            if(count < 0) return false;
        }
        return true;
    }

    public static int balanceCheck(String w){
        int count = 0;
        for(int i = 0; i < w.length(); i++){
            if(w.charAt(i) == '(') count++;
            else count--;

            if(count == 0) return i;
        }
        return -1;
    }

    public static String solution(String p) {
        if(p.equals("")) return p;

        String answer = "";
        int idx = balanceCheck(p);
        String u = p.substring(0, idx + 1);
        String v = p.substring(idx + 1);

        if(isCorrect(u)){
            answer = u + solution(v);
        }
        else{
            answer += "(" + solution(v) + ")";
            u = u.substring(1, u.length() - 1);
            String tmp = "";

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
