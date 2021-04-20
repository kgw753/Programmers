import java.util.Scanner;

public class p12899 {
    public static String solution(int n) {
        StringBuilder sb = new StringBuilder();
        int[] nums = {4, 1, 2};
        while(n > 0) {
            sb.append(nums[n % 3]);
            n = (n - 1) / 3;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(solution(n));
    }
}
