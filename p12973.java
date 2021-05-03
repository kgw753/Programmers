import java.util.Stack;

public class p12973 {
    public static int solution(String s)
    {
        Stack<Character> st = new Stack<>();
        int answer = 0;

        for(int i = s.length() - 1; i >= 0; i--){
            if(!st.isEmpty() && st.peek() == s.charAt(i)){
                st.pop();
            }
            else{
                st.push(s.charAt(i));
            }
        }
        if(st.isEmpty()){
            answer = 1;
        }
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution("cdcd"));
        System.out.println(solution("baabaa"));
    }
}
