import java.math.BigInteger;

public class p62048 {
    public static long solution(int w, int h) {
        long gcd = BigInteger.valueOf(w).gcd(BigInteger.valueOf(h)).longValue();
        long answer = ((long)w * (long)h) - ((((long)w / gcd) + ((long)h / gcd) - (long)1) * gcd);
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution(8, 12));
        System.out.println(solution(6, 9));
    }
}
