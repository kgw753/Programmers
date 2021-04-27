public class p60057 {
    public static int solution(String s) {
        int answer = s.length();
        
        for(int i = 1; i <= s.length() / 2; i++){
            int len = compare(i, s).length();
            answer = Math.min(answer, len);
        }

        return answer;
    }

    public static String compare(int comp, String s){
        String str = "";
        for(int i = 0; i < s.length() + comp; i += comp){
            String s1 = "";

            if(i + comp < s.length()){
                s1 = s.substring(i, i + comp);
            }
            else if(i < s.length()){
                s1 = s.substring(i, s.length());
            }
            else{
                break;
            }

            int cnt = 1;
            int idx = i + comp;

            while(idx + comp <= s.length() && s1.equals(s.substring(idx, idx + comp))){
                cnt++;
                idx += comp;
                i += comp;
            }

            if(cnt > 1){
                str += (Integer.toString(cnt) + s1);
            }
            else{
                str += s1;
            }
        }
        return str;
    }

    public static void main(String[] args){
        System.out.println(solution("aabbaccc"));
        System.out.println(solution("abcabcdede"));
        System.out.println(solution("xababcdcdababcdcd"));
        
    }
}
