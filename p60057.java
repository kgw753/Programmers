public class p60057 {
    public static int solution(String s) {
        int answer = s.length();
        
        for(int i = 1; i < s.length() / 2; i++){
            int len = compare(i, s).length();
            answer = Math.min(answer, len);
            System.out.println();
            System.out.println(compare(i, s));
        }

        return answer;
    }

    public static String compare(int comp, String s){
        String str = "";
        for(int i = 0; i < s.length() - comp; i++){
            String s1 = s.substring(i, i + comp);
            int cnt = 1;
            int idx = i + comp;
            while(idx + comp <= s.length() && s1.equals(s.substring(idx, idx + comp))){
                cnt++;
                idx += comp;
            }

            if(cnt > 1){
                i += (cnt - 1);
                str += (Integer.toString(cnt) + s1);
            }
            else{
                str += s.charAt(i);
                if(i + comp >= s.length()){
                    str += s.substring(i + 1, s.length());
                }

            }
        }
        return str;
    }

    public static void main(String[] args){
        System.out.println(solution("aabbaccc"));
        System.out.println(solution("abcabcabcabcdededededede"));
        
    }
}
