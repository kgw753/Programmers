import java.util.Scanner;
import java.util.Stack;

public class p42883 {
    public static String solution(String number, int k) {
        StringBuilder sb = new StringBuilder();
        Stack<Character> st = new Stack<>();

        for(int i = 0; i < number.length(); i++){
            while(!st.isEmpty() && st.peek() < number.charAt(i) && i - st.size() < k){
                st.pop();
            }
            st.push(number.charAt(i));
        }
        for(int i = 0; i < number.length() - k; i++){
            sb.append(st.get(i));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String number = sc.nextLine();
        int k = sc.nextInt();
        System.out.println(solution(number, k));
    }
}
