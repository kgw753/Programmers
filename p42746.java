import java.util.Arrays;
import java.util.Comparator;

public class p42746 {
    public static String solution(int[] numbers) {
        StringBuilder sb = new StringBuilder();
        String[] str = new String[numbers.length];
        for(int i = 0; i < str.length; i++){
            str[i] = Integer.toString(numbers[i]);
        }
        Arrays.sort(str, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                return (s2 + s1).compareTo(s1 + s2);
            }
        });
        if(str[0].equals("0")){
            return "0";
        }
        for(String s : str){
            sb.append(s);
        }
        return sb.toString();
    }
    public static void main(String[] args){
        System.out.println(solution(new int[]{6, 10, 2}));
        System.out.println(solution(new int[]{3, 30, 34, 5, 9}));
    }
}
