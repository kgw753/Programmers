import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Solution {
    public int solution(String s) {
        StringBuffer sb = new StringBuffer(s);
        int answer = 0;

        for(int i = 0; i < s.length(); i++){
            if(isParenthesis(sb.toString())) answer++;
            
            sb.append(sb.charAt(0));
            sb.deleteCharAt(0);
        }

        return answer;
    }

    public static boolean isParenthesis(String str){
        Stack<Character> st = new Stack<>();

        for(char c : str.toCharArray()){
            if(c == '(' || c == '[' || c == '{') st.add(c);
            else{
                if(st.isEmpty()) return false;
                else if(isEqual(st.peek(), c)) st.pop();
            }
        }

        return st.isEmpty();
    }

    public static boolean isEqual(char c1, char c2){
        if(c1 == '[' && c2 == ']') return true;
        else if(c1 == '(' && c2 == ')') return true;
        else if(c1 == '{' && c2 == '}') return true;
        else return false;
    }
}